<?php

/**
 * @file
 * ft_carousel_logos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_carousel_logos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function ft_carousel_logos_paragraphs_info() {
  $items = array(
    'carousel_logos' => array(
      'name' => 'Carousel logos',
      'bundle' => 'carousel_logos',
      'locked' => '1',
    ),
    'logo' => array(
      'name' => 'Logo',
      'bundle' => 'logo',
      'locked' => '1',
    ),
  );
  return $items;
}
