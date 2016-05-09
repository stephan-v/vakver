<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="header index-header" style="background-image: url(<?php print file_create_url($node->field_image['und'][0]['uri']); ?>)"></div><!-- /.header -->

    <div class="sort-bar">
        <div class="container">
            <ul class="list-inline pull-left">
                <li class="bold">SORTEER OP</li>
                <li>POPULARITEIT</li>
                <li>PRIJS</li>
                <li>RATING</li>
            </ul>

            <ul class="list-inline pull-right">
                <li v-if="hits > 1 || hits == 0">{{ hits }} vakanties gevonden</li>
                <li v-else="">{{ hits }} vakantie gevonden</li>
            </ul>
        </div><!-- /.container -->
    </div>

    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="main-content">
        <aside>
            <div class="btn">Filter reizen</div>

            <div class="filter">
                <div class="filter-header">
                    <h3>Landen</h3>
                    <div class="filter-count">20</div>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->

                <div class="readmore">
                    <ul>
                        <li>Verenigde arabische emiraten</li>
                        <li>Canarische Eilanden</li>
                        <li>Griekenland</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                    </ul>
                </div><!-- /.readmore -->
            </div><!-- /.filer -->

            <div class="filter">
                <div class="filter-header">
                    <h3>Vervoersmiddel</h3>
                    <div class="filter-count">7</div>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->

                <div class="readmore">
                    <ul>
                        <li>Vliegtuig</li>
                        <li>Auto</li>
                        <li>Boot</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                        <li>Verenigde arabische emiraten</li>
                    </ul>
                </div><!-- /.readmore -->
            </div><!-- /.filer -->

            <div class="filter">
                <div class="filter-header">
                    <h3>Rating</h3>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->
                
                <div class="star-rating">
                    <div class="checkbox">
                        <label v-on:click="filterStars(5)">
                            <input type="checkbox" value="">
                            <i class="fa fa-star fa-lg" aria-hidden="true" v-for="index in 5"></i>
                        </label>

                        <label v-on:click="filterStars(4)">
                            <input type="checkbox" value="">
                            <i class="fa fa-star fa-lg" aria-hidden="true" v-for="index in 4"></i>
                        </label>

                        <label v-on:click="filterStars(3)">
                            <input type="checkbox" value="">
                            <i class="fa fa-star fa-lg" aria-hidden="true" v-for="index in 3"></i>
                        </label>

                        <label v-on:click="filterStars(2)">
                            <input type="checkbox" value="">
                            <i class="fa fa-star fa-lg" aria-hidden="true" v-for="index in 2"></i>
                        </label>

                        <label v-on:click="filterStars(1)">
                            <input type="checkbox" value="">
                            <i class="fa fa-star fa-lg" aria-hidden="true" v-for="index in 1"></i>
                        </label>
                    </div>
                </div><!-- /.readmore -->
            </div><!-- /.filer -->
        </aside>

        <div class="container">
            <!-- elasticsearch results(tag is located at: js/components/elasticsearch.vue) -->
            <elasticsearch></elasticsearch>
        </div><!-- /.container -->
    </div><!-- /.main-content -->
</div><!-- /#node -->
