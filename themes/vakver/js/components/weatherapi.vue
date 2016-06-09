<template>
	<div class="weather" v-if="currentTemp">
		<div class="current-weather">
			<h1>{{ currentTemp }}&deg;</h1>
		</div><!-- /.current-weather -->
		<ul class="forecast">
			<li v-for="forecast in dailyForecast">
				<div class="day">{{ getDay($index) }}</div>
				<img v-bind:src="'http://openweathermap.org/img/w/' + forecast.weather[0].icon + '.png'" alt="">
				<div class="temp">{{ Math.floor(forecast.temp.day) }}&deg;</div>
			</li>
		</ul>
	</div>
</template>

<script>
	export default {
		data: function () {
	        return {
	        	currentTemp: '',
	        	dailyForecast: []
	        };
	    },

		// declare the props
  		props: ['city', 'iso'],

		ready: function() {
			// 7 days weather forecast
			Vue.http.get('http://api.openweathermap.org/data/2.5/forecast/daily?q=' + this.city + ',' + this.iso + '&units=metric&lang=nl&mode=json&APPID=317947b4843d1f4de1eb935a78fe6554')
			.then(
				function(resp) {
					this.dailyForecast = resp.data.list;
				}.bind(this), function() {
					console.log(resp);
			});

			// current weather
			Vue.http.get('http://api.openweathermap.org/data/2.5/weather?q=' + this.city + ',' + this.iso + '&units=metric&lang=nl&mode=json&APPID=317947b4843d1f4de1eb935a78fe6554')
			.then(
				function(resp) {
					this.currentTemp = Math.floor(resp.data.main.temp);
				}.bind(this), function() {
					console.log(resp);
			});
		},

		methods: {
			getDay: function(index) {
				// +1 to the index to start at the day of tomorrow instead of today
				return this.capitalizeFirstLetter(moment().add(index + 1, 'days').format('dddd'));
			},

			capitalizeFirstLetter: function(string) {
			    return string.charAt(0).toUpperCase() + string.slice(1);
			}
		}
	}
</script>