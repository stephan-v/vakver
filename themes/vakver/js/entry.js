var Vue 			= require('vue');
var Elasticsearch 	= require('./components/elasticsearch.vue')

Vue.use(require('vue-resource'));
Vue.use(require('vue-chunk'));

// Globally register the component with tag: my-component
Vue.component('elasticsearch', Elasticsearch)

window.onload = function () {
	// create a root instance
	var vue = new Vue({
		el: 'body',
		data: {
			hits: '',
			ratings: []
		},
		watch: {
			'ratings': function() {
				this.$broadcast('receiveRatings', this.ratings);
			}
		},
		events: {
			'travel-hits': function(hits) {
				this.hits = hits;
			}
		}
	})
}