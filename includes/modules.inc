<?php
// $Id$

/**
 * @file
 * Setup Extra Modules
 * 
 * This is where to add extra modules and features for custom install profiles
 * 
 */

function _jetset_extra_modules() {
  $custommodules = array(
    'skinr',
    'override_node_options',
    'logintoboggan',
    'menu_editor',
    'better_formats',
    'nodeformsettings',
    'search404',
    'captcha',
    'css_captcha',
    'pathauto',
    'context_ui',

    // CCK
    'fieldgroup',
    'text',
    'filefield',
    'imagefield',
    'optionwidgets',
    'link',
    
    // Dates
    'calendar',
    'date_api',
    'date_timezone',
    'date',
    'date_popup',
    'date_tools',

    // User Relationships
    'user_relationships_api',
    'user_relationships_ui',
    'user_relationship_views',
    'user_relationships_rules',
    'user_relationship_blocks', 
    'user_relationship_elaborations',
    'user_relationship_mailer',
         
    // Images
    'imageapi',
    'imagecache',
    'imageapi_gd',
    'imagecache_profiles',
    'imagecache_ui',
    'imagecache_canvasactions',

    // Messaging
    'messaging', 
    'messaging_mail',
    'messaging_simple',

    // Notifications
    'notifications',
    'notifications_autosubscribe',
    'notifications_content',
    'notifications_ui', 
    'notifications_views',

    // Heartbeat Activity Stream
    'heartbeat',
    'heartbeat_views',
    'hrules',
    'friendlist_activity',

    // Rules
    'rules', 
    'rules_admin',

    // Shoutbox
    'shoutbox',

    // Editor
    'wysiwyg',
    'better_formats',
    'insert',

    // Add more modules if necessary


    // Features
      'pilot_image_engine',
      'pilot_news_engine',
      'pilot_events_engine',

  );
  return $custommodules;
}
