/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "parsedfilesindex.h"

#include <QDebug>
#include <QMap>
#include <QString>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <array>
#include <iostream>

#include <pasta/AST/AST.h>
#include <pasta/Util/File.h>

namespace multiplier {

struct ParsedFilesIndex::PrivateData final {
  QTreeWidget *source_file_tree{nullptr};
  QMap<QString, pasta::File> files;
};

ParsedFilesIndex::ParsedFilesIndex(QWidget *parent)
    : QFrame(parent), d(new PrivateData) {
  setWindowTitle(tr("Parsed Files"));

  auto layout = new QVBoxLayout();
  layout->setContentsMargins(0, 0, 0, 0);
  setLayout(layout);

  d->source_file_tree = new QTreeWidget();
  d->source_file_tree->setHeaderHidden(true);
  d->source_file_tree->setExpandsOnDoubleClick(false);
  layout->addWidget(d->source_file_tree);

  connect(d->source_file_tree, &QTreeWidget::itemActivated, this,
          &ParsedFilesIndex::onTreeWidgetItemActivated);
}

ParsedFilesIndex::~ParsedFilesIndex() {}

void ParsedFilesIndex::gotAST(std::shared_ptr<pasta::AST> ast) {
  QMap<QString, QTreeWidgetItem *> root_item_map;

  QTreeWidgetItem *root_item = new QTreeWidgetItem();

  for (const pasta::File &file : ast->ParsedFiles()) {

    QTreeWidgetItem *parent = nullptr;

    std::filesystem::path path = file.Path();
    std::filesystem::path accumulated_path = path.root_path();
    std::filesystem::path rel_path = path.relative_path();

    for (auto parent_name : rel_path) {
      accumulated_path /= parent_name;
      QString path_name = QString::fromStdString(accumulated_path.generic_string());
      QTreeWidgetItem *&item = root_item_map[path_name];
      if (!item) {
        item = new QTreeWidgetItem();
        item->setText(0, QString::fromStdString(parent_name.generic_string()));
        if (parent) {
          parent->addChild(item);
        } else {
          root_item->setText(
              0, QString::fromStdString(path.root_path().generic_string()));
          root_item->addChild(item);
        }
      }
      parent = item;
    }

    QString full_path = QString::fromStdString(path.generic_string());
    d->files.insert(full_path, file);
    parent->setText(1, full_path);
  }

  d->source_file_tree->addTopLevelItem(root_item);
  d->source_file_tree->expandAll();
  d->source_file_tree->sortItems(0, Qt::AscendingOrder);
}

void ParsedFilesIndex::reset() {
  d->files.clear();
  d->source_file_tree->reset();
}

void ParsedFilesIndex::onTreeWidgetItemActivated(QTreeWidgetItem *item, int) {

  if (item->childCount() != 0 || item->columnCount() != 2) {
    return;
  }

  auto source_file_path = item->text(1);
  auto file_it = d->files.find(source_file_path);
  if (file_it != d->files.end()) {
    emit parsedFileDoubleClicked(*file_it);
  }
}

} // namespace multiplier
