<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php $count = 0; ?>

<?php foreach ($rows as $id => $row): ?>
	<?php if($count === 0): ?>
		<div class="row">
	<?php elseif($count % 4 === 0): ?>
		</div><div class="row"><!-- /.row -->
	<?php endif; ?>

    <?php print $row; ?>

	<?php if($count === count($rows) && $count % 4 !== 0): ?>
		</div><!-- /.row -->
	<?php endif; ?>

	<?php $count++; ?>

<?php endforeach; ?>
