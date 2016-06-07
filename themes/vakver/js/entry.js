var Vue 			= require('vue');
var Vuex 			= require('vuex');
var Elasticsearch 	= require('./components/elasticsearch.vue')
var WeatherAPI 		= require('./components/weatherapi.vue')

// moment.js settings(timehelper)
var moment 			= require('moment');
require('moment/locale/nl');
global.moment 		= moment;

// make Vue aware of these additional modules
Vue.use(require('vue-resource'));
Vue.use(require('vue-chunk'));
Vue.use(Vuex);

Vue.config.debug = true;

// Globally register the component with tag: my-component
Vue.component('elasticsearch', Elasticsearch);
Vue.component('weatherapi', WeatherAPI);

// give Vue access to jQuery that is tied to the window
var $ = window.jQuery = require('jquery');

// Give Vue and Vuex variable window access, this this not happen by default with webpack and browserify because they wrap our code in an anonymous function
window.Vue = Vue;
window.Vuex = Vue;

$(document).ready(function() {
	// create a root instance
	global.Vue = new Vue({
		el: 'body',
		data: {
			hits: '',
			ratings: [],

			// enabled / disabled filters
			sortPopularity: false,
			sortPrice: false,
			sortRating: false,

			// sortorder for filters
			sortPopularityDesc: false,
			sortRatingDesc: false,
			sortPriceDesc: false,

			// array of unique countries to build a sidebar list
			countries: [],

			// array of countries to filter(sent to the child component)
			countriesToFilter: [],

			// array of unique boards to build a sidebar list
			boards: [],

			// array of accomodations to filter(sent to the child component)
			boardsToFilter: [],

			// array of unique boards to build a sidebar list
			durations: [],

			// array of travel durations to filter(sent to the child component)
			durationsToFilter: [],

			// array of unique accommodations to build a sidebar list
			accommodations: [],

			// array of accommodations to filter(sent to the child component)
			accommodationsToFilter: [],

			query: ''
		},
		watch: {
			'ratings': function() {
				this.$broadcast('ratingsListener', this.ratings);
			}
		},
		ready: function() {
			// if we are on the homepage with a search query, set the query and perform a search for it straight away
			if(window.location.pathname == "/" && location.search.split('search=')[1]) {
				this.query = location.search.split('search=')[1];

				this.search();
			}
		},
		events: {
			// capture the dispatch event from the child component
			'travel-hits': function(hits) {
				this.hits = hits;
			},
			'sort-order': function(sortOrder, filterName) {
				if(filterName == 'rating') {
					this.sortRatingDesc = sortOrder;
				} else {
					this.sortPriceDesc = sortOrder;
				}
			},
			'unique-countries': function(countries) {
				this.countries = countries;
			},
			'unique-accommodations': function(accommodations) {
				this.accommodations = accommodations;
			},
			'unique-boards': function(boards) {
				// remove these elements from the array and filter sidebar - needs to be extremely specific with caps
				for (var i = 0, len = boards.length; i < len; i++) {
					if(boards[i].key == "volgens beschrijving") {
				        boards.splice(i, 1);
				        break;
				    }
				}

				// remove these elements from the array and filter sidebar - needs to be extremely specific with caps
				for (var i = 0, len = boards.length; i < len; i++) {
					if(boards[i].key == "Lookup_VERZORGING_T_1") {
				        boards.splice(i, 1);
				        break;
				    }
				}

				this.boards = boards;
			},
			'unique-durations': function(durations) {
				this.durations = durations;
			}
		},
		methods: {
			// enable a sort
			sort: function(sort) {
				this.sortPopularity = false;
				this.sortPrice = false;
				this.sortRating = false;

				if(sort == 'popularity') {
					this.sortPopularity = true;
				} else if(sort == 'price') {
					this.sortPrice = true;
				} else {
					this.sortRating = true;
				}

				// broadcast the event to the child component listener
				this.$broadcast('sortListener', sort);
			},

			// disable a sort
			removeSort: function() {
				// chain these to set all them to false
				this.sortPopularity = this.sortPrice = this.sortRating = false;

				// broadcast the event to the child component listener
				this.$broadcast('removeSortListener', [this.sortPopularity, this.sortPrice, this.sortRating]);
			},

			/*
			|--------------------------------------------------------------------------
			| Filter broadcast methods / array builders
			|--------------------------------------------------------------------------
			|
			| These methods broadcast an array of filter items to the elasticsearch
			| query builder.
			|
			*/

			countryFilter: function(country) {
				index = this.countriesToFilter.indexOf(country)

				// if object is in the array already then removeit , otherwise add it
				if(index > -1) {
					this.countriesToFilter.splice(index, 1);
				} else {
					this.countriesToFilter.push(country);
				}

				// broadcast the event to the child component listener
				this.$broadcast('countryListener', this.countriesToFilter);
			},

			boardFilter: function(board) {
				index = this.boardsToFilter.indexOf(board)

				// if object is in the array already then removeit , otherwise add it
				if(index > -1) {
					this.boardsToFilter.splice(index, 1);
				} else {
					this.boardsToFilter.push(board);
				}

				// broadcast the event to the child component listener
				this.$broadcast('boardListener', this.boardsToFilter);
			},

			accommodationFilter: function(accommodation) {
				index = this.accommodationsToFilter.indexOf(accommodation)

				// if object is in the array already then removeit , otherwise add it
				if(index > -1) {
					this.accommodationsToFilter.splice(index, 1);
				} else {
					this.accommodationsToFilter.push(accommodation);
				}

				// broadcast the event to the child component listener
				this.$broadcast('accommodationListener', this.accommodationsToFilter);
			},

			durationFilter: function(duration) {
				index = this.durationsToFilter.indexOf(duration)

				// if object is inteh array already then removeit , otherwise add it
				if(index > -1) {
					this.durationsToFilter.splice(index, 1);
				} else {
					this.durationsToFilter.push(duration);
				}

				// broadcast the event to the child component listener
				this.$broadcast('durationListener', this.durationsToFilter);
			},
			search: function(event) {
				// redirect if we get a query on this method call while we are not on the homepage
				if(this.query && window.location.pathname != "/" ) {
					window.location.href = '/?search=' + this.query;
				} else {
					// broadcast the event to the child component listener
					this.$broadcast('searchListener', this.query);

					window.scrollTo(0, $("#main-search").offset().top);

					this.query = '';

					// focus on the main search input
					$(".elasticsearch-input").focus();
				}
			}
		}
	})
});
