<?php

namespace Drupal\amswap\Render\Element;

use Drupal\Component\Utility\NestedArray;
use Drupal\Core\Menu\MenuTreeParameters;
use Drupal\Core\Security\TrustedCallbackInterface;

/**
 * Provides a pre-render callback for the administration menu.
 */
class Amswap implements TrustedCallbackInterface {

  /**
   * {@inheritdoc}
   */
  public static function trustedCallbacks() {
    return ['preRender'];
  }

  /**
   * Pre-render callback to replace the default menu with a role specific menu.
   *
   * @param array $element
   *   The administration toolbar.
   *
   * @return array
   *   The altered element.
   */
  public static function preRender(array $element) {
    $parameters = new MenuTreeParameters();
    $parameters->onlyEnabledLinks();

    $toolbar_menu_tree = \Drupal::service('toolbar.menu_tree');
    $current_user = \Drupal::currentUser();
    $role_menu_pairs = \Drupal::config('amswap.amswapconfig')->get('role_menu_pairs');

    $menu_specified = FALSE;
    $trees = [];
    if (is_array($role_menu_pairs) || is_object($role_menu_pairs)) {
      foreach ($role_menu_pairs as $pair) {
        // If the specified role matches the users current role
        if (in_array($pair['role'], $current_user->getRoles(), FALSE)) {
          $parameters
            ->setMinDepth(1)
            ->setMaxDepth(4);

          $trees[] = $toolbar_menu_tree->load($pair['menu'], $parameters);
          $menu_specified = TRUE;
        }
      }
    }

    if (!$menu_specified) {
      // Return un-altered
      return $element;
    }

    // Add manipulators
    $manipulators = [
      ['callable' => 'menu.default_tree_manipulators:checkAccess'],
      ['callable' => 'menu.default_tree_manipulators:generateIndexAndSort'],
    ];

    if (function_exists('toolbar_tools_menu_navigation_links')) {
      // If Admin Toolbar module is installed, use its toolbar manipulation function
      $manipulators[] = ['callable' => 'toolbar_tools_menu_navigation_links'];
    }
    else {
      // Otherwise use Toolbar module's toolbar manipulation function
      $manipulators[] = ['callable' => 'toolbar_menu_navigation_links'];
    }

    $element['administration_menu'] = [];
    foreach ($trees as $tree) {
      $tree = $toolbar_menu_tree->transform($tree, $manipulators);
      $element['administration_menu'] =  NestedArray::mergeDeep($toolbar_menu_tree->build($tree), $element['administration_menu']);
    }

    return $element;
  }

}
