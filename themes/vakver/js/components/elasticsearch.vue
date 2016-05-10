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
					<div class="placeholder-img" v-if="travel._source.field_image" v-bind:style="{ 'background-image': 'url(' + travel._source.field_image[0].url + ')' }">
						<div class="star-rating" v-if="travel._source.stars">
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
						<div class="placeholder-img" v-if="travel._source.field_image" v-bind:style="{ 'background-image': 'url(' + travel._source.field_image[0].url + ')' }">
							<div class="star-rating" v-if="travel._source.stars">
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

				<!-- crucial v-if logic to render the pagination -->
				<li v-for="pageNumber in totalPages" v-bind:class="{'active' : pageNumber == this.currentPage }" v-if="Math.abs(pageNumber - currentPage) < 4 || pageNumber == totalPages - 1 || pageNumber == 0">
					<a href="#" v-on:click.prevent="paginate(pageNumber)">{{ pageNumber+1 }}</a>
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
				// log: 'trace'
			});

			// perform the initial search
			this.search();

			// switch pages with left and right keypresses - bind the window scope to this object
			window.onkeydown = function (e) {
			    var code = e.keyCode ? e.keyCode : e.which;
			    if (code === 37) { //left key
			        this.prevPage();
			    } else if (code === 39) { //right key
			        this.nextPage();
			    }
			}.bind(this);
		},
		data () {
			return {
				client: '',
				travels: '',
				query: '',
				toggleView: true,
				currentPage: 0,
				totalPages: 0,
				activeFilter: false,
				ratings: [],
				size: 12,
				queryDSL: {
					index: 'node',
					type: 'vakantie',
					from: 0,
  					size: 12
				},
				// probably refactor this bullshit
				querySuffix: {}
			}
		},
		events: {
			'receiveRatings': function(ratings) {
				this.ratings = ratings;

				this.search();
			}
		},
		methods: {

			/*
			|--------------------------------------------------------------------------
			| Global search
			|--------------------------------------------------------------------------
			|
			| Global search method and combination of search queries
			|
			*/
		
			search: function() {
				// if a query and rating is set
				if(this.query && this.ratings.length > 0) {
					this.queryDSL.body = {
						"highlight": {
				            "fields": {
				                "title": {}
				            },
				            "pre_tags": ["<span class='highlight'>"],
        					"post_tags": ["</span>"]
				        },			
						"query": {
							"match_phrase_prefix": {
								"title": {
									"query": this.query,
									"slop": 10,
									"max_expansions": 50
								}
							}
						},
						"filter": {
					        "term": { "stars.value": this.ratings }
					    }
					},
					this.querySuffix = this.queryDSL.body;
				// if a query is set
				} else if(this.query) {
					this.queryDSL.body = {
						"highlight": {
				            "fields": {
				                "title": {}
				            },
				            "pre_tags": ["<span class='highlight'>"],
        					"post_tags": ["</span>"]
				        },			
						"query": {
							"match_phrase_prefix": {
								"title": {
									"query": this.query,
									"slop": 10,
									"max_expansions": 50
								}
							}
						}
					},
					this.querySuffix = this.queryDSL.body;
				// if a rating is set
				} else if(this.ratings.length > 0) {
					this.queryDSL.body = {
  						"query": {
							"terms": {
								"stars.value": this.ratings
							}
						}
					},
					this.querySuffix = this.queryDSL.body;
				// if nothing is set
				} else {
					this.queryDSL = {
						index: 'node',
						type: 'vakantie',
						from: 0,
	  					size: 12
					}
				}

				this.client.search(
					this.queryDSL
				).then(function (resp) {
					this.travels = resp.hits.hits;

					// total number of pages rounded up so we also get a page with less than 12 results if need be
					this.totalPages = Math.ceil(resp.hits.total / this.size);

					// dispatch this data to the entry.js file
					this.$dispatch('travel-hits', resp.hits.total);
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			},

			/*
			|--------------------------------------------------------------------------
			| Pagination Methods
			|--------------------------------------------------------------------------
			|
			| Pagination click handlers. Direct, next and previous.
			|
			*/
		
			paginate: function(index) {
				this.client.search({
						index: 'node',
						type: 'vakantie',
						from: 12 * index,
						size: this.size,
						body: this.querySuffix
				}).then(function (resp) {
					this.travels = resp.hits.hits;
					
					this.currentPage = index;
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			},
			prevPage: function() {
				if(this.currentPage > 0) {
					this.currentPage--;
					this.paginate(this.currentPage);
				}
			},
			nextPage: function() {
				if(this.currentPage < (this.totalPages -1)) {
					this.currentPage++;
					this.paginate(this.currentPage);
				}
			}
		}
	}
</script>