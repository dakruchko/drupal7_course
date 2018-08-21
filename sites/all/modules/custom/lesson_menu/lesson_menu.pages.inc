<<<<<<< HEAD
<?php

/**
 * @file
 * Renders output data.
 */

/**
 * Page callback: Displays a landing page.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_landing() {
  return t('This is the landing page of the Training module');
}

/**
 * Page callback: Displays a tab page.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_tabs($index = '') {
  return ($index === '') ? t('This is the "tabs" menu entry') : t('This is the tab "@index" in the "basic tabs" example', ['@index' => $index]);
}

/**
 * Page callback: Displays a page with passed arguments.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_arguments($one = '', $two = '') {
  $one = ($one !== '') ? $one : t('Did not passed');
  $two = ($two !== '') ? $two : t('Did not passed');

  return t('Argument 1=@one<br />Argument 2=@two', ['@one' => $one, '@two' => $two]);
}

/**
 * Page callback: Displays a page with dynamic argument.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_div($argument) {
  return t('<div>@argument</div>', ['@argument' => $argument]);
}

/**
 * Page callback: Displays a page with prepared argument.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_show_page_with_argument($argument) {
  return ($argument !== '404') ? $argument : drupal_not_found();
}

/**
 * Page callback: Displays a page with visitor's name.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_username() {
  $username = !empty($GLOBALS['user']->name) ?  $GLOBALS['user']->name : t('anonymous');
  return t('Dynamic title: username=@username', ['@username' => $username]);
}

/**
 * Page callback: Displays a page with list of links.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_theme() {
  $links_array = [
    ['title' => t('List'), 'href' => '/training/theme/list'],
    ['title' => t('table'), 'href' => '/training/theme/table'],
    ['title' => t('image'), 'href' => '/training/theme/image'],
    ['title' => t('Access'), 'href' => '/training/theme/Access'],
  ];

  return theme('links', array(
    'links' => $links_array,
    'attributes' => ['type' => 'ol'],
    'heading' => t('Links to themes'),
  ));
}

/**
 * Page callback: Displays a page with table.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_table() {
  $header = [
    t('header 1'),
    t('header 2'),
    t('header 3'),
  ];
  $rows = [
    [
      'data' => [t('cell 1'), ['data' => t('double cell 1'), 'colspan' => 2]],
      'class' => ['rowClass'],
    ],
    [
      'data' => [t('cell 2'), ['data' => t('double cell 2'), 'colspan' => 2]],
      'class' => ['rowClass'],
    ],
  ];
  $attributes = [
    'id' => 'table-test',
  ];

  return theme('table', $variables = [
    'header' => $header,
    'rows' => $rows,
    'attributes' => $attributes,
    'caption' => t('Theme table sample'),
  ]);
}

/**
 * Page callback: Prepares data and passes it to rendering.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_image() {
  $attributes = [
    'class' => ['simple-image'],
  ];
  $original_path = 'public://images/sample.png';

  if (!file_exists($original_path)) {
    file_unmanaged_copy('modules/image/sample.png', $original_path, FILE_EXISTS_REPLACE);
  }

  $original_image = theme('image', [
    'path' => $original_path,
    'attributes' => $attributes,
  ]);

  $image_styles = array_keys(image_styles());
  foreach ($image_styles as $style) {
    $derivative_uri = image_style_url($style, $original_path);
    if (!file_exists($derivative_uri)) {
      $derivative_uri = image_style_create_derivative(image_style_load($style), $original_path, $derivative_uri);
    }
    $generated_images[$style]  = file_create_url($derivative_uri);
  }

  $list_of_styles = theme('item_list', [
    'items' => $image_styles,
    'type' => 'ol',
    'title' => t('Images Styles'),
  ]);

  return theme('lesson_menu_render_images', [
    'list' => $list_of_styles,
    'original_image' => $original_image,
    'generated_images' => $generated_images,
  ]);
}

/**
 * Page callback: Displays a page with content that depends on user's permission.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_access() {
  return (user_access('access protected content')) ? t('Custom access for rendered content') : t('Custom access inversed for rendered content');
}
=======
<?php

/**
 * @file
 * Renders output data.
 */

/**
 * Page callback: Displays a landing page.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_landing() {
  return t('This is the landing page of the Training module');
}

/**
 * Page callback: Displays a tab page.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_tabs($index = '') {
  return ($index === '') ? t('This is the "tabs" menu entry') : t('This is the tab "@index" in the "basic tabs" example', ['@index' => $index]);
}

/**
 * Page callback: Displays a page with passed arguments.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_arguments($one = '', $two = '') {
  $one = ($one !== '') ? $one : t('Did not passed');
  $two = ($two !== '') ? $two : t('Did not passed');

  return t('Argument 1=@one<br />Argument 2=@two', ['@one' => $one, '@two' => $two]);
}

/**
 * Page callback: Displays a page with dynamic argument.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_div($argument) {
  return t('<div>@argument</div>', ['@argument' => $argument]);
}

/**
 * Page callback: Displays a page with prepared argument.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_show_page_with_argument($argument) {
  return ($argument !== '404') ? $argument : drupal_not_found();
}

/**
 * Page callback: Displays a page with visitor's name.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_username() {
  $username = !empty($GLOBALS['user']->name) ?  $GLOBALS['user']->name : t('anonymous');
  return t('Dynamic title: username=@username', ['@username' => $username]);
}

/**
 * Page callback: Displays a page with list of links.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_theme() {
  $links_array = [
    ['title' => t('List'), 'href' => '/training/theme/list'],
    ['title' => t('table'), 'href' => '/training/theme/table'],
    ['title' => t('image'), 'href' => '/training/theme/image'],
    ['title' => t('Access'), 'href' => '/training/theme/Access'],
  ];

  return theme('links', array(
    'links' => $links_array,
    'attributes' => ['type' => 'ol'],
    'heading' => t('Links to themes'),
  ));
}

/**
 * Page callback: Displays a page with table.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_table() {
  $header = [
    t('header 1'),
    t('header 2'),
    t('header 3'),
  ];
  $rows = [
    [
      'data' => [t('cell 1'), ['data' => t('double cell 1'), 'colspan' => 2]],
      'class' => ['rowClass'],
    ],
    [
      'data' => [t('cell 2'), ['data' => t('double cell 2'), 'colspan' => 2]],
      'class' => ['rowClass'],
    ],
  ];
  $attributes = [
    'id' => 'table-test',
  ];

  return theme('table', $variables = [
    'header' => $header,
    'rows' => $rows,
    'attributes' => $attributes,
    'caption' => t('Theme table sample'),
  ]);
}

/**
 * Page callback: Prepares data and passes it to rendering.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_image() {
  $attributes = [
    'class' => ['simple-image'],
  ];
  $original_path = 'public://images/sample.png';

  if (!file_exists($original_path)) {
    file_unmanaged_copy('modules/image/sample.png', $original_path, FILE_EXISTS_REPLACE);
  }

  $original_image = theme('image', [
    'path' => $original_path,
    'attributes' => $attributes,
  ]);

  $image_styles = array_keys(image_styles());
  foreach ($image_styles as $style) {
    $derivative_uri = image_style_url($style, $original_path);
    if (!file_exists($derivative_uri)) {
      $derivative_uri = image_style_create_derivative(image_style_load($style), $original_path, $derivative_uri);
    }
    $generated_images[$style]  = file_create_url($derivative_uri);
  }

  $list_of_styles = theme('item_list', [
    'items' => $image_styles,
    'type' => 'ol',
    'title' => t('Images Styles'),
  ]);

  return theme('lesson_menu_render_images', [
    'list' => $list_of_styles,
    'original_image' => $original_image,
    'generated_images' => $generated_images,
  ]);
}

/**
 * Page callback: Displays a page with content that depends on user's permission.
 *
 * @see lesson_menu_menu().
 */
function lesson_menu_render_access() {
  return (user_access('access protected content')) ? t('Custom access for rendered content') : t('Custom access inversed for rendered content');
}
>>>>>>> 986ad87... first hometask
