<?php

/**
 * @file
 * ft_3_bloques.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function ft_3_bloques_paragraphs_info() {
  $items = array(
    'bloque_icono_link' => array(
      'name' => 'Bloque icono + link',
      'bundle' => 'bloque_icono_link',
      'locked' => '1',
    ),
    'tres_bloques_' => array(
      'name' => 'Tres Bloques',
      'bundle' => 'tres_bloques_',
      'locked' => '1',
    ),
  );
  return $items;
}
