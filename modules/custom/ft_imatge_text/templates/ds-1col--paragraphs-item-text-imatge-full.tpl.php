<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 field_imatge_fons (Array, 16 elements)
field_orientaci_ (Array, 16 elements)
field_title_block (Array, 16 elements)
field_text_par_textimage (Array, 16 elements)
 */

$right = intval($content['field_orientaci_']['#items'][0]['value']);

?>
  <section class="image-square <?php ($right ? print 'right' : print 'left') ?>">
  		<div class="col-md-6 image">
            <div class="background-image-holder">
                <img alt="image" class="background-image" src="<?php print render($content['field_imatge_fons']); ?>">
            </div>
        </div>
        <div class="col-md-6 content"> 
            <h3 class="wow fadeInLeft"><?php print render($content['field_title_block']); ?></h3>
            <div class="mb0 wow fadeInLeft">
                <?php print render($content['field_text_par_textimage']); ?></h3>
            </div>
        </div>
  </section>