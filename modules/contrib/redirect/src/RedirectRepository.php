<?php

namespace Drupal\redirect;

use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Database\Connection;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Language\Language;
use Drupal\redirect\Entity\Redirect;
use Drupal\redirect\Exception\RedirectLoopException;

class RedirectRepository {

  /**
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $manager;

  /**
   * @var \Drupal\Core\Database\Connection
   */
  protected $connection;

  /**
   * @var \Drupal\Core\Config\ImmutableConfig
   */
  protected $config;

  /**
   * An array of found redirect IDs to avoid recursion.
   *
   * @var array
   */
  protected $foundRedirects = [];

  /**
   * Constructs a \Drupal\redirect\EventSubscriber\RedirectRequestSubscriber object.
   *
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $manager
   *   The entity type manager.
   * @param \Drupal\Core\Database\Connection $connection
   *   The database connection.
   */
  public function __construct(EntityTypeManagerInterface $manager, Connection $connection, ConfigFactoryInterface $config_factory) {
    $this->manager = $manager;
    $this->connection = $connection;
    $this->config = $config_factory->get('redirect.settings');
  }

  /**
   * Gets a redirect for given path, query and language.
   *
   * @param string $source_path
   *   The redirect source path.
   * @param array $query
   *   The redirect source path query.
   * @param $language
   *   The language for which is the redirect.
   *
   * @return \Drupal\redirect\Entity\Redirect
   *   The matched redirect entity.
   *
   * @throws \Drupal\redirect\Exception\RedirectLoopException
   */
  public function findMatchingRedirect($source_path, array $query = [], $language = Language::LANGCODE_NOT_SPECIFIED) {
    $source_path = ltrim($source_path, '/');
    $hashes = [Redirect::generateHash($source_path, $query, $language)];
    if ($language != Language::LANGCODE_NOT_SPECIFIED) {
      $hashes[] = Redirect::generateHash($source_path, $query, Language::LANGCODE_NOT_SPECIFIED);
    }

    // Add a hash without the query string if using passthrough querystrings.
    if (!empty($query) && $this->config->get('passthrough_querystring')) {
      $hashes[] = Redirect::generateHash($source_path, [], $language);
      if ($language != Language::LANGCODE_NOT_SPECIFIED) {
        $hashes[] = Redirect::generateHash($source_path, [], Language::LANGCODE_NOT_SPECIFIED);
      }
    }

    // Load redirects by hash. A direct query is used to improve performance.
    $rid = $this->connection->query('SELECT rid FROM {redirect} WHERE hash IN (:hashes[]) ORDER BY LENGTH(redirect_source__query) DESC', [':hashes[]' => $hashes])->fetchField();
    $wildcard_path = FALSE;
    if (empty($rid)) {
      // Check for a wildcard pattern.
      $patterns = $this->connection
        ->query("SELECT rid, language, redirect_source__path AS pattern FROM {redirect} WHERE redirect_source__path LIKE '%*%' ORDER BY LENGTH(redirect_source__query) DESC")
        ->fetchAll();
      $wildcard_matches = [];
      foreach ($patterns as $rule) {
        $pattern = str_replace('/*', '*', $rule->pattern);
        if (fnmatch($pattern, $source_path)) {
          // If the original rule ends in /*, it's a folder redirect and should
          // also match the plain Ã¢â‚¬Â<U+009D>folderÃ¢â‚¬Â<U+009D> without slash.
          if (substr($rule->pattern, -2) == '/*') {
            $expr = '!' . str_replace('/*', '(\/.*)', $rule->pattern) . '!';
            if (!preg_match($expr, $source_path, $matches)) {
              continue;
            }
            $rule->wildcard_value = $matches[1];
          }
          $wildcard_matches[$rule->language] = $rule;
        }
      }
      if (!empty($wildcard_matches)) {
        $wildcard_language = '';
        if (array_key_exists($language, $wildcard_matches)) {
          $wildcard_language = $language;
        }
        elseif (array_key_exists(Language::LANGCODE_NOT_SPECIFIED, $wildcard_matches)) {
          $wildcard_language = Language::LANGCODE_NOT_SPECIFIED;
        }
        if (!empty($wildcard_language)) {
          $rid = $wildcard_matches[$wildcard_language]->rid;
          $pattern = $wildcard_matches[$wildcard_language]->pattern;
          $tr = [
            '*' => '',
          ];
          if (empty($rule->wildcard_value)) {
            $tr = ['/*' => ''] + $tr;
          }
          $raw_pattern = strtr($pattern, $tr);
          $wildcard_path = str_replace($raw_pattern, '', $source_path);
          if(strpos($wildcard_path, '/') === 0){
            $wildcard_path = substr($wildcard_path, 1);
          }
        }
      }
    }

    if (!empty($rid)) {
      // Check if this is a loop.
      if (in_array($rid, $this->foundRedirects)) {
        throw new RedirectLoopException('/' . $source_path, $rid);
      }
      $this->foundRedirects[] = $rid;

      $redirect = $this->load($rid);

      // Find chained redirects.
      if ($recursive = $this->findByRedirect($redirect, $language)) {
        // Reset found redirects.
        $this->foundRedirects = [];
        return $recursive;
      }

      // Reset set redirect URL with wildcard path.
      if (isset($wildcard_path) && strpos($redirect->getRedirect()['uri'], "entity:") === false) {
        $redirect_url = str_replace(' ', '%20', str_replace("internal:", "", str_replace("*", $wildcard_path, $redirect->getRedirect()['uri'])));
        $redirect->setRedirect($redirect_url);
      }
      return $redirect;
    }

    // Reset found redirects.
    $this->foundRedirects = [];
    return NULL;
  }

  /**
   * Helper function to find recursive redirects.
   *
   * @param \Drupal\redirect\Entity\Redirect
   *   The redirect object.
   * @param string $language
   *   The language to use.
   */
  protected function findByRedirect(Redirect $redirect, $language) {
    $uri = $redirect->getRedirectUrl();
    $base_url = \Drupal::request()->getBaseUrl();
    $generated_url = $uri->toString(TRUE);
    $path = ltrim(substr($generated_url->getGeneratedUrl(), strlen($base_url)), '/');
    $query = $uri->getOption('query') ?: [];
    $return_value = $this->findMatchingRedirect($path, $query, $language);
    return $return_value ? $return_value->addCacheableDependency($generated_url) : $return_value;
  }

  /**
   * Finds redirects based on the source path.
   *
   * @param string $source_path
   *   The redirect source path (without the query).
   *
   * @return \Drupal\redirect\Entity\Redirect[]
   *   Array of redirect entities.
   */
  public function findBySourcePath($source_path) {
    $ids = $this->manager->getStorage('redirect')->getQuery()
      ->accessCheck(TRUE)
      ->condition('redirect_source.path', $source_path, 'LIKE')
      ->execute();
    return $this->manager->getStorage('redirect')->loadMultiple($ids);
  }

  /**
   * Finds redirects based on the destination URI.
   *
   * @param string[] $destination_uri
   *   List of destination URIs, for example ['internal:/node/123'].
   *
   * @return \Drupal\redirect\Entity\Redirect[]
   *   Array of redirect entities.
   */
  public function findByDestinationUri(array $destination_uri) {
    $storage = $this->manager->getStorage('redirect');
    $ids = $storage->getQuery()
      ->accessCheck(TRUE)
      ->condition('redirect_redirect.uri', $destination_uri, 'IN')
      ->execute();
    return $storage->loadMultiple($ids);
  }

  /**
   * Load redirect entity by id.
   *
   * @param int $redirect_id
   *   The redirect id.
   *
   * @return \Drupal\redirect\Entity\Redirect
   */
  public function load($redirect_id) {
    return $this->manager->getStorage('redirect')->load($redirect_id);
  }

  /**
   * Loads multiple redirect entities.
   *
   * @param array $redirect_ids
   *   Redirect ids to load.
   *
   * @return \Drupal\redirect\Entity\Redirect[]
   *   List of redirect entities.
   */
  public function loadMultiple(array $redirect_ids = NULL) {
    return $this->manager->getStorage('redirect')->loadMultiple($redirect_ids);
  }
}
