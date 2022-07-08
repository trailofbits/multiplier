// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>

#include <map>
#include <set>
#include <unordered_map>
#include <utility>

#include "Configuration.h"
#include "FileBrowserView.h"
#include "Multiplier.h"

namespace mx::gui {

struct FileBrowserView::PrivateData final {
  FileBrowserConfiguration &config;

  QVBoxLayout *layout{nullptr};
  QLineEdit *filter_box{nullptr};

  QTreeWidget *source_file_tree{nullptr};

  std::unordered_map<
      QTreeWidgetItem *,
      std::pair<std::filesystem::path, RawEntityId>> file_infos;

  inline PrivateData(FileBrowserConfiguration &config_)
      : config(config_) {}
};

void DownloadFileListThread::run(void) {
  emit DownloadedFileList(index.file_paths());
}

FileBrowserView::FileBrowserView(FileBrowserConfiguration &config_,
                                 QWidget *parent)
    : QWidget(parent),
      d(new PrivateData(config_)) {

  InitializeWidgets();
}

FileBrowserView::~FileBrowserView(void) {}

void FileBrowserView::Clear(void) {
  d->source_file_tree->clear();
  d->file_infos.clear();
}

void FileBrowserView::Focus(void) {
  d->source_file_tree->setFocus();
}

void FileBrowserView::InitializeWidgets(void) {
  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);

  // Create a filter widget area so that we can filter down on specific files.
  auto filter_area = new QWidget;
  auto filter_layout = new QHBoxLayout;
  filter_area->setLayout(filter_layout);

  d->filter_box = new QLineEdit;
  filter_layout->addWidget(new QLabel(tr("Filter:")));
  filter_layout->addWidget(d->filter_box);
  d->layout->addWidget(filter_area);

  // Below the filter put the source tree.
  d->source_file_tree = new QTreeWidget;
  d->layout->addWidget(d->source_file_tree);

  setWindowTitle(tr("File Browser"));
  setLayout(d->layout);

  d->source_file_tree->setHeaderHidden(true);
  d->source_file_tree->setColumnCount(1);
  d->source_file_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->source_file_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->source_file_tree->header()->setStretchLastSection(false);

  connect(d->source_file_tree, &QTreeWidget::itemActivated,
          this, &FileBrowserView::OnTreeWidgetItemActivated);

  connect(d->filter_box, &QLineEdit::textChanged,
          this, &FileBrowserView::OnFilterFileView);
}

void FileBrowserView::OnFilterFileView(const QString &text) {

  auto set_visible = +[] (QTreeWidgetItem *item, bool visible) {
    for (auto parent = item; parent; parent = parent->parent()) {
      parent->setHidden(!visible);
    }
  };

  if (!text.size()) {
    for (auto &[item, path_id] : d->file_infos) {
      set_visible(item, true);
    }
  } else {
    for (auto &[item, path_id] : d->file_infos) {
      set_visible(item, false);
    }
    for (auto &[item, path_id] : d->file_infos) {
      QString path = QString::fromStdString(path_id.first.generic_string());
      if (path.contains(text)) {
        set_visible(item, true);
      }
    }
  }

  update();
}

void FileBrowserView::OnDownloadedFileList(FilePathList files) {
  Clear();

  QTreeWidgetItem *root_item = nullptr;

  std::set<std::filesystem::path> has_files;
  for (const auto &[path_, file_id] : files) {
    const std::filesystem::path &path = path_;
    auto base = path.root_path();
    for (std::filesystem::path part : path.parent_path()) {
      base /= part;  // A bit redundant, but follow the same process throughout.
    }
    has_files.emplace(std::move(base));
  }

  // Group the paths into folders that have at least one file in them. This is
  // so that we don't have to see crazy deep folder trees all the time.
  std::map<std::filesystem::path, FilePathList> sub_lists;
  for (const auto &[path_, file_id] : files) {
    std::filesystem::path path = path_;
    auto base = path.root_path();
    for (std::filesystem::path part : path.parent_path()) {
      base /= part;
      if (has_files.count(base)) {
        sub_lists[base].emplace(std::move(path), file_id);
        break;
      }
    }
  }

  // Build up the items.
  for (const auto &[parent_path_, sub_list] : sub_lists) {
    const std::filesystem::path &parent_path = parent_path_;

    QTreeWidgetItem *root_item = new QTreeWidgetItem;
    QString sub_path = QString::fromStdString(parent_path.generic_string());
    root_item->setText(0, sub_path);
    d->source_file_tree->addTopLevelItem(root_item);

#ifndef QT_NO_TOOLTIP
    root_item->setToolTip(0, sub_path);
#endif

    std::map<std::filesystem::path, QTreeWidgetItem *> item_map;

    for (const auto &[path_, file_id] : sub_list) {
      std::filesystem::path path = path_;
      std::filesystem::path base;
      std::filesystem::path full_base = path;
      QTreeWidgetItem *last = root_item;
      for (std::filesystem::path part : path.lexically_relative(parent_path)) {
        base /= part;
        full_base /= part;
        auto &item = item_map[base];
        if (!item) {
          item = new QTreeWidgetItem();
          item->setText(0, QString::fromStdString(part.generic_string()));
          last->addChild(item);

#ifndef QT_NO_TOOLTIP
          item->setToolTip(0, QString::fromStdString(full_base.generic_string()));
#endif
        }
        last = item;
      }

      item_map.erase(base);
      d->file_infos.emplace(last, std::make_pair(std::move(path), file_id));

#ifndef QT_NO_TOOLTIP
      last->setToolTip(0, tr("%1 (File id %2)").arg(last->toolTip(0)).arg(file_id));
#endif
    }
  }

  d->source_file_tree->expandAll();
  d->source_file_tree->sortItems(0, Qt::AscendingOrder);

  emit Connected();
}

void FileBrowserView::OnTreeWidgetItemActivated(
    QTreeWidgetItem *item, int) {

  if (auto it = d->file_infos.find(item); it != d->file_infos.end()) {
    emit SourceFileDoubleClicked(it->second.first, it->second.second);
  }
}

}  // namespace mx::gui
