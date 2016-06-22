<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>  
    <div class="not-found">
        <span class="absolute-center skewed-label">
            <h1><?php print $title; ?></h1>
            <?php print $node->body['und'][0]['value']; ?>
        </span>

        <?php if(isset($node->field_image['und'][0]['uri'])): ?>
            <span class="img-wrapper">
                <?php print theme_image_style(array(
                    'style_name' => 'fullsize',
                    'path' => $node->field_image['und'][0]['uri'],
                    'width' => $node->field_image['und'][0]['width'],
                    'height' => $node->field_image['und'][0]['height'],
                )); ?>
            </span>
        <?php endif; ?>
    </div><!-- /.not-found -->     
</div><!-- /#node -->
