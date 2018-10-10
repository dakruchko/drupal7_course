<?php
/**
 * @file
 * Here we connect lesson_batch table to the Views.
 */

/**
 * Implements hook_views_data()
 */
function lesson_batch_views_data() {
  $data['lesson_batch']['table']['group'] = t('lesson_batch');
  $data['lesson_batch']['table']['base'] = [
    'field' => 'id',
    'title' => t('lesson_batch'),
    'help' => t('lesson_batch table contains lesson_batch info'),
  ];

  $data['lesson_batch']['id'] = [
    'title' => t('Currency ID'),
    'field' => [
      'handler' => 'views_handler_field',
    ],
  ];

  $data['lesson_batch']['title'] = [
    'title' => t('Currency Name'),
    'help' => t('Currency Name'),
    'field' => [
      'handler' => 'views_handler_field',
    ],
  ];

  $data['lesson_batch']['rate'] = [
    'title' => t('Currency Rate'),
    'help' => t('Currency Rate'),
    'field' => [
      'handler' => 'views_handler_field',
    ],
  ];

  return $data;
}
