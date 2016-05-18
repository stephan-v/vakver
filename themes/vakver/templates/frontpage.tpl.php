<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="header index-header" style="background-image: url(<?php print file_create_url($node->field_image['und'][0]['uri']); ?>)"></div><!-- /.header -->

    <div class="sort-bar">
        <div class="container">
            <div class="row">
            <div class="col-sm-8">
                <ul class="list-inline">
                    <li class="bold">SORTEER OP</li>

                    <li>
                        <i class="fa fa-times-circle fa-lg" aria-hidden="true" v-if="sortPopularity" v-on:click="removeSort('popularity')"></i>

                        <div class="toggle-sort" v-on:click.prevent="sort('popularity')" v-bind:class="{'active' : sortPopularity }">
                            <span>POPULARITEIT</span>
                            <i class="fa fa-sort-desc fa-lg" aria-hidden="true" v-if="sortPopularity"></i>
                        </div><!-- /.toggle-sort -->
                    </li>

                    <li>
                        <i class="fa fa-times-circle fa-lg" aria-hidden="true" v-if="sortPrice" v-on:click="removeSort('price')"></i>

                        <div class="toggle-sort" v-on:click.prevent="sort('price')" v-bind:class="{'active' : sortPrice }">
                            <span>PRIJS</span>
                            <span v-if="sortPrice">
                                <i class="fa fa-sort-desc fa-lg" aria-hidden="true" v-if="sortPriceDesc"></i>
                                <i class="fa fa-sort-asc fa-lg" aria-hidden="true" v-else></i>
                            </span>
                        </div><!-- /.toggle-sort -->
                    </li>

                    <li>
                        <i class="fa fa-times-circle fa-lg" aria-hidden="true" v-if="sortRating" v-on:click="removeSort('rating')"></i>

                        <div class="toggle-sort" v-on:click.prevent="sort('rating')" v-bind:class="{'active' : sortRating }">
                            <span>RATING</span>
                            <span v-if="sortRating">
                                <i class="fa fa-sort-desc fa-lg" aria-hidden="true" v-if="sortRatingDesc"></i>
                                <i class="fa fa-sort-asc fa-lg" aria-hidden="true" v-else></i>
                            </span>
                        </div><!-- /.toggle-sort -->
                    </li>
                </ul><!-- /.list-inline -->
            </div><!-- /.col-sm-8 -->

            <div class="col-sm-4">
                <ul class="list-inline">
                    <li v-if="hits > 1 || hits == 0">{{ hits }} vakanties gevonden</li>
                    <li v-else="">{{ hits }} vakantie gevonden</li>
                </ul>
            </div><!-- /.col-sm-4 -->
            </div>
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
                    <div class="filter-count">{{ countries.length }}</div>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->

                <div class="readmore">
                    <ul class="countries">
                        <li v-for="country in countries" v-on:click="countryFilter(country.key)" v-bind:class="{ 'active': countriesToFilter.indexOf(country.key) > -1 }">{{ ucfirst(country.key) }}</li>
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
                    <div class="checkbox" v-for="index in 5">
                        <input type="checkbox" value="{{5-index}}" id="rating-{{5-index}}" v-model="ratings">
                        <label for="rating-{{5-index}}">
                            <i class="fa fa-star fa-lg" aria-hidden="true" v-for="n in 5-index"></i>
                        </label>
                    </div><!-- /.checkbox -->
                </div><!-- /.readmore -->
            </div><!-- /.filer -->
        </aside>

        <div class="wrapper">
            <div class="container">
                <!-- elasticsearch results(tag is located at: js/components/elasticsearch.vue) -->
                <elasticsearch></elasticsearch>
            </div><!-- /.container -->
        </div><!-- /.wrapper -->
    </div><!-- /.main-content -->
</div><!-- /#node -->
