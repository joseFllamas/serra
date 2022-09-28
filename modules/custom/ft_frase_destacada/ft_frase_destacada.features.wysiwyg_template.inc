<?php

/**
 * @file
 * ft_frase_destacada.features.wysiwyg_template.inc
 */

/**
 * Implements hook_wysiwyg_template_default_templates().
 */
function ft_frase_destacada_wysiwyg_template_default_templates() {
  $templates = array();
  $templates['frase_destacada'] = array(
    'title' => 'Frase destacada',
    'description' => '',
    'weight' => 0,
    'fid' => 11211,
    'body' => '<div class="feature feature-1 boxed text-center"><h2 class="mb16">Viu una experiència inoblidable</h2><p class="lead mb64">Demana informació ara sense compromis!&nbsp;&nbsp;&nbsp; <a class="btn-agility" href="https://www.agilitybarcelona.com"> <span> <span class="btn-content"><i aria-hidden="true" class="fas fa-envelope"></i> Contacte</span> </span> </a></p></div>',
    'format' => 'full_html',
    'name' => 'frase_destacada',
    'content_types' => array(),
  );
  return $templates;
}
