<div class="col-md-3 col-sm-6 blogpost">
    <a href="<?php print drupal_get_path_alias('node/' . $node->nid); ?>">
        <?php if(isset($node->field_image['und'][0]['uri'])): ?>
            <?php print theme_image_style(array(
                'style_name' => 'blogpost',
                'path' => $node->field_image['und'][0]['uri'],
                'width' => $node->field_image['und'][0]['width'],
                'height' => $node->field_image['und'][0]['height']
            )); ?>
        <?php endif; ?>
    
        <div class="blog-content">
            <h2><?php print $title; ?></h2>
            <?php print text_summary($body[0]['value'], NULL, 140); ?>
        </div><!-- /.blog-content -->
    </a>
</div><!-- /.col-md-3 -->