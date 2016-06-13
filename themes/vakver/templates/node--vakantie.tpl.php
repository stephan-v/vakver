<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
        <?php if (!$page): ?>
            <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <?php endif; ?>
    <?php print render($title_suffix); ?>
    
    <div class="vacation-header header-single" style="background-image: url(<?php print image_style_url('blur', $field_image[0]['uri']); ?>);">
        <div class="absolute-center skewed-label">
            <h1><?php print $title; ?></h1>

            <!-- if older than 2 weeks in seconds than show the nieuw label -->
            <?php if((time() - $node->created) < 1209600): ?>
                <h2>NIEUW</h2>
            <?php endif; ?>
        </div>
    </div><!-- /.vacation-header -->

    <div class="content"<?php print $content_attributes; ?>>
        <div class="container">
            <div class="row">
                <div class="col-md-9">
                    <div class="travel-information row text-center">
                        <div class="col-md-3 col-xs-6">
                            <i class="fa fa-globe fa-2x" aria-hidden="true"></i>
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
                            <i class="fa fa-map-marker fa-2x" aria-hidden="true"></i>
                            <span class="travel-metadata">
                                <div class="title">Regio</div>
                                <div class="attribute">
                                    <?php 
                                        if(isset($field_region[0]['value'])) {
                                            print $field_region[0]['value']; 
                                        } else {
                                            print "Niet bekend";
                                        }
                                    ?>
                                </div>
                            </span>
                        </div><!-- /.col-md-3 -->

                        <div class="col-md-3 col-xs-6">
                            <i class="fa fa-map-signs fa-2x" aria-hidden="true"></i>
                            <span class="travel-metadata">
                                <div class="title">Stad</div>
                                <div class="attribute">
                                    <?php 
                                        if(isset($field_city[0]['value'])) {
                                            print $field_city[0]['value'];
                                        } else {
                                            print "Niet bekend";
                                        }
                                    ?>
                                </div>
                            </span>
                        </div><!-- /.col-md-3 -->

                        <div class="col-md-3 col-xs-6">
                            <?php if($field_transportation[0]['value'] === 'vliegtuig'): ?>
                                <i class="fa fa-plane fa-2x" aria-hidden="true"></i>
                            <?php else: ?>
                                <i class="fa fa-map-o fa-2x" aria-hidden="true"></i>
                            <?php endif; ?>
                            <span class="travel-metadata">
                                <div class="title">Vervoer</div>
                                <div class="attribute">
                                    <?php 
                                        if(isset($field_transportation[0]['value'])) {
                                            print $field_transportation[0]['value'];
                                        } else {
                                            print "Niet bekend";
                                        }
                                    ?>
                                </div>
                            </span>
                        </div><!-- /.col-md-3 -->
                    </div><!-- travel-information -->

                    <div class="vacation">
                        <div class="social-media">
                            <?php print render($content['addtoany']); ?>
                        </div><!-- /.social-media -->

                        <h3><?php print $title; ?></h3>

                        <?php print text_summary($body[0]['value'], NULL, 180); ?>

                        <?php print render($content['field_image']); ?>

                        <div class="extra-info-header">Aanvullende informatie</div>
                        <div class="extra-info">
                            <ul>
                                <?php if(isset($field_board_type[0]['value'])): ?>
                                    <li><strong>Verzorgingstype:</strong> <?php print $field_board_type[0]['value']; ?></li>
                                <?php endif; ?>

                                <?php if(isset($field_duration[0]['value'])): ?>
                                    <li><strong>Reisduur:</strong> <?php print $field_duration[0]['value']; ?> dagen</li>
                                <?php endif; ?>

                                <?php if(isset($field_accommodation[0]['value'])): ?>
                                    <li><strong>Accommodatie:</strong> <?php print $field_accommodation[0]['value']; ?></li>
                                <?php endif; ?>
                            </ul>
                        </div><!-- /.extra-info -->

                        <a href="<?php print $field_url[0]['url']; ?>" class="call-to-action book-now" target="_blank">Boek nu</a><!-- /.call-to-action -->
                    </div><!-- /.vacation -->
                </div><!-- /.col-md-9 -->

                <div class="col-md-3">
                    <div class="row">
                        <div class="col-sm-6 col-md-12">
                            <div class="pricing">
                                <div class="price">vanaf &euro;<?php print round($field_price[0]['value']); ?></div>
                                <div class="person">Per persoon</div>
                            </div><!-- /.pricing -->
                        </div><!-- /.col-xs-6 -->

                        <div class="col-sm-6 col-md-12">
                            <a href="<?php print $field_url[0]['url']; ?>" class="call-to-action" target="_blank">
                                <div class="inner">Reis boeken<i class="fa fa-plane fa-lg" aria-hidden="true"></i></div><!-- /.inner -->
                                <div class="circle"><i class="fa fa-arrow-right fa-lg" aria-hidden="true"></i></div><!-- /.circle -->
                            </a><!-- /.call-to-action -->
                        </div><!-- /.col-xs-6 -->
                    </div>

                    <div class="row">
                        <div class="col-md-12">
                            <?php
                                // search for a node by travel_agency field
                                $agencyObject = new EntityFieldQuery;
                                $agency = $agencyObject
                                  ->entityCondition('entity_type', 'node')
                                  ->propertyCondition('title', $field_travel_agency[0]['value'])
                                  ->execute();

                                  if(isset($agency['node'])) {
                                    // array_shift to get rid of the first array item
                                    $agency_node = node_load(array_shift(array_keys($agency['node'])));
                                  }
                            ?>

                            <?php if(isset($agency_node->field_logo['und'][0]['uri'])): ?>
                                <a href="/<?php print drupal_get_path_alias('node/' . $agency_node->nid); ?>">
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

            <!-- vakantie view -->
            <div class="row">
                <div class="col-md-12 related-vacations-header">
                    <h3>Anderen bekeken ook</h3>
                </div><!-- /.col-md-12 -->
                <?php print views_embed_view('vakantie', $display_id = 'block_1', $field_country[0]['value']); ?>
            </div>
        </div><!-- /.container -->
    </div><!-- /.content -->
</div><!-- /#node -->
