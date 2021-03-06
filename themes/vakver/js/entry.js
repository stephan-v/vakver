var Vue 			= require('vue');
var Vuex 			= require('vuex');
var lazyload 		= require('vue-lazyload');
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
Vue.use(lazyload, {
  error: 'dist/error.png',
  loading: Drupal.settings.pathToTheme + '/img/ripple.gif',
  try: 3 // default 1 
});

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
			ratings: [],

			// array of unique countries to build a sidebar list
			countries: [],

			// set of countries display first
			customCountries: [],

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

			// array of unique accommodations to build a sidebar list
			transportations: [],

			// array of accommodations to filter(sent to the child component)
			transportationsToFilter: [],

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
			'sort-order': function(sortOrder, filterName) {
				if(filterName == 'rating') {
					this.sortRatingDesc = sortOrder;
				} else {
					this.sortPriceDesc = sortOrder;
				}
			},
			'unique-countries': function(countries) {
				// shorten this name since it's too long for the sidebar
				for(var i = 0, len = countries.length; i < len; i++) {
					if(countries[i].key === 'Verenigde Arabische Emiraten') {
						countries[i].key = 'Ver. Arabische Emiraten';
					}
				}

				// custom countries that sit at the top of the filter
				this.customCountries = countries.filter(function(country) {
				    return ["Spanje","Griekenland", "Italië", "Turkije", "Frankrijk"].indexOf(country.key) != -1
				});

				// find and replace lange landnamen
				this.countries = countries;

				// only launch readmore functionality after data has finished loading
				this.finishRender();
			},
			'unique-accommodations': function(accommodations) {
				this.accommodations = accommodations;

				// only launch readmore functionality after data has finished loading
				this.finishRender();
			},
			'unique-transportations': function(transportations) {
				this.transportations = transportations;

				// only launch readmore functionality after data has finished loading
				this.finishRender();
			},
			'unique-boards': function(boards) {
				// remove these elements from the array and filter sidebar - needs to be extremely specific with caps
				for (var i = 0, len = boards.length; i < len; i++) {
					if(boards[i].key === "volgens beschrijving") {
				        boards.splice(i, 1);
				        break;
				    }
				}

				// remove these elements from the array and filter sidebar - needs to be extremely specific with caps
				for (var i = 0, len = boards.length; i < len; i++) {
					if(boards[i].key === "Lookup_VERZORGING_T_1") {
				        boards.splice(i, 1);
				        break;
				    }
				}

				this.boards = boards;

				// only launch readmore functionality after data has finished loading
				this.finishRender();
			},
			'unique-durations': function(durations) {
				this.durations = durations;

				// only launch readmore functionality after data has finished loading
				this.finishRender();
			}
		},
		methods: {
			/*
			|--------------------------------------------------------------------------
			| Filter broadcast methods / array builders
			|--------------------------------------------------------------------------
			|
			| These methods broadcast an array of filter items to the elasticsearch
			| query builder.
			|
			*/
		
			filter: function(itemToFilter, singular, plural) {
				// dynamically assign the property to call
				var whatToFilter = plural + 'ToFilter';

    			var index = this[whatToFilter].indexOf(itemToFilter);

    			// if object is in the array already then removeit , otherwise add it
				if(index > -1) {
					this[whatToFilter].splice(index, 1);
				} else {
					this[whatToFilter].push(itemToFilter);
				}

				// broadcast the event to the child component listener
				this.$broadcast('filterListener', this[whatToFilter], plural);
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
			},

			/*
			|--------------------------------------------------------------------------
			| Waits for data to finish loading before executing whatever is in here
			|--------------------------------------------------------------------------
			|
			| This is required so the height for a sidebar filter is set first
			| Otherwise the readmore functionality won't work properly.
			|
			*/

			finishRender: function() {
				Vue.nextTick(function(){
				    $('.filter .readmore').readmore({
						moreLink: '<a href="#" class="show-more">Toon alles</a>',
						lessLink: '<a href="#" class="show-more">Toon minder</a>',
						collapsedHeight: 90,
						speed: 1000
					});
				});
			}
		}
	})
});
