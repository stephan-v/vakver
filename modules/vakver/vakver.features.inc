<?php
/**
 * @file
 * vakver.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vakver_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "elasticsearch_connector" && $api == "elasticsearch_connector_defaults") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vakver_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function vakver_image_default_styles() {
  $styles = array();

  // Exported image style: blogpost.
  $styles['blogpost'] = array(
    'label' => 'Blogpost',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 450,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blur.
  $styles['blur'] = array(
    'label' => 'Blur',
    'effects' => array(
      1 => array(
        'name' => 'canvasactions_blur',
        'data' => array(
          'intensity' => 10,
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1920,
          'height' => 500,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: fullsize.
  $styles['fullsize'] = array(
    'label' => 'fullsize',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function vakver_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Een blogpost'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'homepage' => array(
      'name' => t('Homepage'),
      'base' => 'node_content',
      'description' => t('Van deze inhoudstype bestaat nogmaals gesproken maar 1 pagina. Aanmaken of verwijderen kan in de meeste gevallen alleen door een developer gedaan worden.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Pagina'),
      'base' => 'node_content',
      'description' => t('Dit inhoudstype is te gebruiken voor bijvoorbeeld \'Over ons\' en kan in het menu geplaatst kan worden.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'reisaanbieder' => array(
      'name' => t('Reisaanbieder'),
      'base' => 'node_content',
      'description' => t('Een overzichtspagina voor een reisaanbieder'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'vakantie' => array(
      'name' => t('vakantie'),
      'base' => 'node_content',
      'description' => t('Vakantie'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function vakver_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : null,
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : { "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] } },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\nh2 = 3\\nh3 = 2\\nstrong = 2\\nb = 2\\nem = 1.5\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "promote" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "0",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function vakver_default_search_api_server() {
  $items = array();
  $items['elasticsearch_server'] = entity_import('search_api_server', '{
    "name" : "elasticsearch_server",
    "machine_name" : "elasticsearch_server",
    "description" : "",
    "class" : "search_api_elasticsearch_connector",
    "options" : { "cluster" : "elasticsearch", "facet_limit" : 10 },
    "enabled" : "1"
  }');
  return $items;
}
