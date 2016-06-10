<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="content"<?php print $content_attributes; ?>>
        <div class="container">
            <div class="col-md-8 col-md-offset-2">
                <div class="blogpost">
                    <?php if(isset($node->field_image['und'][0]['uri'])): ?>
                        <a href="/<?php print drupal_get_path_alias('node/' . $node->nid); ?>">
                            <?php print theme_image_style(array(
                                'style_name' => 'fullsize',
                                'path' => $node->field_image['und'][0]['uri'],
                                'width' => $node->field_image['und'][0]['width'],
                                'height' => $node->field_image['und'][0]['height']
                            )); ?>
                        </a>
                    <?php endif; ?>

                    <div class="blog-content">
                        <h1><?php print $title; ?></h1>
                        <?php print render($content['body']); ?>
                    </div><!-- /.blog-content -->
                </div><!-- /.blogpost -->
            </div><!-- /.col-md-8 -->
        </div><!-- /.container -->
    </div><!-- /.content -->
</div><!-- /#node -->