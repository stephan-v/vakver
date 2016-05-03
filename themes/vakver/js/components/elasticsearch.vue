// app.vue
<style>
	.highlight {
		color: #74AF2A;
		font-weight: bold;
	}
	[v-cloak] {
	  display: none;
	}
</style>

<template>
	<div class="row main-search-wrapper">
        <div class="col-md-6 col-md-offset-3">
            <i class="fa fa-search fa-2x" aria-hidden="true"></i>
            <!-- add: debounce="500" for a 500ms delay -->
            <input type="text" placeholder="Zoek op naam, land, stad of regio" v-on:keyup="search" v-model="query">
        </div><!-- /.col-md-6 -->

        <div class="col-md-3 view-options">
            <i class="fa fa-bars fa-2x" aria-hidden="true" v-bind:class="{ 'active': !toggleView}" v-on:click="toggleView = false"></i>
            <i class="fa fa-th-large fa-2x" aria-hidden="true" v-bind:class="{ 'active': toggleView}" v-on:click="toggleView = true"></i>
        </div><!-- /.col-md-3 -->
    </div><!-- /.row -->

	<div v-if="toggleView" class="row" v-for="row in travels | chunk 4">
		<div class="col-md-3" v-for="travel in row">
			<div class="vacation-item">
				<a href="/node/{{ travel._source.nid }}">
					<div class="placeholder-img" v-bind:style="{ 'background-image': 'url(' + travel._source.field_image[0].url + ')' }">
						<div class="star-rating">
							<i class="fa fa-star fa-lg" aria-hidden="true" v-for="star in parseInt(travel._source.stars[0].value)"></i>
						</div><!-- /.star-rating -->
					</div><!-- /.placeholder-img -->

					<div class="content">
						<h2 v-if="travel.highlight">{{{ travel.highlight.title }}}</h2>
						<h2 v-else>{{{ travel._source.title }}}</h2>
						<p>{{ travel._source.body[0].value.substring(0, 85) }}...</p>
					</div><!-- /.content -->
				</a>
			</div><!-- /.vacation-item -->
		</div><!-- /.col-md-3 -->
	</div><!-- /.row -->

	<div v-if="!toggleView" class="row list-view" v-for="travel in travels">
		<div class="col-md-10 col-md-offset-1">
			<div class="vacation-item">
				<a href="/node/{{ travel._source.nid }}">
					<div class="col-md-3">
						<div class="placeholder-img" v-bind:style="{ 'background-image': 'url(' + travel._source.field_image[0].url + ')' }">
							<div class="star-rating">
								<i class="fa fa-star fa-lg" aria-hidden="true" v-for="star in parseInt(travel._source.stars[0].value)"></i>
							</div><!-- /.star-rating -->
						</div><!-- /.placeholder-img -->
					</div><!-- /.col-md-3 -->

					<div class="col-md-9">
						<div class="content">
							<h2 v-if="travel.highlight">{{{ travel.highlight.title }}}</h2>
							<h2 v-else>{{{ travel._source.title }}}</h2>
							<p>{{ travel._source.body[0].value.substring(0, 85) }}...</p>
						</div><!-- /.content -->
					</div><!-- /.col-md-9 -->
				</div><!-- /.vacation-item -->
			</a>
		</div><!-- /.col-md-3 -->
	</div><!-- /.row -->

	<div class="row">
		<nav class="text-center">
			<ul class="pagination">
				<li>
					<a href="#" aria-label="Previous" v-on:click.prevent="prevPage()">
						<span aria-hidden="true">&laquo;</span>
					</a>
				</li>

				<li v-for="index in 10" v-bind:class="{'active' : index == this.page }">
					<a href="#" v-on:click.prevent="paginate(index)">{{ index+1 }}</a>
				</li>

				<li>
					<a href="#" aria-label="Next" v-on:click.prevent="nextPage()">
						<span aria-hidden="true">&raquo;</span>
					</a>
				</li>
			</ul><!-- /.pagination -->
		</nav>
	</div><!-- /.row -->
</template>

<script>
	export default {
		ready: function() {
			var elasticsearch = require('elasticsearch');

			this.client = new elasticsearch.Client({
				host: 'localhost:9200',
				log: 'trace'
			});

			// perform the initial search
			this.search();
		},
		data () {
			return {
				client: '',
				msg: 'Vue test',
				travels: '',
				query: '',
				toggleView: true,
				page: 0,
				activeFilter: false,
				rating: 0
			}
		},
		events: {
			'filter-stars': function(rating) {
				this.activeFilter = true;
				this.rating = rating;

				this.client.search({
						index: 'node',
						type: 'vakantie',
						from: 0,
  						size: 12,
  						body: {
  							query: {
  								match: {
  									"stars.value": rating
  								}
							}
  						}
				}).then(function (resp) {
					this.travels = resp.hits.hits;

					// dispatch this data to the entry.js file
					this.$dispatch('travel-hits', resp.hits.total);
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			}
		},
		methods: {
			search: function() {
				if(this.activeFilter && this.query) {
					this.client.search({
						index: 'node',
						type: 'vakantie',
						from: 0,
	  					size: 12,
						body: {			
					    	"query": {
						        "bool": {
						            "must": [
						                {
						                    "match": {
						                        "stars.value": this.rating
						                    }
						                },
						                {
						                    "match_phrase_prefix": {
						                        "title": this.query
						                    }
						                }
						            ]
						        }
						    },
						    "highlight": {
						        "fields": {
						            "title": {}
						        },
						        "pre_tags": ["<span class='highlight'>"],
								"post_tags": ["</span>"]
						    }
						}
					}).then(function (resp) {
						this.travels = resp.hits.hits;

						// dispatch this data to the entry.js file
						this.$dispatch('travel-hits', resp.hits.total);
					}.bind(this), function (err) {
						console.trace(err.message);
					});

					return;
				}

				// if there is a query from the input we look for that query
				if(this.query) {
					this.client.search({
						index: 'node',
						type: 'vakantie',
						from: 0,
	  					size: 12,
						body: {					
							query: {
								match_phrase_prefix: {
									title: {
										query: this.query,
										slop: 10,
										max_expansions: 50
									}
								}
							},
							highlight: {
					            fields: {
					                title: {}
					            },
					            pre_tags: ["<span class='highlight'>"],
	        					post_tags: ["</span>"]
					        }
						}
					}).then(function (resp) {
						this.travels = resp.hits.hits;

						// dispatch this data to the entry.js file
						this.$dispatch('travel-hits', resp.hits.total);
					}.bind(this), function (err) {
						console.trace(err.message);
					});

				// else we simply run a query to get al results
				} else {
					this.client.search({
							index: 'node',
							type: 'vakantie',
							from: 0,
	  						size: 12,
					}).then(function (resp) {
						this.travels = resp.hits.hits;

						// dispatch this data to the entry.js file
						this.$dispatch('travel-hits', resp.hits.total);
					}.bind(this), function (err) {
						console.trace(err.message);
					});
				}
			},

			paginate: function(index) {
				this.client.search({
						index: 'node',
						type: 'vakantie',
						from: 12 * index,
						size: 12,
				}).then(function (resp) {
					this.travels = resp.hits.hits;
					
					this.page = index;
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			},

			prevPage: function() {
				this.page--;
				this.paginate(this.page);
			},

			nextPage: function() {
				this.page++;
				this.paginate(this.page);
			}
		}
	}
</script>