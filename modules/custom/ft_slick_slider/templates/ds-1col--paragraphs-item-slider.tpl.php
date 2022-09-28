<?php

/**
 * @file
 * Display Suite 1 column template.
 */
$fullwidth = intval($content['field_container']['#items'][0]['value']);
$height = $content['field_height']['#items'][0]['value']."vh";

?>
	
<section class=" pt0 pb0 <?php if(!$fullwidth) print 'container'; ?>" >
    <div class="slider slider-paragraph" style="height: <?php print $height;?>">

		  <?php if (isset($title_suffix['contextual_links'])): ?>
		  <?php print render($title_suffix['contextual_links']); ?>
		  <?php endif; ?>

		  <?php print $ds_content; ?>
	</div>
</section>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>

