/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "translationunitindex.h"

#include <QHeaderView>
#include <QJsonArray>
#include <QJsonObject>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <array>

namespace multiplier {

struct TranslationUnitIndex::PrivateData final {
  QTreeWidget *source_file_tree{nullptr};
};

TranslationUnitIndex::TranslationUnitIndex(QWidget *parent)
    : ITranslationUnitIndex(parent), d(new PrivateData) {
  setWindowTitle(tr("Translation Units"));

  auto layout = new QVBoxLayout();
  layout->setContentsMargins(0, 0, 0, 0);
  setLayout(layout);

  d->source_file_tree = new QTreeWidget();
  d->source_file_tree->setHeaderHidden(true);
  d->source_file_tree->setColumnCount(1);
  d->source_file_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->source_file_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->source_file_tree->header()->setStretchLastSection(false);
  layout->addWidget(d->source_file_tree);

  connect(d->source_file_tree, &QTreeWidget::itemActivated, this,
          &TranslationUnitIndex::onTreeWidgetItemActivated);
}

TranslationUnitIndex::~TranslationUnitIndex() {}

bool TranslationUnitIndex::setCompileCommands(const QJsonDocument &json_document) {
  static const std::array<const char *, 3> kExpectedFileObjectEntries = {
      "directory",
      "command",
      "file",
  };

  if (!json_document.isArray()) {
    return false;
  }

  QMap<QString, QTreeWidgetItem *> root_item_map;

  const auto &file_obj_array = json_document.array();
  for (const auto &file_obj_value : file_obj_array) {
    if (!file_obj_value.isObject()) {
      return false;
    }

    const auto &file_obj = file_obj_value.toObject();
    for (const auto &entry_name : kExpectedFileObjectEntries) {
      if (!file_obj.contains(entry_name) || !file_obj[entry_name].isString()) {
        return false;
      }
    }

    auto directory_path = file_obj["directory"].toString();
    auto compile_command = file_obj["command"].toString();
    auto source_file = file_obj["file"].toString();

    auto path_component_list = source_file.split(QChar('/'));

    auto parent_name = path_component_list.takeFirst();
    if (!parent_name.isEmpty()) {
      // This is not an absolute path
      return false;
    }

    parent_name = path_component_list.takeFirst();
    if (parent_name.isEmpty()) {
      return false;
    }

    auto file_name = path_component_list.takeLast();

    auto root_item_map_it = root_item_map.find(parent_name);
    if (root_item_map_it == root_item_map.end()) {
      auto item = new QTreeWidgetItem();
      item->setText(0, parent_name);

      root_item_map_it = root_item_map.insert(parent_name, item);
    }

    auto parent = *root_item_map_it;

    for (const auto &path_component : path_component_list) {
      auto found{false};

      for (auto i = 0; i < parent->childCount(); ++i) {
        auto child = parent->child(i);
        if (child->text(0) == path_component) {
          found = true;
          parent = child;
        }
      }

      if (!found) {
        auto child = new QTreeWidgetItem();
        child->setText(0, path_component);

        parent->addChild(child);
        parent = child;
      }
    }

    auto file_name_item = new QTreeWidgetItem();
    file_name_item->setText(0, file_name);
    file_name_item->setText(1, directory_path);
    file_name_item->setText(2, source_file);
    file_name_item->setText(3, compile_command);

    parent->addChild(file_name_item);
  }

  for (auto item : root_item_map) {
    for (;;) {
      if (item->childCount() == 0) {
        break;

      } else if (item->childCount() == 1) {
        item = item->child(0);

      } else {
        break;
      }
    }

    auto root_item = new QTreeWidgetItem();
    root_item->setText(0, item->text(0));
    root_item->addChildren(item->takeChildren());
    delete item;

    d->source_file_tree->addTopLevelItem(root_item);
  }

  d->source_file_tree->expandAll();
  d->source_file_tree->sortItems(0, Qt::AscendingOrder);
  return true;
}

void TranslationUnitIndex::reset() { d->source_file_tree->reset(); }

void TranslationUnitIndex::onTreeWidgetItemActivated(QTreeWidgetItem *item, int) {

  if (item->childCount() != 0 || item->columnCount() != 4) {
    return;
  }

  auto working_directory = item->text(1);
  auto source_file_path = item->text(2);
  auto compile_command = item->text(3);

  emit sourceFileDoubleClicked(working_directory, source_file_path, compile_command);
}

} // namespace multiplier
