<?php
// $Id$

/**
 * @file
 * Setup Wysiwyg editor
 * 
 */

function _jetset_setup_wysiwyg(&$context) {

  // Build SQL statement
  $sql = "INSERT INTO {wysiwyg} (format, editor, settings) VALUES (%d, '%s', '%s')";

  // Insert the settings
  db_query($sql, 1, 'ckeditor', serialize(drupal_commons_editor_settings('Filtered HTML')));

  // Build settings for filtered html array
  $settings = array();

  // Insert the settings
  db_query($sql, 2, 'ckeditor', serialize(drupal_commons_editor_settings('Full HTML')));

  $msg = st('Configured Wysiwyg editor');
  _jetset_log($msg);
  $context['message'] = $msg;
}


/*
 *  Return settings for WYSIWYG editors
 *
 * @param $format
 *   The format name
 * @return
 *   An array of editor settings
 */
function drupal_commons_editor_settings($format) {
  $settings = '';

  switch($format) {
    case 'Full HTML':
      $settings = array(
        'default' => 1,
        'user_choose' => 0,
        'show_toggle' => 1,
        'theme' => 'advanced',
        'language' => 'en',
        'buttons' => array(
          'default' => array(
            'Bold' => 1,
            'Italic' => 1,
            'Underline' => 1,
            'Strike' => 1,
            'JustifyLeft' => 1,
            'JustifyCenter' => 1,
            'JustifyRight' => 1,
            'JustifyBlock' => 1,
            'BulletedList' => 1,
            'NumberedList' => 1,
            'Outdent' => 1,
            'Indent' => 1,
            'Undo' => 1,
            'Redo' => 1,
            'Link' => 1,
            'Unlink' => 1,
            'Anchor' => 1,
            'Image' => 1,
            'Superscript' => 1,
            'Subscript' => 1,
            'Blockquote' => 1,
            'Cut' => 1,
            'Copy' => 1,
            'Paste' => 1,
            'RemoveFormat' => 1,
            'SpecialChar' => 1,
            'Format' => 1,
            'Table' => 1,
            'Find' => 1,
            'CreateDiv' => 1,
            'Maximize' => 1,
          ),
        ),
        'toolbar_loc' => 'top',
        'toolbar_align' => 'left',
        'path_loc' => 'bottom',
        'resizing' => 1,
        'verify_html' => 1,
        'preformatted' => 0,
        'convert_fonts_to_spans' => 0,
        'remove_linebreaks' => 0,
        'apply_source_formatting' => 0,
        'paste_auto_cleanup_on_paste' => 0,
        'block_formats' => 'p,address,pre,blockquote,h2,h3,h4,h5,h6,div',
        'css_setting' => 'theme',
        'css_path' => '',
        'css_classes' => '',
      );
      break;

    case 'Filtered HTML':
    default:
      $settings = array(
        'default' => 1,
        'user_choose' => 0,
        'show_toggle' => 1,
        'theme' => 'advanced',
        'language' => 'en',
        'buttons' => array(
          'default' => array(
            'Bold' => 1,
            'Italic' => 1,
            'Underline' => 1,
            'Strike' => 1,
            'JustifyLeft' => 1,
            'JustifyCenter' => 1,
            'JustifyRight' => 1,
            'JustifyBlock' => 1,
            'BulletedList' => 1,
            'NumberedList' => 1,
            'Outdent' => 1,
            'Indent' => 1,
            'Undo' => 1,
            'Redo' => 1,
            'Link' => 1,
            'Unlink' => 1,
            'Anchor' => 1,
            'Image' => 1,
            'Superscript' => 1,
            'Subscript' => 1,
            'Blockquote' => 1,
            'Cut' => 1,
            'Copy' => 1,
            'Paste' => 1,
            'PasteFromWord' => 1,
            'RemoveFormat' => 1,
            'Format' => 1,
            'SelectAll' => 1,
            'Find' => 1,
          ),
        ),
        'toolbar_loc' => 'top',
        'toolbar_align' => 'left',
        'path_loc' => 'bottom',
        'resizing' => 1,
        'verify_html' => 1,
        'preformatted' => 0,
        'convert_fonts_to_spans' => 1,
        'remove_linebreaks' => 0,
        'apply_source_formatting' => 0,
        'paste_auto_cleanup_on_paste' => 0,
        'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6',
        'css_setting' => 'theme',
        'css_path' => '',
        'css_classes' => '',
      );
  }

  return $settings;
}

