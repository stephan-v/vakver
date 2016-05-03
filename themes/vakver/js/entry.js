var Vue 			= require('vue');
var Elasticsearch 	= require('./components/elasticsearch.vue')

Vue.use(require('vue-resource'));
Vue.use(require('vue-chunk'));

// Globally register the component with tag: my-component
Vue.component('elasticsearch', Elasticsearch)

window.onload = function () {
	// create a root instance
	new Vue({
	  el: 'body',
	  data: {
	  	hits: ''
	  },
	  events: {
	  	'travel-hits': function(hits) {
	  		this.hits = hits;
	  	}
	  },
	  methods: {
	  	filterStars: function(rating) {
	  		this.$broadcast('filter-stars', rating);
	  	}
	  }
	})
}