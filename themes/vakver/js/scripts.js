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
				collapsedHeight: 85,
				speed: 1000
			});
		}, 1000);

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
	});
}(jQuery));