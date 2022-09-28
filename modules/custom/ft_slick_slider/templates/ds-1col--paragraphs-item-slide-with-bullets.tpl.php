<?php

/**
 * @file
 * Display Suite 1 column template.
 */
 // krumo($content);
?>


                    <div class="overlay image-bg" style="position: relative; overflow: hidden;">
                        <div class="background-image-holder">
                            <img alt="image" class="background-image" src="<?php print render($content['field_slide_background']);?>"/>
                            
                        </div>
                        <div class="container v-align-transform">
                            <div class="row text-center">
                                <div class="col-md-10 col-md-offset-1">  
                                    <h2 class="mb-xs-16">
                                        <?php print render($content['field_slide_title']);?>

                                    </h2>
                                    <p class="lead mb40">
                                        <?php print render($content['field_slide_body']);?>
                                    </p>
                                    <a class="btn btn-lg btn-filled" href="<?php print $content['field_slide_link']['#items'][0]['url'];?>">
                                       <?php print $content['field_slide_link']['#items'][0]['title'];?>
                                    </a>
                                    
                                </div>
                            </div>
                        </div>  
                        
                    </div> 


<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>


  <?php //print $ds_content; ?>

