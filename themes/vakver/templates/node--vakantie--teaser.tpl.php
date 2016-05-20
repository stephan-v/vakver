<div class="col-md-4">
	<div class="vacation-item">
		<a href="#">
			<div class="placeholder-img" style="background-image: url('http://vakver.dev/sites/vakver.dev/files/accommodatie_1_104.jpg');">
				<div class="star-rating">
					<i class="fa fa-star fa-lg" aria-hidden="true" v-for="index in <?php print $node->field_stars['und'][0]['value']; ?>"></i>
				</div><!-- /.star-rating -->
				<div class="pricing">&euro; <?php print $node->field_price['und'][0]['value']; ?></div><!-- /.pricing -->
			</div><!-- /.placeholder-img -->

			<div class="content">
				<h2><?php print $node->title; ?></h2>
				<p><?php print text_summary($node->body['und'][0]['value'], NULL, 100); ?>...</p>
			</div><!-- /.content -->
		</a>
	</div><!-- /.vacation-item -->
</div><!-- /.col-md-4 -->