<?php

/**
 * @file
 * ft_slick_slider.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_slick_slider_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function ft_slick_slider_paragraphs_info() {
  $items = array(
    'slide_with_bullets' => array(
      'name' => 'Sub - Slide',
      'bundle' => 'slide_with_bullets',
      'label' => 'Slide',
      'description' => '',
      'locked' => '1',
    ),
    'slider' => array(
      'name' => 'Slick Slider',
      'bundle' => 'slider',
      'label' => 'Slick Slider',
      'description' => 'Slider con slick.js',
      'locked' => '1',
    ),
  );
  return $items;
}
