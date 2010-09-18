<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ca_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function ca_news_imagecache_default_presets() {
  $items = array(
    'ca_news_preview' => array(
      'presetname' => 'ca_news_preview',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '600',
            'height' => '600',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'ca_news_thumb' => array(
      'presetname' => 'ca_news_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '200',
            'height' => '200',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function ca_news_node_info() {
  $items = array(
    'ca_news' => array(
      'name' => t('News'),
      'module' => 'features',
      'description' => t('Publish new news articles and control users who can publish it.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'has_body' => '1',
      'body_label' => t('Article'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function ca_news_views_api() {
  return array(
    'api' => '2',
  );
}
