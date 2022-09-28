<?php

/**
 * @file
 * ft_slick_slider.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ft_slick_slider_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-slide_with_bullets-field_slide_background'.
  $field_instances['paragraphs_item-slide_with_bullets-field_slide_background'] = array(
    'bundle' => 'slide_with_bullets',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_url_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
          'url_type' => '',
        ),
        'type' => 'image_url',
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
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_slide_background',
    'label' => 'Slide background',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-slide_with_bullets-field_slide_body'.
  $field_instances['paragraphs_item-slide_with_bullets-field_slide_body'] = array(
    'bundle' => 'slide_with_bullets',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_slide_body',
    'label' => 'Slide body',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
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
  // 'paragraphs_item-slide_with_bullets-field_slide_link'.
  $field_instances['paragraphs_item-slide_with_bullets-field_slide_link'] = array(
    'bundle' => 'slide_with_bullets',
    'default_value' => array(
      0 => array(
        'title' => 'See more',
        'url' => '#',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'custom_title' => '',
        ),
        'type' => 'link_default',
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
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_slide_link',
    'label' => 'Slide link',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 0,
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
      'enable_tokens' => 1,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'required',
      'title_allowed_values' => '',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-slide_with_bullets-field_slide_title'.
  $field_instances['paragraphs_item-slide_with_bullets-field_slide_title'] = array(
    'bundle' => 'slide_with_bullets',
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
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_slide_title',
    'label' => 'Slide title',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
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

  // Exported field_instance: 'paragraphs_item-slider-field_container'.
  $field_instances['paragraphs_item-slider-field_container'] = array(
    'bundle' => 'slider',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_container',
    'label' => 'full-width',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'paragraphs_item-slider-field_height'.
  $field_instances['paragraphs_item-slider-field_height'] = array(
    'bundle' => 'slider',
    'default_value' => array(
      0 => array(
        'value' => 50,
      ),
    ),
    'deleted' => 0,
    'description' => 'Choose the height of this slide, considering the window/fullscreen height as 100%',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_height',
    'label' => 'Height',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-slider-field_slides'.
  $field_instances['paragraphs_item-slider-field_slides'] = array(
    'bundle' => 'slider',
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
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_slides',
    'label' => 'Slides',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'bloque_icono_link' => -1,
        'carousel_logos' => -1,
        'frase_destacada_parallax' => -1,
        'icono_link' => -1,
        'logo' => -1,
        'slide_with_bullets' => 'slide_with_bullets',
        'slider' => -1,
        'text_imatge' => -1,
        'texto_4_bloques' => -1,
        'tres_bloques_' => -1,
      ),
      'bundle_weights' => array(
        'bloque_icono_link' => 2,
        'carousel_logos' => 3,
        'frase_destacada_parallax' => 4,
        'icono_link' => 5,
        'logo' => 6,
        'slide_with_bullets' => 8,
        'slider' => 7,
        'text_imatge' => 10,
        'texto_4_bloques' => 9,
        'tres_bloques_' => 11,
      ),
      'default_edit_mode' => 'closed',
      'default_edit_mode_override' => 1,
      'title' => 'Slide',
      'title_multiple' => 'Slide',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Choose the height of this slide, considering the window/fullscreen height as 100%');
  t('Height');
  t('Slide background');
  t('Slide body');
  t('Slide link');
  t('Slide title');
  t('Slides');
  t('full-width');

  return $field_instances;
}
