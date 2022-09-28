<?php

/**
 * @file
 * ft_3_bloques.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ft_3_bloques_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-bloque_icono_link-field_descripci_n'.
  $field_instances['paragraphs_item-bloque_icono_link-field_descripci_n'] = array(
    'bundle' => 'bloque_icono_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_descripci_n',
    'label' => 'Descripción',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-bloque_icono_link-field_icono_'.
  $field_instances['paragraphs_item-bloque_icono_link-field_icono_'] = array(
    'bundle' => 'bloque_icono_link',
    'default_value' => array(
      0 => array(
        'value' => 'fa fa-graduation-cap',
      ),
    ),
    'deleted' => 0,
    'description' => 'Añade un icono de <a href="https://fontawesome.com/icons?d=gallery&m=free" target="_blank">Font awesome</a>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_icono_',
    'label' => 'Icono ',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 40,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-bloque_icono_link-field_link_block'.
  $field_instances['paragraphs_item-bloque_icono_link-field_link_block'] = array(
    'bundle' => 'bloque_icono_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_link_block',
    'label' => 'link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_allowed_values' => '',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-bloque_icono_link-field_subt_tulo'.
  $field_instances['paragraphs_item-bloque_icono_link-field_subt_tulo'] = array(
    'bundle' => 'bloque_icono_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Aparecerá debajo del título',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_subt_tulo',
    'label' => 'Subtítulo',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-bloque_icono_link-field_t_tulo_bloque'.
  $field_instances['paragraphs_item-bloque_icono_link-field_t_tulo_bloque'] = array(
    'bundle' => 'bloque_icono_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_t_tulo_bloque',
    'label' => 'Título bloque',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-tres_bloques_-field_bloques'.
  $field_instances['paragraphs_item-tres_bloques_-field_bloques'] = array(
    'bundle' => 'tres_bloques_',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_bloques',
    'label' => 'Bloques',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'bloque_icono_link' => 'bloque_icono_link',
        'galeria_texto' => -1,
        'texto_imagenes' => -1,
        'tres_bloques_' => -1,
      ),
      'bundle_weights' => array(
        'bloque_icono_link' => 2,
        'galeria_texto' => 3,
        'texto_imagenes' => 4,
        'tres_bloques_' => 5,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Aparecerá debajo del título');
  t('Añade un icono de <a href="https://fontawesome.com/icons?d=gallery&m=free" target="_blank">Font awesome</a>');
  t('Bloques');
  t('Descripción');
  t('Icono ');
  t('Subtítulo');
  t('Título bloque');
  t('link');

  return $field_instances;
}
