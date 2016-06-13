<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="header index-header" style="background-image: url(<?php print file_create_url($node->field_image['und'][0]['uri']); ?>)">
        <div class="absolute-center skewed-label">
            <h1>Meer dan {{ Math.floor(this.$children[0].$data.hits / 100) * 100 }} vakanties</h1>
        </div><!-- /.skewed-label -->
    </div><!-- /.header -->

    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="main-content">
        <aside>
            <div class="filter slider">
                <h3>Prijs</h3>
                <div id="slider-handles"></div>
                <div class="range">
                    <div id="slider-margin-value-min"></div>
                    <div id="slider-margin-value-max"></div>
                </div><!-- /.range -->
            </div><!-- /.slider -->

            <div class="filter">
                <div class="filter-header">
                    <h3>Landen</h3>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->

                <div class="readmore">
                    <ul>
                        <!-- custom block voor vakanties die bovenaan moeten komen te staan - landnaam moet met hoofdletter -->
                        <li v-on:click="filter('Spanje', 'country', 'countries')" v-bind:class="{ 'active': countriesToFilter.indexOf('Spanje') > -1 }">Spanje</li>

                        <div class="filter-item" v-for="country in countries | orderBy 'key'">
                            <li v-on:click="filter(country.key, 'country', 'countries')" v-bind:class="{ 'active': countriesToFilter.indexOf(country.key) > -1 }">
                                {{ country.key | capitalize }}
                            </li>
                            <span class="filter-count">{{ country.doc_count }}</span>
                        </div><!-- /.filter-item -->
                    </ul>
                </div><!-- /.readmore -->
            </div><!-- /.filer -->

            <div class="filter">
                <div class="filter-header">
                    <h3>Verzorgingstype</h3>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->

                <div class="readmore">
                    <ul>
                        <div class="filter-item" v-for="board in boards | orderBy 'key'">
                            <li v-on:click="filter(board.key, 'board', 'boards')" v-bind:class="{ 'active': boardsToFilter.indexOf(board.key) > -1 }">{{ board.key | capitalize }}</li>
                            <span class="filter-count">{{ board.doc_count }}</span>
                        </div><!-- /.filter-item -->
                    </ul>
                </div><!-- /.readmore -->
            </div><!-- /.filer -->

            <div class="filter">
                <div class="filter-header">
                    <h3>Accommodaties</h3>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->

                <div class="readmore">
                    <ul>
                        <div class="filter-item" v-for="accommodation in accommodations | orderBy 'key'">
                            <li v-on:click="filter(accommodation.key, 'accommodation', 'accommodations')" v-bind:class="{ 'active': accommodationsToFilter.indexOf(accommodation.key) > -1 }">{{ accommodation.key | capitalize }}</li>
                            <span class="filter-count">{{ accommodation.doc_count }}</span>
                        </div><!-- /.filter-item -->
                    </ul>
                </div><!-- /.readmore -->
            </div><!-- /.filer -->

            <div class="filter">
                <div class="filter-header">
                    <h3>Reisduur</h3>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->

                <div class="readmore">
                    <ul>
                        <div class="filter-item" v-for="duration in durations.slice().reverse()">
                            <li v-on:click="filter(duration.key, 'duration', 'durations')" v-bind:class="{ 'active': durationsToFilter.indexOf(duration.key) > -1 }">{{ duration.key | capitalize }} dagen</li>
                            <span class="filter-count">{{ duration.doc_count }}</span>
                        </div><!-- /.filter-item -->
                    </ul>
                </div><!-- /.readmore -->
            </div><!-- /.filer -->

            <div class="filter">
                <div class="filter-header">
                    <h3>Vervoersmiddel</h3>
                    <div class="clearfix"></div>
                </div><!-- /.filter-header -->

                <div class="readmore">
                    <ul>
                        <div class="filter-item" v-for="transportation in transportations.slice().reverse()">
                            <li v-on:click="filter(transportation.key, 'transportation', 'transportations')" v-bind:class="{ 'active': transportationsToFilter.indexOf(transportation.key) > -1 }">{{ transportation.key | capitalize }}</li>
                            <span class="filter-count">{{ transportation.doc_count }}</span>
                        </div><!-- /.filter-item -->
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
                <div class="col-md-12 always-float">
                    <!-- elasticsearch results(tag is located at: js/components/elasticsearch.vue) -->
                    <elasticsearch></elasticsearch>
                </div>
            </div><!-- /.container -->
        </div><!-- /.wrapper -->
    </div><!-- /.main-content -->
</div><!-- /#node -->
