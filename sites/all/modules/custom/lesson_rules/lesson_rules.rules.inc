<?php

/**
 * @file
 * Implements custom rules event and action.
 */

/**
 * Implements hook_event_info().
 */
function lesson_rules_rules_event_info() {
  return [
    'lesson_rules' => [
      'label' => t('Lottery page visited'),
      'group' => t('Training'),
    ],
  ];
}

/**
 * Implements hook_rules_action_info().
 */
function lesson_rules_rules_action_info() {
  return [
    'lesson_action' => [
      'label' => t('Show a message on the site'),
      'group' => t('System'),
      'parameter' => [
        'message' => [
          'type' => 'text',
          'label' => t('Message'),
          'sanitize' => TRUE,
          'translatable' => TRUE,
        ],
        'type' => [
          'type' => 'token',
          'label' => t('Message type'),
          'options list' => 'rules_action_drupal_message_types',
          'default value' => 'status',
          'optional' => TRUE,
        ],
        'repeat' => [
          'type' => 'boolean',
          'label' => t('Repeat message'),
          'description' => t("If disabled and the message has been already shown, then the message won't be repeated."),
          'default value' => TRUE,
          'optional' => TRUE,
          'restriction' => 'input',
        ],
      ],
      'base' => 'lesson_rules_custom_action',
    ],
  ];
}

/**
 * Sends xmlrpc request and shows predefined message in case of win.
 */
function lesson_rules_custom_action($message, $status, $repeat) {
  global $user;
  if (!cache_get($user->uid . '-winner', 'cache_lesson_rules')) {
    $lucky_number = mt_rand(1, 8);
    $server = url($GLOBALS['base_url'] . '/xmlrpc.php', ['external' => TRUE]);
    $options = [
      'lesson_rules.ping' => [$lucky_number],
    ];
    $result = xmlrpc($server, $options);
    if ($result !== 0) {
      drupal_set_message(filter_xss_admin($message), $status, $repeat);
      $cid = $user->uid . '-winner';
    }
    else {
      $cid = $user->uid . '-' . REQUEST_TIME;
    }
    $obj = new stdClass();
    $obj->winner_code = $result;
    cache_set($cid, $obj, 'cache_lesson_rules', CACHE_PERMANENT);
  }
  else {
    drupal_set_message(filter_xss_admin($message), $status, $repeat);
  }
}
