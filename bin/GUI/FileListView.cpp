// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "FileListView.h"

#include <QHeaderView>
#include <QJsonArray>
#include <QJsonObject>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <filesystem>
#include <map>
#include <unordered_map>

namespace mx::gui {

struct FileListView::PrivateData final {
  QTreeWidget *source_file_tree{nullptr};
  std::unordered_map<QTreeWidgetItem *, mx::FileId> file_ids;
};

FileListView::FileListView(QWidget *parent)
    : QWidget(parent),
      d(new PrivateData) {

  setWindowTitle(tr("Files"));

  d->source_file_tree = new QTreeWidget();
  d->source_file_tree->setHeaderHidden(true);
  d->source_file_tree->setColumnCount(1);
  d->source_file_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->source_file_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->source_file_tree->header()->setStretchLastSection(false);

  auto layout = new QVBoxLayout();
  layout->setContentsMargins(0, 0, 0, 0);
  setLayout(layout);

  layout->addWidget(d->source_file_tree);

  connect(d->source_file_tree, &QTreeWidget::itemActivated, this,
          &FileListView::OnTreeWidgetItemActivated);
}

FileListView::~FileListView(void) {}

void FileListView::Set(FileList files) {
  QTreeWidgetItem *root_item = nullptr;

  // Build up the items.
  std::map<std::filesystem::path, QTreeWidgetItem *> item_map;
  for (const auto &[path_, file_id] : files) {
    std::filesystem::path path = path_.lexically_normal();
    auto base = path.root_path();
    QTreeWidgetItem *last = nullptr;
    for (std::filesystem::path part : path) {
      base /= part;
      auto &item = item_map[base.generic_string()];
      if (!item) {
        item = new QTreeWidgetItem();
        item->setText(0, QString::fromStdString(part.generic_string()));
        if (last) {
          last->addChild(item);
        } else if (!root_item) {
          root_item = item;
        }
      }
      last = item;
    }
    d->file_ids.emplace(last, file_id);
  }

  d->source_file_tree->addTopLevelItem(root_item);
  d->source_file_tree->expandAll();
  d->source_file_tree->sortItems(0, Qt::AscendingOrder);
}

void FileListView::Clear(void) {
  d->file_ids.clear();
  d->source_file_tree->reset();
}

void FileListView::OnTreeWidgetItemActivated(
    QTreeWidgetItem *item, int) {

  if (auto it = d->file_ids.find(item); it != d->file_ids.end()) {
    emit SourceFileDoubleClicked(it->second);
  }
}

}  // namespace mx::gui
