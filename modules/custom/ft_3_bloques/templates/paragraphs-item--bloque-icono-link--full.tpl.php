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
<a class="linkblock" href="<?php print $content['field_link_block']['#items'][0]['url']; ?>">
	<i class="<?php print $content['field_icono_'][0]['#markup'];?> mb32" aria-hidden="true"></i>
	<h4 class="uppercase  mb16 mb-xs-24"><?php print $content['field_t_tulo_bloque'][0]['#markup'];?><small><?php print $content['field_subt_tulo'][0]['#markup']; ?></small></h4>
	<p class="lead"><?php print $content['field_descripci_n'][0]['#markup']; ?></p></a>
