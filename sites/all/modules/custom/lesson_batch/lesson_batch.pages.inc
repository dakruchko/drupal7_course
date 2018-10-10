<?php
/**
 * @file
 * Renders output data.
 */

/**
 * Page callback: Displays a a table with uploaded files.
 *
 * @see lesson_batch_menu().
 */
function lesson_batch_landing_table() {
  global $user;
  drupal_add_js(drupal_get_path('module', 'lesson_batch') . '/js/lesson_batch.js');
  drupal_add_js(array('uid' => $user->uid, ), 'setting');
  $uploaded_files = [];
  $uploaded_files = db_select('file_managed', 'fm')
    ->fields('fm', ['fid', 'uid', 'uri', 'status'])
    ->execute()
    ->fetchAll();
  $user_has_rights_to_download = FALSE;
  foreach ($uploaded_files as $file) {
    if ($file->uid === $user->uid) {
      $user_has_rights_to_download = TRUE;
      break;
    }
  }

  return lesson_batch_render_table($uploaded_files, $user_has_rights_to_download);
}

/**
 * Page callback: Shows modal with form to upload the files and describes 'after upload' actions.
 *
 * @see lesson_batch_menu().
 */
function lesson_batch_upload_file() {
  ctools_include('modal');
  $form_state = [
    'title' => t('Upload File'),
    'ajax' => TRUE,
    'build_info' => [
      'args' => [],
    ],
  ];
  $commands = [];
  $commands = ctools_modal_form_wrapper('lesson_batch_form', $form_state);
  if (!empty($form_state['executed'])) {
    $commands = [];
    $commands[] = ctools_modal_command_dismiss();
    $just_uploaded_file = db_select('file_managed', 'fm')
      ->fields('fm', ['fid', 'uid', 'uri', 'status'])
      ->condition('fm.fid', $form_state['values']['file'])
      ->execute()
      ->fetchObject();
    $just_uploaded_file->download_link = l(t('Download'),  file_create_url($just_uploaded_file->uri), [
      'attributes' => [
        'download' => drupal_basename($just_uploaded_file->uri),
      ],
    ]);
    $commands[] = ctools_modal_command_display(t('uploaded successfully'), t('you can proceed now'));
    $commands[] = [
      'command' => 'afterAjaxCallback',
      'uploaded_file' => $just_uploaded_file,
    ];
  }

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Creates form to upload files.
 */
function lesson_batch_form($form, &$form_state) {
  $form['file'] = [
    '#type' => 'managed_file',
    '#title' => t('Image'),
    '#description' => t('Upload a file'),
  ];
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save'),
  ];
  $form['#attached']['css'][] = [
    drupal_get_path('module', 'lesson_batch') . 'css/lesson_batch.css',
  ];

  return $form;
}

/**
 * Renders table with all uploaded files and their attributes.
 */
function lesson_batch_render_table($uploaded_files, $user_has_rights_to_download) {
  $attributes = ['class' => ['uploaded-files-table'], 'id' => 'file-storage-table'];
  $header = [
    t('file ID'),
    t('user ID'),
    t('URI'),
    t('status'),
    t('link'),
  ];
  $rows = [];
  if (!empty($uploaded_files)) {
    foreach ($uploaded_files as $file) {
      if ($user_has_rights_to_download) {
        $rows[] = [
          'data' => [
            $file->fid,
            ['data' => $file->uid, 'class' => ['user_id']],
            $file->uri,
            $file->status,
            l(t('Download'),  file_create_url($file->uri), [
              'attributes' => [
                'download' => drupal_basename($file->uri),
              ],
            ]),
          ],
        ];
      }
      else {
        $rows[] = [
          'data' => [
            $file->fid,
            $file->uid,
            $file->uri,
            $file->status,
            t('You have no access to this file'),
          ],
        ];
      }
    }
  }

  return theme('table', $variables = [
    'header' => $header,
    'rows' => $rows,
    'attributes' => $attributes,
    'caption' => t('Uploaded Files'),
  ]);
}
