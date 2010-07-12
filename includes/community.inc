<?php
// $Id$

/**
 * @file
 * Setup Community Features
 * 
 * 
 */

function _jetset_setup_community(&$context) {
  global $theme_key, $base_url;
  cache_clear_all();


// Configure user_relationships

  // Add initial relationship type 'Friend'
  $rel = new stdClass;
  $rel->name = t('Friend');
  $rel->plural_name = t('Friends');
  $rel->requires_approval = 1;
  $rel->expires_val = 0;
  $rel->is_oneway = 0;
  $rel->is_reciprocal = 0;

  // Save relationship
  drupal_write_record('user_relationship_types', $rel);

  // Alert other modules about the new relationship
  _user_relationships_invoke('insert', $rel, TRUE);

  // Refresh all available heartbeat streams
  // This registers the relational activity stream
  heartbeat_check_access_types();

  // Rebuild all available heartbeat message templates
  heartbeat_messages_rebuild();

  // Disable stream tabs on user profiles
 // $streams = variable_get('heartbeat_stream_data', '');

 // if ($streams) {
 //   foreach ($streams as $key => $value) {
 //     $streams[$key]['profile'] = 0;
 //   }

 //   variable_set('heartbeat_stream_data', $streams);
  // }


  $msg = st('Configured Blocks');
  _jetset_log($msg);
  $context['message'] = $msg;
}
