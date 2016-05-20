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
                        <div class="col-md-3 col-xs-6">
                            <i class="fa fa-globe fa-3x" aria-hidden="true"></i>
                            <span class="travel-metadata">
                                <div class="title">Land</div>
                                <div class="attribute">
                                    <?php 
                                        if(isset($field_country[0]['value'])) {
                                            print $field_country[0]['value']; 
                                        } else {
                                            print "Niet bekend";
                                        }
                                    ?>
                                </div>
                            </span>
                        </div><!-- /.col-md-3 -->

                        <div class="col-md-3 col-xs-6">
                            <i class="fa fa-map-marker fa-3x" aria-hidden="true"></i>
                            <span class="travel-metadata">
                                <div class="title">Regio</div>
                                <div class="attribute">
                                    <?php 
                                        if($field_region[0]['value']) {
                                            print $field_region[0]['value']; 
                                        } else {
                                            print "Niet bekend";
                                        }
                                    ?>
                                </div>
                            </span>
                        </div><!-- /.col-md-3 -->

                        <div class="col-md-3 col-xs-6">
                            <i class="fa fa-map-signs fa-3x" aria-hidden="true"></i>
                            <span class="travel-metadata">
                                <div class="title">Stad</div>
                                <div class="attribute">
                                    <?php 
                                        if($field_city[0]['value']) {
                                            print $field_city[0]['value'];
                                        } else {
                                            print "Niet bekend";
                                        }
                                    ?>
                                </div>
                            </span>
                        </div><!-- /.col-md-3 -->

                        <div class="col-md-3 col-xs-6">
                            <span class="travel-metadata">
                                <div class="title">Vervoer</div>
                                <div class="attribute">Niet bekend</div>
                            </span>
                        </div><!-- /.col-md-3 -->
                    </div><!-- travel-information -->

                    <div class="vacation">
                        <?php print render($content['field_image']); ?>

                        <h3><?php print $title; ?></h3>

                        <?php print $body[0]['value']; ?>
                    </div><!-- /.vacation -->

                    <!-- vakantie view -->
                    <div class="row">
                        <div class="col-md-12 related-vacations-header">
                            <h3>VERGELIJKERBARE VAKANTIES</h3>
                        </div><!-- /.col-md-12 -->
                        <?php print views_embed_view('vakantie', $display_id = 'block_1', 'Cyprus'); ?>
                    </div>
                </div><!-- /.col-md-9 -->

                <div class="col-md-3">
                    <div class="pricing">
                        <div class="price">&euro;<?php print $field_price[0]['value']; ?></div>
                        <div class="person">Per persoon</div>
                    </div><!-- /.pricing -->

                    <a href="<?php print $field_url[0]['url']; ?>" class="call-to-action">
                        <div class="inner">Reis boeken<i class="fa fa-plane fa-lg" aria-hidden="true"></i></div><!-- /.inner -->
                        <div class="circle"><i class="fa fa-arrow-right fa-lg" aria-hidden="true"></i></div><!-- /.circle -->
                    </a><!-- /.call-to-action -->

                    <!-- pass the city and country iso as props down to the component(weatherapi.vue) -->
                    <weatherapi city="<?php print $field_city[0]['value']; ?>" iso="<?php print $field_country_iso[0]['value']; ?>"></weatherapi>
                </div><!-- /.col-md-3 -->
            </div><!-- /.row -->
        </div><!-- /.container -->
    </div><!-- /.content -->
</div><!-- /#node -->
