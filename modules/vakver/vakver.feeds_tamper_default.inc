<?php
/**
 * @file
 * vakver.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function vakver_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'd_reizen-blank_country_of_destination_1-code_to_country';
  $feeds_tamper->importer = 'd_reizen';
  $feeds_tamper->source = 'Blank country_of_destination 1';
  $feeds_tamper->plugin_id = 'code_to_country';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert ISO code to country';
  $export['d_reizen-blank_country_of_destination_1-code_to_country'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'd_reizen-blank_country_of_destination_1-copy';
  $feeds_tamper->importer = 'd_reizen';
  $feeds_tamper->source = 'Blank country_of_destination 1';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'country_of_destination',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Copy source value';
  $export['d_reizen-blank_country_of_destination_1-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'd_reizen-img_medium-find_replace';
  $feeds_tamper->importer = 'd_reizen';
  $feeds_tamper->source = 'img_medium';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '380-285/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['d_reizen-img_medium-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'd_reizen-img_medium-find_replace_regex';
  $feeds_tamper->importer = 'd_reizen';
  $feeds_tamper->source = 'img_medium';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\/\\//',
    'replace' => 'http://',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['d_reizen-img_medium-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'd_reizen2-blank_country_of_destination_1-code_to_country';
  $feeds_tamper->importer = 'd_reizen2';
  $feeds_tamper->source = 'Blank country_of_destination 1';
  $feeds_tamper->plugin_id = 'code_to_country';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert ISO code to country';
  $export['d_reizen2-blank_country_of_destination_1-code_to_country'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'd_reizen2-blank_country_of_destination_1-copy';
  $feeds_tamper->importer = 'd_reizen2';
  $feeds_tamper->source = 'Blank country_of_destination 1';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'country_of_destination',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Copy source value';
  $export['d_reizen2-blank_country_of_destination_1-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'd_reizen2-img_medium-find_replace';
  $feeds_tamper->importer = 'd_reizen2';
  $feeds_tamper->source = 'img_medium';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '380-285/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['d_reizen2-img_medium-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'd_reizen2-img_medium-find_replace_regex';
  $feeds_tamper->importer = 'd_reizen2';
  $feeds_tamper->source = 'img_medium';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\/\\//',
    'replace' => 'http://',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['d_reizen2-img_medium-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'elizawashere-blank_country-copy';
  $feeds_tamper->importer = 'elizawashere';
  $feeds_tamper->source = 'Blank country';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'country',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Copy source value';
  $export['elizawashere-blank_country-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'elizawashere-blank_country-country_to_code';
  $feeds_tamper->importer = 'elizawashere';
  $feeds_tamper->source = 'Blank country';
  $feeds_tamper->plugin_id = 'country_to_code';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert country to ISO code';
  $export['elizawashere-blank_country-country_to_code'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'elizawashere-imageurl-find_replace';
  $feeds_tamper->importer = 'elizawashere';
  $feeds_tamper->source = 'imageURL';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'width=264&height=176',
    'replace' => 'width=1024&height=525',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['elizawashere-imageurl-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tjingo-blank_country_of_destination_1-code_to_country';
  $feeds_tamper->importer = 'tjingo';
  $feeds_tamper->source = 'Blank country_of_destination 1';
  $feeds_tamper->plugin_id = 'code_to_country';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert ISO code to country';
  $export['tjingo-blank_country_of_destination_1-code_to_country'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tjingo-blank_country_of_destination_1-copy';
  $feeds_tamper->importer = 'tjingo';
  $feeds_tamper->source = 'Blank country_of_destination 1';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'country_of_destination',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Copy source value';
  $export['tjingo-blank_country_of_destination_1-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tjingo-img_medium-find_replace';
  $feeds_tamper->importer = 'tjingo';
  $feeds_tamper->source = 'img_medium';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'http://media.tjingo.nl/imagecache/?image=',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['tjingo-img_medium-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tjingo-img_medium-remove_prefix';
  $feeds_tamper->importer = 'tjingo';
  $feeds_tamper->source = 'img_medium';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'http://media.tjingo.nl/imagecache/?image=',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Remove imagecache prefixer';
  $export['tjingo-img_medium-remove_prefix'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'tjingo-img_medium-required';
  $feeds_tamper->importer = 'tjingo';
  $feeds_tamper->source = 'img_medium';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Verplicht veld';
  $export['tjingo-img_medium-required'] = $feeds_tamper;

  return $export;
}
