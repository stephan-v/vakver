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
	});
}(jQuery));