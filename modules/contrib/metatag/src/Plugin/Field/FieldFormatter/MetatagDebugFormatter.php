<?php

namespace Drupal\metatag\Plugin\Field\FieldFormatter;

use Drupal\Component\Utility\Html;
use Drupal\Core\Field\FormatterBase;
use Drupal\Core\Field\FieldItemListInterface;

/**
 * Plugin implementation of the 'metatag_debug_formatter' formatter.
 *
 * @FieldFormatter(
 *   id = "metatag_debug_formatter",
 *   label = @Translation("Debug formatter"),
 *   field_types = {
 *     "metatag"
 *   }
 * )
 */
class MetatagDebugFormatter extends FormatterBase {

  /**
   * {@inheritdoc}
   */
  public function viewElements(FieldItemListInterface $items, $langcode) {
    $elements = [];
    foreach ($items as $delta => $item) {
      // Associative array keyed by the metatag names.
      $metetags = unserialize($item->value);
      if (empty($metetags)) {
        continue;
      }

      ksort($metetags);

      $items = [];
      foreach ($metetags as $name => $value) {
        $parsed = is_array($value) ? implode(', ', $value) : $value;
        $items[] = Html::escape("$name: $parsed");
      }

      $elements[$delta] = [
        '#theme' => 'item_list',
        '#list_type' => 'ul',
        '#items' => $items,
      ];
    }

    return $elements ?: [['#plain_text' => $this->t('No meta tags.')]];
  }

}