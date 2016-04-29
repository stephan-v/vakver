<div id="page">	
	<nav class="navbar navbar-default">
		<div class="container-fluid">
			<div class="navbar-header">
				<div class="logo"></div>
		    </div><!-- /.navbar-header -->

		    <form class="navbar-form navbar-right" role="search">
				<div class="form-group">
					<input type="text" class="form-control" placeholder="Vakantie zoeken">
				</div><!-- /.form-group -->
			</form>

			<?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('nav', 'navbar-nav', 'navbar-right')))); ?>
		</div><!-- /.container-fluid -->

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
		<?php print $messages; ?>
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
		<?php print render($page['footer']); ?>
	</div> <!-- /#footer -->

</div> <!-- /#page-wrapper -->
