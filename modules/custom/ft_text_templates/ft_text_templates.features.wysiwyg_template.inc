<?php

/**
 * @file
 * ft_text_templates.features.wysiwyg_template.inc
 */

/**
 * Implements hook_wysiwyg_template_default_templates().
 */
function ft_text_templates_wysiwyg_template_default_templates() {
  $templates = array();
  $templates['imagen_y_texto'] = array(
    'title' => 'imagen y texto',
    'description' => '',
    'weight' => 0,
    'fid' => 11210,
    'body' => '<section class="image-edge">
<div class="col-md-5 col-sm-4 "><img alt="Screenshot" class="mb-xs-24 p48 pt0" src="/sites/default/files/bootstrap/logoweb.jpg" /></div>

<div class="col-md-7 pt32 col-sm-8">
<h5 class="italic mb0 ">Mini titol</h5>

<h1 class="mb40 mb-xs-16 italic">Vine a veure les nostres<br>
<span class=""> instal·lacions</span></h1>

<p class="lead mb40">Text descriptiu.</p>
<a class="btn-agility" href="https://www.agilitybarcelona.com"><span><span class="btn-content">Enllaç</span></span></a></div>
</section>
',
    'format' => 'full_html',
    'name' => 'imagen_y_texto',
    'content_types' => array(),
  );
  $templates['text_i_xifres'] = array(
    'title' => 'Text i Xifres',
    'description' => '',
    'weight' => 0,
    'fid' => 11213,
    'body' => '<section class="bg-secondary"><div class="container"><div class="row v-align-children"><div class="col-sm-6 col-md-5"><h2 class="uppercase ">No trobaràs un lloc millor</h2><hr /><p>Adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.</p></div><div class="col-sm-6 col-md-offset-1 p0"><div class="col-sm-6 text-center"><div class="feature bordered mb30"><h1 class="large uppercase">300</h1><h5 class="uppercase">m2 de terreny</h5></div></div><div class="col-sm-6 text-center"><div class="feature bordered mb30"><h1 class="large">12h</h1><h5 class="uppercase">Horari flexible 10:00 - 22:00</h5></div></div><div class="col-sm-6 text-center"><div class="feature bordered mb30"><h1 class="large">30</h1><h5 class="uppercase">Obstacles disponibles</h5></div></div><div class="col-sm-6 text-center"><div class="feature bordered mb30"><h1 class="large">4</h1><h5 class="uppercase">Zones independents per circuits</h5></div></div></div></div></div></section>',
    'format' => 'full_html',
    'name' => 'text_i_xifres',
    'content_types' => array(),
  );
  return $templates;
}
