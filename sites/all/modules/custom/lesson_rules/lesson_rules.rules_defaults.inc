<?php

/**
 * @file
 * Default rule configuration.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function lesson_rules_default_rules_configuration() {
  $items = [];
  $items['rules_lottery_page'] = entity_import('rules_config', '{ "rules_lottery_page" : {
    "LABEL" : "Lottery page",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "lesson_rules" ],
    "ON" : { "lesson_rules" : [] },
    "DO" : [
      { "lesson_action" : { "message" : "Congratulations [site:current-user] You Win!" } }
    ]
  }}');

  return $items;
}
