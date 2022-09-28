<?php

/**
 * @file
 * ft_imatge_text.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_imatge_text_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ft_imatge_text_image_default_styles() {
  $styles = array();

  // Exported image style: mini_podiums.
  $styles['mini_podiums'] = array(
    'label' => 'mini_podiums',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 110,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: paragraph_imgtext.
  $styles['paragraph_imgtext'] = array(
    'label' => 'paragraph_imgtext',
    'effects' => array(
      28 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 800,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_paragraphs_info().
 */
function ft_imatge_text_paragraphs_info() {
  $items = array(
    'text_imatge' => array(
      'name' => 'Text + Imatge',
      'bundle' => 'text_imatge',
      'locked' => '1',
    ),
  );
  return $items;
}
