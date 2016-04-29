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
					<div class="placeholder-img" style="background-image: url({{ travel._source.field_image[0].url }})">
						<div class="star-rating">
							<i class="fa fa-star fa-lg" aria-hidden="true" v-for="star in parseInt(travel._source.stars[0].value)"></i>
						</div><!-- /.star-rating -->
					</div><!-- /.placeholder-img -->

					<div class="content">
						<h2 v-if="travel.highlight">{{{ travel.highlight.title }}}</h2>
						<h2 v-else>{{{ travel._source.title }}}</h2>
						<p>{{ travel._source.body[0].value }}</p>
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
						<div class="placeholder-img" style="background-image: url({{ travel._source.field_image[0].url }})">

						</div><!-- /.placeholder-img -->
					</div><!-- /.col-md-3 -->

					<div class="col-md-9">
						<div class="content">
							<h2 v-if="travel.highlight">{{{ travel.highlight.title }}}</h2>
							<h2 v-else>{{{ travel._source.title }}}</h2>
							<p>{{ travel._source.body[0].value }}</p>
						</div><!-- /.content -->
					</div><!-- /.col-md-9 -->
				</div><!-- /.vacation-item -->
			</a>
		</div><!-- /.col-md-3 -->
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
			toggleView: true
		}
	},
	methods: {
		search: function() {
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
					this.$dispatch('travel-hits', this.travels.length)
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			} else {
				this.client.search({
						index: 'node',
						type: 'vakantie',
						from: 0,
  						size: 12,
				}).then(function (resp) {
					this.travels = resp.hits.hits;

					// dispatch this data to the entry.js file
					this.$dispatch('travel-hits', this.travels.length)
				}.bind(this), function (err) {
					console.trace(err.message);
				});
			}
		}
	}
}
</script>