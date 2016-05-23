<div id="page">	
	<nav class="navbar navbar-default">
		<form class="navbar-form" role="search">
			<div class="form-group">
				<input type="text" class="form-control" placeholder="Vakantie zoeken">
			</div><!-- /.form-group -->
		</form>

		<div class="container">
			<!-- Brand and toggle get grouped for better mobile display -->
			<div class="navbar-header">
				<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
					<span class="sr-only">Toggle navigation</span>
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
				</button>
				<a class="logo" href="<?php print url('<front>'); ?>">Vakver.nl</a>
			</div><!-- /.navbar-header -->

			<!-- Collect the nav links, forms, and other content for toggling -->
	    	<div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
				<?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('nav', 'navbar-nav', 'navbar-right')))); ?>
			</div><!-- collapse -->
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
						<div class="input-group">
							<input type="text" class="form-control" placeholder="E-mail invullen" aria-describedby="basic-addon2">
							<span class="input-group-addon" id="basic-addon2">aanmelden</span>
						</div><!-- /.input-group -->
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
						<ul class="menu-list">
							<li><a href="#">Reizen</a></li>
							<li><a href="#">Mijn bestemmingen</a></li>
							<li><a href="#">Reisorganisaties</a></li>
							<li><a href="#">Blog</a></li>
							<li><a href="#">Inloggen</a></li>
						</ul><!-- /.menu-list -->
					</div><!-- /.col-md-2 -->

					<div class="col-md-2">
						<h3>Menu</h3>
						<ul class="menu-list">
							<li><a href="#">Privacy</a></li>
							<li><a href="#">Disclaimer</a></li>
						</ul><!-- /.menu-list -->
					</div><!-- /.col-md-2 -->

					<div class="col-md-4 contact">
						<h3>Contact</h3>
						<p>Heeft u vragen of opmerkingen? U kunt contact met ons opnemen <a href="#">via dit contactformulier.</a></p>
					</div><!-- /.col-md-4 -->
				</div><!-- /.row -->
			</div><!-- /.container -->

			<img src="<?php print path_to_theme(); ?>/img/palm.png" alt="" class="palm">
		</div><!-- /.main-content -->

		<div class="lower-footer text-center">
			<p>Wij verkopen zelf geen reizen, maar helpen u bij het vinden van de goedkoopste aanbieder voor uw zonvakantie.</p>
		</div><!-- /.lower-footer -->

		<?php print render($page['footer']); ?>
	</div> <!-- /#footer -->

</div> <!-- /#page-wrapper -->
