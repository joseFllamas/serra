<?php

/**
 * @file
 * ft_text_ckeditor.features.wysiwyg_template.inc
 */

/**
 * Implements hook_wysiwyg_template_default_templates().
 */
function ft_text_ckeditor_wysiwyg_template_default_templates() {
  $templates = array();
  $templates['title_text_button'] = array(
    'title' => 'Title + text + button',
    'description' => 'Title + text + button',
    'weight' => 0,
    'fid' => 1554,
    'body' => '<h2 class="uppercase color-primary">
                                Sample title
                            </h2>
                            <hr>
                                <p>
                                    Adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
                                </p>
                                <a class="btn btn-lg btn-filled" href="#">
                                        What\'s Shafe?
                                    </a>
                            </hr>',
    'format' => 'full_html',
    'name' => 'title_text_button',
    'content_types' => array(),
  );
  return $templates;
}
