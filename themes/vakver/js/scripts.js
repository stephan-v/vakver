(function($) {
	$( document ).ready(function() {
		
		/* ==========================================================================
		Global
		========================================================================== */
		
		// Remove error style on focus
		$('.form-item .error').focus(function() {
			$(this).removeClass('error');
		});

		/* ==========================================================================
		Navigation search input
		========================================================================== */
		$(".navbar-form input").focus(function() {
			$(this).addClass('expand');

			// on removal of the inputs focus
			$(this).blur(function() {
				$(this).removeClass('expand');
			});
		});

		$(".search").click(function() {
			$(".navbar-form input").addClass('expand').focus();
		});

		/* ==========================================================================
		Readmore functionality
		========================================================================== */

		// sloppy hotfix
		setTimeout(function() {
			$('.filter .readmore').readmore({
				moreLink: '<a href="#" class="show-more">Toon alles</a>',
				lessLink: '<a href="#" class="show-more">Toon minder</a>',
				collapsedHeight: 90,
				speed: 1000
			});
		}, 500);

		// without timeout
		$('.agency-content .readmore').readmore({
			moreLink: '<a href="#" class="show-more">a</a>',
			lessLink: '<a href="#" class="show-more">a</a>',
			collapsedHeight: 100,
			speed: 1000
		});

		/* ==========================================================================
		Show / Hide mobile filter sidebar
		========================================================================== */
		
		$(".fa-filter").click(function() {
			$("aside").toggleClass("active");
		});

		/* ==========================================================================
		noui Slider
		========================================================================== */

		setTimeout(function() {
			// round down and up to the nearest 100 for the slider range to look a little more neat
			var min_price = Math.floor(Vue.$children[0].priceMinMax.min_price.value/100)*100;
			var max_price = Math.ceil(Vue.$children[0].priceMinMax.max_price.value/100)*100;

			var slider = document.getElementById('slider-handles');

			noUiSlider.create(slider, {
				start: [min_price, max_price],
				step: 50,
				range: {
					'min': [min_price],
					'max': [max_price]
				}
			});

			var marginMin = document.getElementById('slider-margin-value-min'),
				marginMax = document.getElementById('slider-margin-value-max');

			slider.noUiSlider.on('update', function ( values, handle ) {
				if ( handle ) {
					var values = values.map(function (x) { 
					    return parseInt(x, 10); 
					});

					Vue.$broadcast('priceListener', values);

					marginMax.innerHTML = values[handle];
				} else {
					var values = values.map(function (x) { 
					    return parseInt(x, 10); 
					});
					
					Vue.$broadcast('priceListener', values);

					marginMin.innerHTML = values[handle];
				}
			});
		}, 500);
	});
}(jQuery));