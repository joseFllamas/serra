<?php

namespace Drupal\better_social_sharing_buttons\Plugin\DsField;

use Drupal\ds\Plugin\DsField\DsFieldBase;

/**
 * Class SocialSharingButtonsParagraph.
 *
 * @package Drupal\better_social_sharing_buttons\Plugin\DsField
 *
 * @DsField(
 *   id = "better_social_sharing_buttons_paragraph",
 *   title = @Translation("Better Social Sharing Buttons paragraph"),
 *   entity_type = "paragraph",
 *   provider = "better_social_sharing_buttons",
 *   ui_limit = {"*|*"}
 * )
 */
class SocialSharingButtonsParagraph extends DsFieldBase {

  /**
   * {@inheritdoc}
   */
  public function build() {
    $items = [];
    global $base_url;
    $entity = $this->entity();

    $current_path = \Drupal::service('path.current')->getPath();
    $page_url = \Drupal::service('path.alias_manager')->getAliasByPath($current_path);

    $config = \Drupal::config('better_social_sharing_buttons.settings');

    $items['page_url'] = $base_url . $page_url;
    $items['description'] = '';
    $items['title'] = $entity->get('title')->value;
    $items['width'] = $config->get('width') ?: '20px';
    $items['height'] = $config->get('height') ?: '20px';
    $items['radius'] = $config->get('radius') ?: '3px';
    $items['facebook_app_id'] = $config->get('facebook_app_id') ?: '';
    $items['iconset'] = $config->get('iconset') ?: 'social-icons--square';
    $items['services'] = $config->get('services') ?: [
      'facebook' => 'facebook',
      'twitter' => 'twitter',
      'linkedin' => 'linkedin',
      'googleplus' => 'googleplus',
      'email' => 'email',
    ];
    $items['base_url'] = $base_url;

    return [
      '#theme' => 'better_social_sharing_buttons',
      '#items' => $items,
    ];
  }

}
