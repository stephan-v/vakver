// app.vue
<style>
	.highlight {
		color: #74AF2A;
		font-weight: bold;
	}
</style>

<template>
	<div class="row main-search-wrapper">
        <div class="col-md-6 col-md-offset-3">
            <i class="fa fa-search fa-2x" aria-hidden="true"></i>
            <!-- add: debounce="500" for a 500ms delay -->
            <input type="text" placeholder="Zoek op naam, land, stad of regio" v-on:keyup="search" v-model="query" class="elasticsearch-input">
        </div><!-- /.col-md-6 -->

        <div class="col-md-3 view-options">
            <i class="fa fa-bars fa-2x" aria-hidden="true" v-bind:class="{ 'active': !toggleView}" v-on:click="toggleView = false"></i>
            <i class="fa fa-th-large fa-2x" aria-hidden="true" v-bind:class="{ 'active': toggleView}" v-on:click="toggleView = true"></i>
        </div><!-- /.col-md-3 -->
    </div><!-- /.row -->

	<div v-if="toggleView" class="row" v-for="row in travels | chunk 4">
		<div class="col-xs-6 col-lg-3" v-for="travel in row">
			<div class="vacation-item">
				<a href="/node/{{ travel._source.nid }}">
					<div class="placeholder-img" v-if="travel._source.field_image" v-bind:style="{ 'background-image': 'url(' + travel._source.field_image[0].url.replace('files', 'files/styles/medium/public') + ')' }">
						<div class="star-rating" v-if="travel._source.stars">
							<i class="fa fa-star fa-lg" aria-hidden="true" v-for="star in travel._source.stars[0].value"></i>
						</div><!-- /.star-rating -->
						<div class="pricing">&euro; {{ Math.floor(travel._source.price[0].value) }}</div><!-- /.pricing -->
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
						<div class="placeholder-img" v-if="travel._source.field_image" v-bind:style="{ 'background-image': 'url(' + travel._source.field_image[0].url.replace('files', 'files/styles/medium/public') + ')' }">
							<div class="star-rating" v-if="travel._source.stars">
								<i class="fa fa-star fa-lg" aria-hidden="true" v-for="star in travel._source.stars[0].value"></i>
							</div><!-- /.star-rating -->
							<div class="pricing">&euro; {{ Math.floor(travel._source.price[0].value) }}</div><!-- /.pricing -->
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

	<div class="row" v-if="this.travels == 0">
		<div class="col-md-6 col-md-offset-3 text-center no-results">
			<h2>We hebben helaas geen resultaten kunnen vinden binnen deze zoekcriteria. Probeer het nog eens.</h2>
		</div><!-- /.col-md-6 -->
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

			
			// check with TLD() helper if the top level domain is .dev or .local
			if(this.getTLD() == "dev" || this.getTLD() == "local") {
				this.client = new elasticsearch.Client({				
					/* development */
					host: 'localhost:9200'
				});
			} else {
				this.client = new elasticsearch.Client({
					/* production */
					host: '46.182.217.108:9200'
				});
			}

			// perform the initial search
			this.search();

			// perform a search for a list of all unique countries
			this.searchUniqueCountries();

			// perform a search for a list of all unique board types
			this.searchUniqueBoards();

			// perform a search for a list of all unique accommodation types
			this.searchUniqueAccommodations();

			// perform a search for the lowest and highest vacation price
			this.searchMinMax();

			// perform a search for a list of all unique board types
			this.searchUniqueDurations();

			// switch pages with left and right keypresses - bind the window scope to this object
			window.onkeydown = function (e) {
			    var code = e.keyCode ? e.keyCode : e.which;
			    if (code === 37) {
			        this.prevPage();
			    } else if (code === 39) {
			        this.nextPage();
			    }
			}.bind(this);
		},
		data: function() {
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
  					size: 12,
  					body: {
  						"highlight": {
				            "fields": {
				                "title": {}
				            },
				            "pre_tags": ["<span class='highlight'>"],
        					"post_tags": ["</span>"]
				        }
  					}
				},
				sortRatingDesc: false,
				sortPriceDesc: false,

				// apply filters with these arrays
				countries: [],
				boards: [],
				accommodations: [],
				durations: [],
				priceRange: [],
				priceMinMax: [],

				// debounce timer
				timer: 0
			};
		},
		events: {
			// general filter functionality
			'filterListener': function(itemsToFilter, plural) {
				// dynamically assign the property to call
				this[plural] = itemsToFilter;

				this.search();
			},
			'searchListener': function(query) {
				this.query = query;

				this.search()
			},
			'ratingsListener': function(ratings) {
				this.ratings = ratings;

				this.search();
			},
			'sortListener': function(sort) {
				this.sort(sort);
			},
			'priceListener': function(range) {
				this.priceRange = range;

				/* custom made debouncer */
				 
				// clears the timer so there is always x seconds in between calls
				clearTimeout(this.timer);

				// setTimeout calls a function after x seconds
            	this.timer = setTimeout(function(){
					this.search()
				}.bind(this), 150);
			},
			'removeSortListener': function(sort) {
				this.removeSort(sort);
			},
		},
		methods: {
			/*
			|--------------------------------------------------------------------------
			| Sort functionality for elasticsearch
			|--------------------------------------------------------------------------
			|
			| Implement a sort filter on top of any query that might be set
			|
			*/
		
			sort: function(sort) {
				if(sort == 'rating') {
					this.sortRatingDesc = !this.sortRatingDesc;

					// dispatch this data to the entry.js file
					this.$dispatch('sort-order', this.sortRatingDesc, 'rating');

					if(this.sortRatingDesc) {
						this.queryDSL.body.sort = {
					        "stars.value": { "order": "desc" }
						}
					} else {
						this.queryDSL.body.sort = {
					        "stars.value": { "order": "asc" }
						}
					}
				}

				if(sort == 'price') {
					this.sortPriceDesc = !this.sortPriceDesc;

					// dispatch this data to the entry.js file
					this.$dispatch('sort-order', this.sortPriceDesc, 'price');

					if(this.sortPriceDesc) {
						this.queryDSL.body.sort = {
					        "price.value": { "order": "desc" }
						}
					} else {
						this.queryDSL.body.sort = {
					        "price.value": { "order": "asc" }
						}
					}
				}

				this.search();
			},

			/*
			|--------------------------------------------------------------------------
			| remove sort functionality for elasticsearch
			|--------------------------------------------------------------------------
			|
			| delete the sort property from the main query
			|
			*/
		
			removeSort: function(sort) {
				delete this.queryDSL.body.sort;

				this.search();
			},

			/*
			|--------------------------------------------------------------------------
			| Global search
			|--------------------------------------------------------------------------
			|
			| Global search method and combination of search queries, these will all 
			| append or delete so a single if statement for each one is adequate
			|
			*/
		
			search: function() {
				// if a query has been set
				if(this.query) {
					// create the query value because we can't have an empty query field in the elasticsearch body
					// this will result in an error
					this.queryDSL.body.query = {},

					this.queryDSL.body.query.multi_match = {
						"fields" : ["title", "country.value", "region.value"],
			            "query" : this.query,
			            "type" : "phrase_prefix",
			            "max_expansions": 50,
			            "slop": 10
					}
				} else {
					// if no query, filter or sort has been set delete the query property from the object entirely to prevent elasticsearch errors
					delete this.queryDSL.body.query;
				}

				/*
				|--------------------------------------------------------------------------
				| Search Filters
				|--------------------------------------------------------------------------
				|
				| Add new search filters here with arguments: itemsToFilter, filterValue
				| itemsToFilter being an array, filterValue the Elasticsearch db value
				|
				*/
			
				// if a filter vaue has been set also set a filter for it, otherwise delete it to prevent elasticsearch errors
				if(this.ratings.length > 0 || this.countries.length > 0 || this.boards.length > 0 || this.priceRange.length > 0 || this.durations.length > 0) {
					this.queryDSL.body.filter = {};
					this.queryDSL.body.filter.bool = {};
					this.queryDSL.body.filter.bool.must = [];
				} else {
					delete this.queryDSL.body.filter;
				}
			
				if(this.ratings.length > 0) {
					this.searchFilter(this.ratings, "stars.value");
				}

				if(this.countries.length > 0) {
					this.searchFilter(this.countries, "country.value.raw");
				}

				if(this.boards.length > 0) {
					this.searchFilter(this.boards, "board_type.value.raw");
				}

				if(this.accommodations.length > 0) {
					this.searchFilter(this.accommodations, "accommodation.value.raw");
				}

				if(this.durations.length > 0) {
					this.searchFilter(this.durations, "duration.value");
				}

				if(this.priceRange.length > 0) {
					this.priceFilter();
				}


				/* The main search function */
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
			| Searchfilter method
			|--------------------------------------------------------------------------
			|
			| Method responsible for filtering searches this receives 2 arguments
			| The array of items to filter and the value to filter through.
			|
			*/
		
			searchFilter: function(itemsToFilter, filterValue) { 
				setFilter = false;

				for (var i = 0, len = this.queryDSL.body.filter.bool.must.length; i < len; i++) {
					// if the value is in the must query update it, otherwise create it
					if (filterValue in this.queryDSL.body.filter.bool.must[i].terms) {
						this.queryDSL.body.filter.bool.must[i].terms[filterValue] = itemsToFilter;
						
						setFilter = true;
					}
				}

				// if the filter has not been set yet, set it one time only
				if(!setFilter) {
					this.queryDSL.body.filter.bool.must.push({ "terms": { [filterValue]: itemsToFilter } });
				}
			},

			priceFilter: function() {
				this.queryDSL.body.filter.bool.must.push({ "range": { "price.value": {"gte": this.priceRange[0], "lte": this.priceRange[1]} } });
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
						// append the suffix from others filters if there are any
						body: this.queryDSL.body
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
			},

			/*
			|--------------------------------------------------------------------------
			| Aggregation query to get a list of all unique countries
			|--------------------------------------------------------------------------
			|
			| Size is set to zero so we don't get a full hit, this results in much
			| faster searches. With this query we get a unique value and the 
			| amount of hits per unique value.
			|
			*/
		
			searchUniqueCountries: function() {
				this.client.search({
					index: 'node',
					type: 'vakantie',
  					body: {
						"size" : 0,
					    "aggs" : { 
					        "countries" : { 
					            "terms" : { 
					              "size" : 100,
					              "field" : "country.value.raw"
					            }
					        }
					    }
					}
				}).then(function (resp) {
					// dispatch this data to the entry.js file
					this.$dispatch('unique-countries', resp.aggregations.countries.buckets);
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			},

			/*
			|--------------------------------------------------------------------------
			| Aggregation query to get a list of all unique accommodations
			|--------------------------------------------------------------------------
			|
			| Same as above
			|
			*/
		
			searchUniqueBoards: function() {
				this.client.search({
					index: 'node',
					type: 'vakantie',
  					body: {
						"size" : 0,
					    "aggs" : { 
					        "boards" : { 
					            "terms" : { 
					              "size" : 100,
					              "field" : "board_type.value.raw"
					            }
					        }
					    }
					}
				}).then(function (resp) {
					// dispatch this data to the entry.js file
					this.$dispatch('unique-boards', resp.aggregations.boards.buckets);
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			},

			/*
			|--------------------------------------------------------------------------
			| Aggregation query to get a list of all unique accommodations
			|--------------------------------------------------------------------------
			|
			| Same as above
			|
			*/
		
			searchUniqueAccommodations: function() {
				this.client.search({
					index: 'node',
					type: 'vakantie',
  					body: {
						"size" : 0,
					    "aggs" : { 
					        "accommodations" : { 
					            "terms" : { 
					              "size" : 100,
					              "field" : "accommodation.value.raw"
					            }
					        }
					    }
					}
				}).then(function (resp) {
					// dispatch this data to the entry.js file
					this.$dispatch('unique-accommodations', resp.aggregations.accommodations.buckets);
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			},

			/*
			|--------------------------------------------------------------------------
			| Aggregation query to the min and max price for vacations
			|--------------------------------------------------------------------------
			|
			| Same as above - values are meant for the price sliders max and min values
			|
			*/
		
			searchMinMax: function() {
				this.client.search({
					index: 'node',
					type: 'vakantie',
  					body: {
						"size" : 0,
					    "aggs" : { 
					        "min_price" : { "min" : { "field" : "price.value" } },
					        "max_price" : { "max" : { "field" : "price.value" } }
					    }
					}
				}).then(function (resp) {
					// dispatch this data to the entry.js file
					this.priceMinMax = resp.aggregations;
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			},

			/*
			|--------------------------------------------------------------------------
			| Aggregation query to get a list of all unique accommodations
			|--------------------------------------------------------------------------
			|
			| Same as above
			|
			*/
		
			searchUniqueDurations: function() {
				this.client.search({
					index: 'node',
					type: 'vakantie',
  					body: {
						"size" : 0,
					    "aggs" : { 
					        "durations" : { 
					            "terms" : { 
					              "size" : 100,
					              "field" : "duration.value"
					            }
					        }
					    }
					}
				}).then(function (resp) {
					// dispatch this data to the entry.js file
					this.$dispatch('unique-durations', resp.aggregations.durations.buckets);
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			},

			/*
			|--------------------------------------------------------------------------
			| Helper method to fetch the Top Level Domain
			|--------------------------------------------------------------------------
			|
			| Grab the TLD of .dev or .local and change settings depending on the env
			|
			*/

			getTLD: function() {  
			      var hostName = window.location.hostname;  
			      var hostNameArray = hostName.split(".");  
			      var posOfTld = hostNameArray.length - 1;  
			      var tld = hostNameArray[posOfTld];  
			      return tld;  
			 }
		}
	}
</script>