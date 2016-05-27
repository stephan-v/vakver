var Vue 			= require('vue');
var Elasticsearch 	= require('./components/elasticsearch.vue')
var WeatherAPI 		= require('./components/weatherapi.vue')

// moment.js settings(timehelper)
var moment 			= require('moment');
require('moment/locale/nl');
global.moment 		= moment;

Vue.use(require('vue-resource'));
Vue.use(require('vue-chunk'));

Vue.config.debug = true;

// Globally register the component with tag: my-component
Vue.component('elasticsearch', Elasticsearch);
Vue.component('weatherapi', WeatherAPI);

// give window access to the vue module, this is needed for the Vue resource to work with it in child components aswell
window.Vue = Vue;

window.onload = function () {
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
			countriesToFilter: []
		},
		watch: {
			'ratings': function() {
				this.$broadcast('ratingsListener', this.ratings);
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

			// helper function to capatilize the first letter of a string
			ucfirst: function(string) { 
			    return string.charAt(0).toUpperCase() + string.slice(1).toLowerCase(); 
			},

			countryFilter: function(country) {
				index = this.countriesToFilter.indexOf(country)

				// if in array already remove, otherwise add
				if(index > -1) {
					this.countriesToFilter.splice(index, 1);
				} else {
					this.countriesToFilter.push(country);
				}

				// broadcast the event to the child component listener
				this.$broadcast('countryListener', this.countriesToFilter);
			}
		}
	})
}