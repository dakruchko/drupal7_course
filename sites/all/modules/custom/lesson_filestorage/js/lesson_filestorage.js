/*
 * @file
 * JavaScript for lesson_filestorage module.
 */

(function ($, Drupal) {
  Drupal.behaviors.lessonFilestorage = {
    attach : function(context, settings) {
      var ownerClass = "uploaded-by-you"; // class to highlight files uploaded by current user
      Drupal.ajax.prototype.commands.afterAjaxCallback = function(ajax, response, status) {
        var fileStorageTable = $('#file-storage-table');
        var html = '';
        html+='<td>' + response.uploaded_file.fid + '</td>';
        html+='<td>' + response.uploaded_file.uid + '</td>';
        html+='<td>' + response.uploaded_file.uri + '</td>';
        html+='<td>' + response.uploaded_file.status + '</td>';
        html+='<td>' + response.uploaded_file.download_link + '</td>';
        var $newRow = $('<tr class='+ownerClass+'></tr>').append(html).appendTo(fileStorageTable);
      };
      $("td.user_id").filter(function(index) {
        return $(this).html() == Drupal.settings.uid;
      }).parent().addClass(ownerClass);
    }
  };
})(jQuery, Drupal);
