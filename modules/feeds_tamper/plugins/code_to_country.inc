<?php

/**
 * @file
 * Convert a country name to ISO code.
 */

$plugin = array(
  'form' => 'feeds_tamper_code_to_country_form',
  'callback' => 'feeds_tamper_code_to_country_callback',
  'name' => 'ISO code to Country',
  'multi' => 'loop',
  'category' => 'Other',
  'default description' => 'Convert ISO code to country',
);

function feeds_tamper_code_to_country_form($importer, $element_key, $settings) {
  $form = array();
  $form['help'] = array(
    '#markup' => t('Converts this field from a two character ISO 3166-1 alpha-2 code to a country name string.'),
  );
  return $form;
}

// Custom plugin code for the vakver.nl feed
function feeds_tamper_code_to_country_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  include_once DRUPAL_ROOT . '/includes/locale.inc';

  // set an empty array but only on the first call of this function(static)
  static $countries = array();

  if (empty($countries)) {
    $countries = country_get_list();
  }

  // If it's already a valid country code, leave it alone.
  if (in_array($field, $countries)) {
    return;
  }

  // Trim whitespace ($field is ISO code)
  $iso_code = trim($field);
  if (isset($countries[$iso_code])) {
    $field = $countries[$iso_code];
  }
  else {
    // If country name cannot be found, return nothing.
    $field = '';
  }
}

/**
 * Callback for array_walk().
 */
function _feeds_tamper_code_to_country_strtolower(&$word) {
  $word = drupal_strtolower($word);
}
