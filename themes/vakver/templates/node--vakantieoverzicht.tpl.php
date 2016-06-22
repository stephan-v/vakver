<div class="container filter-overzicht">
	<div class="col-md-12 text-center">
		<h1 class="overview-heading">Reizen - <?php print $title; ?></h1>
	</div><!-- /.col-md-12 -->

	<div class="col-md-8 col-md-offset-2">
		<div class="country-content">
			<?php print render($content['body']); ?>
		</div><!-- /.country-content -->
	</div><!-- /.col-md-12 -->

	<div class="col-md-12">
		<?php print views_embed_view('vacation_filter', $display_id = 'default', $field_country[0]['value']); ?>
	</div><!-- /.col-md-12 -->
</div><!-- /.container -->