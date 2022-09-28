<?php

/**
 * @file
 * ft_slick_slider.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ft_slick_slider_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|slide_with_bullets|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'slide_with_bullets';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slide_background',
        1 => 'field_slide_title',
        2 => 'field_slide_body',
        3 => 'field_slide_link',
      ),
    ),
    'fields' => array(
      'field_slide_background' => 'ds_content',
      'field_slide_title' => 'ds_content',
      'field_slide_body' => 'ds_content',
      'field_slide_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|slide_with_bullets|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'paragraphs_item|slider|default';
  $ds_layout->entity_type = 'paragraphs_item';
  $ds_layout->bundle = 'slider';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slides',
      ),
    ),
    'fields' => array(
      'field_slides' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['paragraphs_item|slider|default'] = $ds_layout;

  return $export;
}
