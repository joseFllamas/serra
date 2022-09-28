<?php

/**
 * @file
 * ft_frase_destacada.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_frase_destacada_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ft_frase_destacada_image_default_styles() {
  $styles = array();

  // Exported image style: banner_home.
  $styles['banner_home'] = array(
    'label' => 'banner_home',
    'effects' => array(
      11 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1600,
          'height' => 500,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'banner_home',
        ),
        'weight' => 0,
      ),
      17 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'right',
          'ypos' => 'bottom',
          'alpha' => 100,
          'path' => 'public://Jirka_Wasserbauer3.png',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_paragraphs_info().
 */
function ft_frase_destacada_paragraphs_info() {
  $items = array(
    'frase_destacada_parallax' => array(
      'name' => 'Frase destacada - parallax',
      'bundle' => 'frase_destacada_parallax',
      'locked' => '1',
    ),
  );
  return $items;
}
