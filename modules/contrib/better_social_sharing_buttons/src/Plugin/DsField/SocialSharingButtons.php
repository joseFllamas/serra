<?php

namespace Drupal\better_social_sharing_buttons\Plugin\DsField;

use Drupal\ds\Plugin\DsField\DsFieldBase;
use Drupal\Core\Url;

/**
 * Class SocialSharingButtons.
 *
 * @package Drupal\better_social_sharing_buttons\Plugin\DsField
 *
 * @DsField(
 *   id = "better_social_sharing_buttons",
 *   title = @Translation("Better Social Sharing Buttons field"),
 *   entity_type = "node",
 *   provider = "better_social_sharing_buttons",
 *   ui_limit = {"*|*"}
 * )
 */
class SocialSharingButtons extends DsFieldBase {

  /**
   * {@inheritdoc}
   */
  public function build() {
    $items = [];
    global $base_url;
    $entity = $this->entity();

    $config = \Drupal::config('better_social_sharing_buttons.settings');

    $items['page_url'] = Url::fromRoute('<current>', [], ['absolute' => TRUE]);
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
