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
                        <div class="social-media">
                            <i class="fa fa-facebook-square fa-2x" aria-hidden="true"></i>
                            <i class="fa fa-twitter fa-2x" aria-hidden="true"></i>
                            <i class="fa fa-google-plus fa-lg" aria-hidden="true"></i>
                        </div><!-- /.social-media -->

                        <?php print render($content['field_image']); ?>

                        <h3><?php print $title; ?></h3>

                        <?php print $body[0]['value']; ?>
                    </div><!-- /.vacation -->
                </div><!-- /.col-md-9 -->

                <div class="col-md-3">
                    <div class="row">
                        <div class="col-sm-6 col-md-12">
                            <div class="pricing">
                                <div class="price">&euro;<?php print $field_price[0]['value']; ?></div>
                                <div class="person">Per persoon</div>
                            </div><!-- /.pricing -->
                        </div><!-- /.col-xs-6 -->

                        <div class="col-sm-6 col-md-12">
                            <a href="<?php print $field_url[0]['url']; ?>" class="call-to-action">
                                <div class="inner">Reis boeken<i class="fa fa-plane fa-lg" aria-hidden="true"></i></div><!-- /.inner -->
                                <div class="circle"><i class="fa fa-arrow-right fa-lg" aria-hidden="true"></i></div><!-- /.circle -->
                            </a><!-- /.call-to-action -->
                        </div><!-- /.col-xs-6 -->
                    </div>

                    <div class="row">
                        <div class="col-md-12">
                            <?php
                                // search for a node by travel_agency field
                                $agency = (new EntityFieldQuery())
                                  ->entityCondition('entity_type', 'node')
                                  ->propertyCondition('title', $field_travel_agency[0]['value'])
                                  ->execute();

                                  // array_shift to get rid of the first array item
                                  $agency_node = node_load(array_shift(array_keys($agency['node'])));
                            ?>

                            <?php if(isset($agency_node->field_logo['und'][0]['uri'])): ?>
                                <a href="<?php print drupal_get_path_alias('node/' . $agency_node->nid); ?>">
                                    <?php print theme_image_style(array(
                                        'style_name' => 'large',
                                        'path' => $agency_node->field_logo['und'][0]['uri'],
                                        'width' => $agency_node->field_logo['und'][0]['width'],
                                        'height' => $agency_node->field_logo['und'][0]['height'],
                                        'attributes' => array('class' => 'travel-provided-by')
                                    )); ?>
                                </a>
                            <?php endif; ?>
                        </div><!-- /.col-md-12 -->
                    </div><!-- /.row -->

                    <!-- pass the city and country iso as props down to the component(weatherapi.vue) -->
                    <weatherapi city="<?php print $field_city[0]['value']; ?>" iso="<?php print $field_country_iso[0]['value']; ?>"></weatherapi>
                </div><!-- /.col-md-3 -->
            </div><!-- /.row -->

            <?php print_r($node->field_images); ?>

            <!-- vakantie view -->
            <div class="row">
                <div class="col-md-12 related-vacations-header">
                    <h3>vergelijkbare vakanties</h3>
                </div><!-- /.col-md-12 -->
                <?php print views_embed_view('vakantie', $display_id = 'block_1', $field_country[0]['value']); ?>
            </div>
        </div><!-- /.container -->
    </div><!-- /.content -->
</div><!-- /#node -->
