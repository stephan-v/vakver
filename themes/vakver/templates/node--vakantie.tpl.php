<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
        <?php if (!$page): ?>
            <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <?php endif; ?>
    <?php print render($title_suffix); ?>
    
    <div class="vacation-header">
        <h1 class="absolute-center"><?php print $title; ?></h1>
    </div><!-- /.vacation-header -->

    <div class="content"<?php print $content_attributes; ?>>
        <div class="container">
            <div class="row">
                <div class="col-md-9">
                    <div class="travel-information row text-center">
                        <div class="col-md-3">
                            <p>Land</p>
                            <?php print $field_country[0]['value']; ?>
                        </div><!-- /.col-md-3 -->

                        <div class="col-md-3">
                            <p>Regio</p>
                            <?php print $field_region[0]['value']; ?>
                        </div><!-- /.col-md-3 -->

                        <div class="col-md-3">
                            <p>Stad</p>
                            <?php print $field_city[0]['value']; ?>
                        </div><!-- /.col-md-3 -->

                        <div class="col-md-3">
                            <p>Vervoer</p>
                        </div><!-- /.col-md-3 -->
                    </div><!-- travel-information -->

                    <div class="vacation">
                        <?php
                            print render($content);
                        ?>
                    </div><!-- /.vacation -->
                </div><!-- /.col-md-9 -->

                <div class="col-md-3">
                    <a href="<?php print $field_url[0]['url']; ?>" class="call-to-action">
                        <div class="inner">Reis boeken<i class="fa fa-plane fa-lg" aria-hidden="true"></i></div><!-- /.inner -->
                        <div class="circle"><i class="fa fa-arrow-right fa-lg" aria-hidden="true"></i></div><!-- /.circle -->
                    </a><!-- /.call-to-action -->

                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Voluptatum, nostrum explicabo placeat possimus tempore aut dolorem! Vero ducimus rem, delectus laboriosam quos suscipit, voluptate dolores, sapiente magnam architecto eveniet fugit!</p>
                </div><!-- /.col-md-3 -->
            </div><!-- /.row -->
        </div><!-- /.container -->
    </div><!-- /.content -->
</div><!-- /#node -->
