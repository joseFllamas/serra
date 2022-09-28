<?php

/**
 * @file
 * ft_imatge_text.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ft_imatge_text_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|text_imatge|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'text_imatge';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_imatge_fons',
        1 => 'field_orientaci_',
        2 => 'field_title_block',
        3 => 'field_text_par_textimage',
      ),
    ),
    'fields' => array(
      'field_imatge_fons' => 'ds_content',
      'field_orientaci_' => 'ds_content',
      'field_title_block' => 'ds_content',
      'field_text_par_textimage' => 'ds_content',
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
  $export['paragraphs_item|text_imatge|default'] = $ds_layout;

  return $export;
}
