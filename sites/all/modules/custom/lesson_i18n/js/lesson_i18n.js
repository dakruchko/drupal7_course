/*
 * @file
 * JavaScript for lesson_i18n module.
 */

(function ($, Drupal) {
  Drupal.behaviors.lessonI18n = {
    attach : function(context, settings) {
      $("#lesson-i18n-user-registration-date").click(function() {
        const params = {
          "!regDate": Drupal.settings.created,
          "!newYearDays": Drupal.settings.days_to_new_year
        };
        alert(Drupal.t('registration date !regDate, days to New Year: !newYearDays', params));
      });
    }
  };
})(jQuery, Drupal);
