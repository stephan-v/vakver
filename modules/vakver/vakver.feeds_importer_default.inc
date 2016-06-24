<?php
/**
 * @file
 * vakver.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function vakver_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'd_reizen';
  $feeds_importer->config = array(
    'name' => 'D-reizen',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'img_medium',
            'target' => 'field_image:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'stars',
            'target' => 'field_stars',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'city_of_destination',
            'target' => 'field_city',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'region_of_destination',
            'target' => 'field_region',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'link',
            'target' => 'field_url:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'minimum_price',
            'target' => 'field_price',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'country_of_destination',
            'target' => 'field_country_iso',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Blank country_of_destination 1',
            'target' => 'field_country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Blank travel_agency',
            'target' => 'field_travel_agency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'category',
            'target' => 'field_board_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'duration',
            'target' => 'field_duration',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'accommodation_type',
            'target' => 'field_accommodation',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'transportation_type',
            'target' => 'field_transportation',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'vakantie',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['d_reizen'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'elizawashere';
  $feeds_importer->config = array(
    'name' => 'Elizawashere',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'price',
            'target' => 'field_price',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'stars',
            'target' => 'field_stars',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'country',
            'target' => 'field_country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'region',
            'target' => 'field_region',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'city',
            'target' => 'field_city',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'imageURL',
            'target' => 'field_image:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'productURL',
            'target' => 'field_url:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Blank country',
            'target' => 'field_country_iso',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Blank travel_agency',
            'target' => 'field_travel_agency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'lodgement',
            'target' => 'field_board_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'transportation_type',
            'target' => 'field_transportation',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'vakantie',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['elizawashere'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'tjingo';
  $feeds_importer->config = array(
    'name' => 'Tjingo',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'link',
            'target' => 'field_url:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'stars',
            'target' => 'field_stars',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'minimum_price',
            'target' => 'field_price',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'city_of_destination',
            'target' => 'field_city',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'region_of_destination',
            'target' => 'field_region',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'img_medium',
            'target' => 'field_image:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'country_of_destination',
            'target' => 'field_country_iso',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Blank country_of_destination 1',
            'target' => 'field_country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Blank travel_agency',
            'target' => 'field_travel_agency',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'board_type',
            'target' => 'field_board_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'duration',
            'target' => 'field_duration',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'accommodation_type',
            'target' => 'field_accommodation',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'vakantie',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['tjingo'] = $feeds_importer;

  return $export;
}
