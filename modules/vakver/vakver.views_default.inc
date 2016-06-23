<?php
/**
 * @file
 * vakver.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vakver_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Toepassen';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteren op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Startpunt';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« eerste';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'volgende ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'laatste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'blog';
  $translatables['blog'] = array(
    t('Master'),
    t('Blog'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteren op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Startpunt'),
    t('« eerste'),
    t('‹ vorige'),
    t('volgende ›'),
    t('laatste »'),
    t('Page'),
  );
  $export['blog'] = $view;

  $view = new view();
  $view->name = 'reisaanbieders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'reisaanbieders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'reisaanbieders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Toepassen';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteren op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Startpunt';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« eerste';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'volgende ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'laatste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sorteercriterium: Inhoud: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reisaanbieder' => 'reisaanbieder',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Veld: Inhoud: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['path'] = 'reisaanbieders';

  /* Display: Blok */
  $handler = $view->new_display('block', 'Blok', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Startpunt';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« eerste';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'volgende ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'laatste »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextueel filter: Inhoud: Travel agency (field_travel_agency) */
  $handler->display->display_options['arguments']['field_travel_agency_value']['id'] = 'field_travel_agency_value';
  $handler->display->display_options['arguments']['field_travel_agency_value']['table'] = 'field_data_field_travel_agency';
  $handler->display->display_options['arguments']['field_travel_agency_value']['field'] = 'field_travel_agency_value';
  $handler->display->display_options['arguments']['field_travel_agency_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_travel_agency_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_travel_agency_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_travel_agency_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_travel_agency_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_travel_agency_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_travel_agency_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vakantie' => 'vakantie',
  );
  /* Filtercriterium: Inhoud: Afbeelding (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  $translatables['reisaanbieders'] = array(
    t('Master'),
    t('reisaanbieders'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteren op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Startpunt'),
    t('« eerste'),
    t('‹ vorige'),
    t('volgende ›'),
    t('laatste »'),
    t('Page'),
    t('Blok'),
    t('Alle'),
  );
  $export['reisaanbieders'] = $view;

  $view = new view();
  $view->name = 'vacation_filter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Vakantiefilter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Toepassen';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteren op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Startpunt';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« eerste';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'volgende ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'laatste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Veld: Inhoud: Afbeelding */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Veld: Inhoud: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextueel filter: Inhoud: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_country_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_country_value']['limit'] = '0';
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vakantie' => 'vakantie',
  );
  /* Filtercriterium: Inhoud: Afbeelding (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_image_fid']['expose']['operator_id'] = 'field_image_fid_op';
  $handler->display->display_options['filters']['field_image_fid']['expose']['label'] = 'Image (field_image:fid)';
  $handler->display->display_options['filters']['field_image_fid']['expose']['operator'] = 'field_image_fid_op';
  $handler->display->display_options['filters']['field_image_fid']['expose']['identifier'] = 'field_image_fid';

  /* Display: vakanties/% */
  $handler = $view->new_display('page', 'vakanties/%', 'page_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextueel filter: Inhoud: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_country_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_country_value']['limit'] = '0';
  /* Contextueel filter: Inhoud: Region (field_region) */
  $handler->display->display_options['arguments']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['arguments']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['arguments']['field_region_value']['field'] = 'field_region_value';
  $handler->display->display_options['arguments']['field_region_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_region_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_region_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_region_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_region_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_region_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'vakanties/%';

  /* Display: vakanties/%/% */
  $handler = $view->new_display('page', 'vakanties/%/%', 'page_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextueel filter: Inhoud: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_country_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_country_value']['limit'] = '0';
  /* Contextueel filter: Inhoud: Region (field_region) */
  $handler->display->display_options['arguments']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['arguments']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['arguments']['field_region_value']['field'] = 'field_region_value';
  $handler->display->display_options['arguments']['field_region_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_region_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_region_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_region_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_region_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_region_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'vakanties/%/%';

  /* Display: vakanties/%/%/% */
  $handler = $view->new_display('page', 'vakanties/%/%/%', 'page_3');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextueel filter: Inhoud: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_country_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_country_value']['limit'] = '0';
  /* Contextueel filter: Inhoud: Region (field_region) */
  $handler->display->display_options['arguments']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['arguments']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['arguments']['field_region_value']['field'] = 'field_region_value';
  $handler->display->display_options['arguments']['field_region_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_region_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_region_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_region_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_region_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_region_value']['limit'] = '0';
  /* Contextueel filter: Inhoud: City (field_city) */
  $handler->display->display_options['arguments']['field_city_value']['id'] = 'field_city_value';
  $handler->display->display_options['arguments']['field_city_value']['table'] = 'field_data_field_city';
  $handler->display->display_options['arguments']['field_city_value']['field'] = 'field_city_value';
  $handler->display->display_options['arguments']['field_city_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_city_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_city_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_city_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_city_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_city_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'vakanties/%/%/%';
  $translatables['vacation_filter'] = array(
    t('Master'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteren op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Startpunt'),
    t('« eerste'),
    t('‹ vorige'),
    t('volgende ›'),
    t('laatste »'),
    t('Alle'),
    t('Image (field_image:fid)'),
    t('vakanties/%'),
    t('vakanties/%/%'),
    t('vakanties/%/%/%'),
  );
  $export['vacation_filter'] = $view;

  $view = new view();
  $view->name = 'vakantie';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Vakantie';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Toepassen';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteren op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Veld: Inhoud: Afbeelding */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Veld: Inhoud: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextueel filter: Inhoud: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_country_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_country_value']['limit'] = '0';
  /* Contextueel filter: Inhoud: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vakantie' => 'vakantie',
  );
  /* Filtercriterium: Inhoud: Afbeelding (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_image_fid']['expose']['operator_id'] = 'field_image_fid_op';
  $handler->display->display_options['filters']['field_image_fid']['expose']['label'] = 'Image (field_image:fid)';
  $handler->display->display_options['filters']['field_image_fid']['expose']['operator'] = 'field_image_fid_op';
  $handler->display->display_options['filters']['field_image_fid']['expose']['identifier'] = 'field_image_fid';

  /* Display: Gerelateerde vakanties */
  $handler = $view->new_display('block', 'Gerelateerde vakanties', 'block_1');
  $translatables['vakantie'] = array(
    t('Master'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteren op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Alle'),
    t('Image (field_image:fid)'),
    t('Gerelateerde vakanties'),
  );
  $export['vakantie'] = $view;

  return $export;
}
