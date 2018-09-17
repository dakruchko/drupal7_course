<?php

/**
 * @file
 * Renders output data.
 */

/**
 * Page callback: Displays a page with random number.
 *
 * @see lesson_i18n_menu().
 */
function lesson_i18n_random_number() {
  $random_number = mt_rand(0, 100);
  return format_plural($random_number, 'task', '@count tasks');
}

/**
 * Page callback: Displays a page with link to show user registration date and number of days to New Year.
 *
 * @see lesson_i18n_menu().
 */
function lesson_i18n_link_get_user_registration_date() {
  $user_registration_date = format_date($GLOBALS['user']->created, $type = 'custom', $format = 'd F Y');
  $new_year_date = new DateObject('January 1, 2019 00:00:00');
  $current_date = new DateObject(time());
  $days_to_new_year = $new_year_date->difference($current_date, 'days');
  drupal_add_js(array('days_to_new_year' => $days_to_new_year), 'setting');
  drupal_add_js(drupal_get_path('module', 'lesson_i18n') . '/js/lesson_i18n.js');
  drupal_add_js(array('created' => $user_registration_date), 'setting');

  return l('show user registration date', current_path(), ['attributes' => ['id' => 'lesson-i18n-user-registration-date']]);
}
