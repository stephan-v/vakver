<?php

/**
 * @file
 * Customize confirmation screen after successful submission.
 *
 * This file may be renamed "webform-confirmation-[nid].tpl.php" to target a
 * specific webform e-mail on your site. Or you can leave it
 * "webform-confirmation.tpl.php" to affect all webform confirmations on your
 * site.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $progressbar: The progress bar 100% filled (if configured). This may not
 *   print out anything if a progress bar is not enabled for this node.
 * - $confirmation_message: The confirmation message input by the webform
 *   author.
 * - $sid: The unique submission ID of this submission.
 */
?>
<div class="container confirmation-well">
	<div class="col-md-8 col-md-offset-2 well">
		<?php print $progressbar; ?>

		<div class="webform-confirmation">
		  <?php if ($confirmation_message): ?>
		    <?php print $confirmation_message ?>
		  <?php else: ?>
		    <p><?php print t('Thank you, your submission has been received.'); ?></p>
		  <?php endif; ?>
		</div>

		<div class="links">
		  <a href="<?php print url('node/'. $node->nid) ?>"><?php print t('Go back to the form') ?></a>
		</div>
		</div><!-- /.col-md-8 -->
</div><!-- /.container -->