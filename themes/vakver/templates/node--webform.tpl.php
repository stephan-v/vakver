<div class="contact-header" style="background-image: url(<?php print file_create_url($field_image[0]['uri']); ?>);">
    <div class="absolute-center">
        <h2><?php print $node->title; ?></h2>
    </div><!-- /.text-overlay -->
</div><!-- /.contact-header -->

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="container">
        <?php print render($title_prefix); ?>
            <?php if (!$page): ?>
                <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
            <?php endif; ?>
        <?php print render($title_suffix); ?>

        <div class="content"<?php print $content_attributes; ?>>
            <div class="row contact-us">
                <div class="col-md-6">
                    <div class="form-wrapper">
                        <?php print render($content['body']); ?>
                        <?php print render($content['webform']); ?>
                    </div><!-- /.form-wrapper -->
                </div><!-- /.col-md-6 -->

                <div class="col-md-6 contact-form-img">
                    <div class="palmtree"></div>
                </div><!-- /.col-md-6 -->
            </div><!-- /.contact-us -->
        </div><!-- /.content -->
    </div><!-- /.container -->
</div><!-- /#node -->
