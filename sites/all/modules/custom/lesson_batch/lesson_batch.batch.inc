<?php
/**
 * @file
 * File contains batch operations.
 */

/**
 * Process every item in batch
 */
function lesson_batch_process_currencies($data, &$context) {
  $data_to_process = json_decode($data, TRUE);
  $limit = 1;
  if (empty($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($data_to_process);
  }
  if (empty($context['sandbox']['items'])) {
    $context['sandbox']['items'] = $data_to_process;
  }
  $counter = 0;
  if (!empty($context['sandbox']['items'])) {
    if ($context['sandbox']['progress'] != 0) {
      array_splice($context['sandbox']['items'], 0, $limit);
    }
    foreach ($context['sandbox']['items'] as $currency) {
      if ($counter !== $limit) {
        $currency_update = db_merge('lesson_batch')
          ->fields([
            'id' => $currency['Cur_ID'],
            'title' => $currency['Cur_Name'],
            'rate' => $currency['Cur_OfficialRate'],
          ])
          ->condition('id', $currency['Cur_ID'], '=')
          ->execute();
        $counter++;
        $context['sandbox']['progress']++;
        $context['message'] = t('Now processing currency %progress of %count', [
          '%progress' => $context['sandbox']['progress'],
          '%count' => $context['sandbox']['max']
        ]);
        $context['results']['processed'] = $context['sandbox']['progress'];
      }
    }
  }
  if ($context['sandbox']['progress'] !== $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Finish callback for Batch
 */
function lesson_batch_finished_callback($success, $results, $operations) {
  if ($success) {
    $message = format_plural($results['processed'], 'One currency processed.', '@count currencies processed.');
  }
  else {
    $message = t('Finished with an error.');
  }
  drupal_set_message($message);
}
