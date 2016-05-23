<?php

/**
 * @file
 * template.php
 */

// Helper function to load all field collections from a node field, ex. $node->field_fc_name
function field_collection_load_multiple($field) {
	// Retreive ID's from field
	$ids = array();
	foreach ($field as $field_item) {
	    $ids[] = $field_item['value'];
	}
	// Load all field collection items
	return field_collection_item_load_multiple($ids);
}

function vakver_preprocess_html(&$variables) {
    drupal_add_css('https://fonts.googleapis.com/css?family=Oxygen:400,300,700', array('type' => 'external'));
    drupal_add_css('https://fonts.googleapis.com/css?family=Kaushan+Script', array('type' => 'external'));
}

function vakver_preprocess_node(&$vars) {
  if($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';   
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
  }
}