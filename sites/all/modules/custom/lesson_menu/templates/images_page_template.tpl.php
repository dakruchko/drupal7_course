<?php

/**
 * @file
 * Displays a list of images and possible image styles.
 *
 * Available variables:
 * - $original_image: contains HTML for an original (sample) image.
 * - $list: contains a list of possible image styles.
 * - $generated_images: array that contains generated miniatures, array keys are image styles names, array values are links to the images.
 *
 * @see lesson_menu_render_image().
 *
 */

print $original_image;

print $list;

foreach ($generated_images as $src) {
  print theme('image', $variables = ['path' => $src]);
}
