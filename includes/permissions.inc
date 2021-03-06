<?php
// $Id$

/**
 * @file
 * Sets up User Roles and Configures Permissions
 *
 * can be customised
 */

function _jetset_set_permissions(&$context) {

  // First set up roles

  // Make sure default roles are set right (just in case)
  db_query("UPDATE {role} SET rid = 1 WHERE name = 'anonymous user'");
  db_query("UPDATE {role} SET rid = 2 WHERE name = 'authenticated user'");


  $sitemgr_rid = install_add_role('site manager');
  $communitymanager_rid = install_add_role('community manager');
  $moderator_rid = install_add_role('moderator');
  $staff_rid = install_add_role('staff');
  $member_rid = install_add_role('member');
  $registered_rid = install_add_role('registered');

  // The value of each variable is now the role id
  // Login toboggan needs the rid of the registered but not authenticated role
  variable_set('logintoboggan_pre_auth_role', $registered_rid);

  // administrator user is managed by admin_role module

  // Make sure first user is a "Site Manager"
  db_query("INSERT INTO {users_roles} (uid, rid) VALUES (1, $sitemgr_rid)");
  // Make sure first user is a "Community Manager"
  db_query("INSERT INTO {users_roles} (uid, rid) VALUES (1, $communitymanager_rid)");

    // Purge permissions, just in case there are any stored
  db_query("DELETE FROM {permission}");

  // Setup permissions for site manager user
  install_add_permissions($sitemgr_rid, array(
    'access user profiles',
    'create comment content',
    'edit any comment content',
    'revert revisions',
    'post comments without approval',
      'access user profiles',
      'administer comments',
      'delete any blog entry',
      'delete heartbeat activity logs',
  ));

  // Setup permissions for community manager user
  install_add_permissions($communitymanager_rid, array(
    'create comment content',
    'edit any comment content',
    'revert revisions',
    'post comments without approval',
      'access user profiles',
      'administer comments',
      'delete any blog entry',
      'delete heartbeat activity logs',
      'edit any blog entry',

  ));

  // Setup permissions for moderator user
  install_add_permissions($moderator_rid, array(
    'create comment content',
    'edit any comment content',
    'revert revisions',
    'post comments without approval',
      'access user profiles',
      'administer comments',

  ));


  // Setup permissions for staff user
  install_add_permissions($staff_rid, array(
    'create comment content',
    'delete own comment content',
    'edit own comment content',
    'post comments without approval',
      'access user profiles',
      'create blog entries',
      'edit own blog entries',
      'delete own blog entries',
  ));

  // Setup permissions for member user
  install_add_permissions($member_rid, array(
    'create comment content',
    'delete own comment content',
    'edit own comment content',
    'post comments without approval',
      'access user profiles',
      'can have relationships',
      'create blog entries',
      'edit own blog entries',
      'delete own blog entries',
      'delete own heartbeat activity logs',
      'maintain own relationships',
      'view user relationships',
  ));

  // Setup permissions for authenticated user
  install_add_permissions(2, array(
    'access comments',
    'post comments',
      'post comments without approval',
    'access content',
    'create comment content',
    'search content',
     // 'maintain own subscriptions',
     // 'manage own subscriptions',
    //  'skip notifications',
    //  'subscribe to author',
    //  'subscribe to content',
      'view heartbeat messages',
  ));

  // Setup permissions for anonymous user
  install_add_permissions(1, array(
    'access comments',
    'access content',
    'search content',
  ));


  // Then our test users - one for each role
  // IMPORTANT - this is not safe for a production site. Remove these users before going live!
  install_add_user('site manager', 'test', 'sitemanager@example.com', array('site manager'), 1);
  install_add_user('editor', 'test', 'editor@example.com', array('editor'), 1);
  install_add_user('moderator', 'test', 'moderator@example.com', array('moderator'), 1);
  install_add_user('contributor', 'test', 'contributor@example.com', array('contributor'), 1);
  install_add_user('staff', 'test', 'staff@example.com', array('staff'), 1);
  install_add_user('authenticated', 'test', 'authenticated@example.com', array('authenticated user'), 1);
  install_add_user('registered', 'test', 'registered@example.com', array('registered'), 1);
  install_add_user('anonymous', 'test', 'anonymous@example.com', array('anonymous user'), 1);


  // Now we set up permissions on input filters

  /*
   * To set up a new input format:
   *
   * $formatid = install_add_format($name, $cache = 1)
   *
   * $name = human readable name of input format
   * $cache = if it is cacheable
   *
   * it returns the new format id
   */

  /*
   * Add a filter to the specified format
   *
   * install_set_filter($format_id, $module, $delta = 0, $weight = 0)
   *
   * format_id = the id of the input format to add the filter to
   * module = the module this filter belongs to
   * delta = the delta of this filter within the module
   * weight = the weight to apply to the filter
   */

  /*
   * Assign an input filter to be available to a role
   *
   * install_format_set_roles($roles, $format_id)
   *
   * $roles = an array of role IDs
   * $format_id = an integer of the format ID
   */


  // And we're done
  $msg = st('Configured Permissions');
  _jetset_log($msg);
  $context['message'] = $msg;
}

