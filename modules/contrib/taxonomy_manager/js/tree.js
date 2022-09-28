(function ($, Drupal, drupalSettings) {
  'use strict';

  /**
   * Attaches the JS.
   */
  Drupal.behaviors.TaxonomyManagerTree = {
    attach: function (context, settings) {
      var treeSettings = settings.taxonomy_manager.tree || [];
      if (treeSettings instanceof Array) {
        for (var i = 0; i < treeSettings.length; i++) {
          $('#' + treeSettings[i].id).once('taxonomy-manager-tree').each(function () {
            new Drupal.TaxonomyManagerFancyTree(treeSettings[i].id, treeSettings[i].name, treeSettings[i].source);
          });
        }
      }
    }
  };

  /**
   * FancyTree integration.
   *
   * @param {string} id The id of the wrapping div element
   * @param {string} name The form element name (used in $_POST)
   * @param {object} source The JSON object representing the initial tree
   */
  Drupal.TaxonomyManagerFancyTree = function (id, name, source) {
    // Settings generated by http://wwwendt.de/tech/fancytree/demo/sample-configurator.html
    $('#' + id).fancytree({
      activeVisible: true, // Make sure, active nodes are visible (expanded).
      aria: false, // Enable WAI-ARIA support.
      autoActivate: true, // Automatically activate a node when it is focused (using keys).
      autoCollapse: false, // Automatically collapse all siblings, when a node is expanded.
      autoScroll: false, // Automatically scroll nodes into visible area.
      clickFolderMode: 4, // 1:activate, 2:expand, 3:activate and expand, 4:activate (dblclick expands)
      checkbox: true, // Show checkboxes.
      debugLevel: 2, // 0:quiet, 1:normal, 2:debug
      disabled: false, // Disable control
      focusOnSelect: false, // Set focus when node is checked by a mouse click
      generateIds: false, // Generate id attributes like <span id='fancytree-id-KEY'>
      idPrefix: 'ft_', // Used to generate node id´s like <span id='fancytree-id-<key>'>.
      icon: false, // Display node icons.
      keyboard: false, // Support keyboard navigation.
      keyPathSeparator: '/', // Used by node.getKeyPath() and tree.loadKeyPath().
      minExpandLevel: 1, // 1: root node is not collapsible
      quicksearch: false, // Navigate to next node by typing the first letters.
      selectMode: 2, // 1:single, 2:multi, 3:multi-hier
      tabindex: 0, // Whole tree behaves as one single control
      titlesTabbable: false, // Node titles can receive keyboard focus
      lazyLoad: function (event, data) {
        // Load child nodes via ajax GET /taxonomy_manager/parent=1234
        data.result = {
          url: Drupal.url('taxonomy_manager/subTree'),
          data: {parent: data.node.key},
          cache: false
        };
      },
      source: source,
      select: function (event, data) {
        // We update the the form inputs on every checkbox state change as
        // ajax events might require the latest state.
        data.tree.generateFormElements(name + '[]');
        // If no item is selected then disable delete button.
        if (data.tree.getSelectedNodes().length < 1) {
          document.getElementById("edit-delete").disabled = true;
        } else {
          let $deleteButton = document.getElementById("edit-delete");
          $deleteButton.disabled = false;
          if ($deleteButton.classList.contains('is-disabled')) {
            $deleteButton.classList.remove('is-disabled');
          }
        }
      },
      focus: function (event, data) {
        new Drupal.TaxonomyManagerTermData(data.node.key, data.tree);
      }
    });
  };

})(jQuery, Drupal, drupalSettings);
