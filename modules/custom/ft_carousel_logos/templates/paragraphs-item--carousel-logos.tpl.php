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
 */
?>
 <section class="bg-secondary">
    <div class="container">
        <div class="row">
            <div class="col-sm-12 text-center">
                <h4 class="uppercase mb64 mb-xs-40"><?php print $content['field_t_tol']['#items'][0]['value']; ?></h4>
            </div>
        </div>
        
        <div class="row">
            <div class="logo-carousel">
                <ul class="slides">
				   <?php
				   	foreach ($content['field_logos']['#items'] as $key => $value) : ?>
				   		<li>
				   			<?php print drupal_render($content['field_logos'][$key]); ?>
				   		</li>
				   	<?php endforeach;  ?>
			     </ul>
            </div>
            
        </div>
        
    </div>
		    
</section>
