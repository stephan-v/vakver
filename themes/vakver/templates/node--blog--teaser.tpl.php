<div class="col-md-3 col-sm-6 blogpost">
    <?php if(isset($node->field_image['und'][0]['uri'])): ?>
        <a href="<?php print drupal_get_path_alias('node/' . $node->nid); ?>">
            <?php print theme_image_style(array(
                'style_name' => 'large',
                'path' => $node->field_image['und'][0]['uri'],
                'width' => $node->field_image['und'][0]['width'],
                'height' => $node->field_image['und'][0]['height']
            )); ?>
        
            <div class="blog-content">
                <h2><?php print $title; ?></h2>
                <?php print text_summary($body[0]['value'], NULL, 180); ?>
            </div><!-- /.blog-content -->
        </a>
    <?php endif; ?>
</div><!-- /.col-md-3 -->