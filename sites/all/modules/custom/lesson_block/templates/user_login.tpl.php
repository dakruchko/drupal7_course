<?php
/**
 * @file
 * Implements table layout for login form.
 *
 * Available variables:
 * - $form: array that contains fields for login form.
 *
 * @see lesson_block_theme().
 *
 */
?>
<table>
  <tr>
    <td><?php print drupal_render($form['name']); ?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form['pass']); ?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form['secret_key']); ?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form['actions']['submit']); ?></td>
  </tr>
  <tr>
    <td><?php print drupal_render_children($form); ?></td>
  </tr>
</table>
