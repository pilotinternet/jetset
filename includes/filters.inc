<?php
// $Id$

/**
 * @file
 * Setup Input filters
 * 
 * 
 */

function _jetset_setup_filters(&$context) {

  /*
   * Set allowed HTML for filtered_html filter
   */
  $filteredhtml = '<a> <img> <br> <em> <p> <strong> <cite> <sub> <sup> <span>
  <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <pre>
  <address> <h2> <h3> <h4> <h5> <h6>';

  /*
   * Force filter format and filter IDs
   * Necessary because Drupal doesn't use machine names for everything
   */
  // Filtered HTML
  db_query("UPDATE {filters} f INNER JOIN {filter_formats} ff ON f.format = ff.format SET f.format = 1 WHERE ff.name = 'Filtered HTML'");
  db_query("UPDATE {filter_formats} SET format = 1 WHERE name = 'Filtered HTML'");

  // Full HTML
  db_query("UPDATE {filters} f INNER JOIN {filter_formats} ff ON f.format = ff.format SET f.format = 2 WHERE ff.name = 'Full HTML'");
  db_query("UPDATE {filter_formats} SET format = 2 WHERE name = 'Full HTML'");

  // PHP code
  db_query("UPDATE {filters} f INNER JOIN {filter_formats} ff ON f.format = ff.format SET f.format = 3 WHERE ff.name = 'PHP code'");
  db_query("UPDATE {filter_formats} SET format = 3 WHERE name = 'PHP code'");

  // Messaging
  db_query("UPDATE {filters} f INNER JOIN {filter_formats} ff ON f.format = ff.format SET f.format = 4 WHERE ff.name = 'Messaging plain text'");
  db_query("UPDATE {filter_formats} SET format = 4 WHERE name = 'Messaging plain text'");

  // Let community and content manager role use Full HTML
  db_query("UPDATE {filter_formats} SET roles = ',3,4,' WHERE name = 'Full HTML'");

  // Set Full HTML as default format for community and content manager roles
  db_query("INSERT INTO {better_formats_defaults} (rid, type, format, type_weight, weight)
    VALUES (3, 'node', 2, 1, 0)");
  db_query("INSERT INTO {better_formats_defaults} (rid, type, format, type_weight, weight)
    VALUES (3, 'comment', 2, 1, 0)");
  db_query("INSERT INTO {better_formats_defaults} (rid, type, format, type_weight, weight)
    VALUES (3, 'block', 2, 1, 25)");
  db_query("INSERT INTO {better_formats_defaults} (rid, type, format, type_weight, weight)
    VALUES (4, 'node', 2, 1, 0)");
  db_query("INSERT INTO {better_formats_defaults} (rid, type, format, type_weight, weight)
    VALUES (4, 'comment', 2, 1, 0)");
  db_query("INSERT INTO {better_formats_defaults} (rid, type, format, type_weight, weight)
    VALUES (4, 'block', 2, 1, 25)");

  // Create a "links-only" filter format that Shoutbox will use
  db_query("INSERT INTO {filter_formats} (format, name, cache) VALUES (5, 'Links Only', 1)");

  // Add filters to the format
  db_query("INSERT INTO {filters} (format, module, delta, weight) VALUES (5, 'filter', 0, -10)");
  db_query("INSERT INTO {filters} (format, module, delta, weight) VALUES (5, 'filter', 2, -9)");

  // Adjust settings for the filter
  variable_set('filter_url_length_5', 60);
  variable_set('filter_html_5', 1);
  variable_set('filter_html_help_5', 0);
  variable_set('allowed_html_5', '');

  // Set allowed HTML tags for Filter HTML format
  variable_set('allowed_html_1', $filteredhtml);

  // Add wiki-style freelinking to both default formats
  //$sql = "INSERT INTO {filters} (format, module, delta, weight) VALUES (%d, '%s', %d, %d)";
  //db_query($sql, 1, 'freelinking', 0, 10);  // Filtered HTML
  //db_query($sql, 2, 'freelinking', 0, 10);  // Full HTML

  $msg = st('Configured Input Filters');
  _jetset_log($msg);
  $context['message'] = $msg;
}
