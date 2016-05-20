<?php
/**
 * @file
 * vakver.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vakver_taxonomy_default_vocabularies() {
  return array(
    'landen' => array(
      'name' => 'Landen',
      'machine_name' => 'landen',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
