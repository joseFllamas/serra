<?php

/**
 * @file
 * ft_text_ckeditor.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function ft_text_ckeditor_paragraphs_info() {
  $items = array(
    'ckeditor_text' => array(
      'name' => 'Ckeditor Text',
      'bundle' => 'ckeditor_text',
      'label' => 'Ckeditor Text',
      'description' => '',
      'locked' => '1',
    ),
  );
  return $items;
}
