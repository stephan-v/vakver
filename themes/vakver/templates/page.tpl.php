<div id="page">	
	<nav class="navbar navbar-default">
		<form class="navbar-form" role="search" v-on:submit.prevent="search($event)">
			<div class="form-group">
				<input type="text" class="form-control" placeholder="Vakantie zoeken" v-model="query">
			</div><!-- /.form-group -->
		</form>

		<div class="container">
			<!-- Brand and toggle get grouped for better mobile display -->
			<div class="navbar-header">
				<a class="logo" href="<?php print url('<front>'); ?>">Vakver.nl</a>
			</div><!-- /.navbar-header -->

	
			<div id="main-menu">
				<?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('nav', 'navbar-nav', 'navbar-right')))); ?>
			</div>
		
		</div><!-- /.container-->

	    <div class="search">
			<svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
				 width="133px" height="149px" viewBox="0 0 133 149" enable-background="new 0 0 133 149" xml:space="preserve">
				<polygon fill="#F7CE45" points="0,0 133,0 133,149 38.5,77 "/>
			</svg>
			<i class="fa fa-search fa-2x" aria-hidden="true"></i>
    	</div><!-- /.search -->
	</nav> <!-- /.navbar -->
	
	<?php if ($breadcrumb): ?>
		<div id="breadcrumb"><?php // print $breadcrumb; ?></div>
	<?php endif; ?>
	
	<div class="container">
		<?php //print $messages; ?>
	</div><!-- /.container -->

	<?php if(drupal_is_front_page()): ?>
		<?php require("frontpage.tpl.php"); ?>
	<?php else: ?>
		<?php print render($page['content']); ?>
	<?php endif; ?>

	<?php if ($page['sidebar_first']): ?>
		<div id="sidebar-first" class="column sidebar">
			<?php print render($page['sidebar_first']); ?>
		</div> <!-- /#sidebar-first -->
	<?php endif; ?>
	
	<div id="footer">
		<div class="newsletter">
			<div class="container">
				<div class="row">
					<div class="col-md-6">
						<p>Meld je aan voor onze nieuwsbrief en blijf op hoogte van de laatste aanbiedingen</p>
					</div><!-- /.col-md-6 -->

					<div class="col-md-6">
						<?php print render($page['subscription']); ?>
					</div><!-- /.col-md-6 -->
				</div><!-- /.row -->
			</div><!-- /.container -->
		</div><!-- /.newsletter -->

		<div class="main-content">
			<div class="container">
				<div class="row">
					<div class="col-md-3">
						<a class="logo" href="<?php print url('<front>'); ?>">Vakver.nl</a>
						<p>Vakver.nl is een onafhankelijke reissite. Wij vergelijken prijzen van bekende reisaanbieders voor de goedkoopste vakantiebestemmingen.</p>
					</div><!-- /.col-md-4 -->

					<div class="col-md-2 col-md-offset-1">
						<h3>Menu</h3>
						<?php
							$menu = menu_navigation_links('menu-footermenu');
							print theme('links__menu_your_custom_menu_footermenu', array('links' => $menu, 'attributes' => array('class' => array('menu-list'))));
						?>
					</div><!-- /.col-md-2 -->

					<div class="col-md-2">
						<h3>Menu</h3>
						<?php
							$menu = menu_navigation_links('menu-footermenu2');
							print theme('links__menu_your_custom_menu_footermenu2', array('links' => $menu, 'attributes' => array('class' => array('menu-list'))));
						?>
					</div><!-- /.col-md-2 -->

					<div class="col-md-4 contact">
						<h3>Contact</h3>
						<p>Heeft u vragen of opmerkingen? U kunt contact met ons opnemen <a href="/contact">via dit contactformulier.</a></p>
						<a href="https://twitter.com/vak_ver" target="_blank" class="social-link">
							<i class="fa fa-twitter-square fa-2x" aria-hidden="true"></i>
						</a>
						<a href="https://www.facebook.com/vakver/" target="_blank" class="social-link">
							<i class="fa fa-facebook-square fa-2x" aria-hidden="true"></i>
						</a>
					</div><!-- /.col-md-4 -->
				</div><!-- /.row -->
			</div><!-- /.container -->

			<img src="/<?php print path_to_theme(); ?>/img/palm.png" alt="" class="palm">
		</div><!-- /.main-content -->

		<div class="lower-footer text-center">
			<p>Wij verkopen zelf geen reizen, maar helpen u bij het vinden van de goedkoopste aanbieder voor uw zonvakantie.</p>
		</div><!-- /.lower-footer -->
	</div> <!-- /#footer -->

</div> <!-- /#page-wrapper -->
