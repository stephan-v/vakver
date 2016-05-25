<div class="col-md-3 col-sm-6">
    <?php if(isset($node->field_logo['und'][0]['uri'])): ?>
        <a href="<?php print drupal_get_path_alias('node/' . $node->nid); ?>">
            <?php print theme_image_style(array(
                'style_name' => 'large',
                'path' => $node->field_logo['und'][0]['uri'],
                'width' => $node->field_logo['und'][0]['width'],
                'height' => $node->field_logo['und'][0]['height'],
                'attributes' => array('class' => 'absolute-center')
            )); ?>
        </a>
    <?php endif; ?>
</div><!-- /.col-md-3 -->