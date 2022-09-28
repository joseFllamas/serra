<?php

/**
 * @file
 * ft_frase_destacada.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ft_frase_destacada_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|frase_destacada_parallax|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'frase_destacada_parallax';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_texto_frase',
        1 => 'field_imagen_fondo',
      ),
    ),
    'fields' => array(
      'field_texto_frase' => 'ds_content',
      'field_imagen_fondo' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|frase_destacada_parallax|default'] = $ds_layout;

  return $export;
}
