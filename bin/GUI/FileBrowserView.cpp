// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QThreadPool>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <filesystem>
#include <map>
#include <multiplier/Types.h>
#include <set>
#include <unordered_map>
#include <utility>

#include "FileBrowserView.h"
#include "MainWindow.h"

namespace mx::gui {

struct FileBrowserView::PrivateData final {
  QVBoxLayout *layout{nullptr};
  QLineEdit *filter_box{nullptr};
  QTreeWidget *source_file_tree{nullptr};
  std::unordered_map<
      QTreeWidgetItem *,
      std::pair<std::filesystem::path, mx::FileId>> file_infos;
};

void DownloadFileListThread::run(void) {
  emit DownloadedFileList(index.file_paths());
}

FileBrowserView::FileBrowserView(MainWindow *mw, QWidget *parent)
    : QWidget(parent),
      d(new PrivateData) {

  connect(this, &FileBrowserView::Connected,
          mw, &MainWindow::OnConnected);

  connect(this, &FileBrowserView::SourceFileDoubleClicked,
          mw, &MainWindow::OnSourceFileDoubleClicked);

  InitializeWidgets();
}

FileBrowserView::~FileBrowserView(void) {}

void FileBrowserView::Clear(void) {
  d->source_file_tree->clear();
}

void FileBrowserView::DownloadFileListInBackground(Index index) {
  auto downloader = new DownloadFileListThread(std::move(index));
  downloader->setAutoDelete(true);

  connect(downloader, &DownloadFileListThread::DownloadedFileList,
          this, &FileBrowserView::OnDownloadedFileList);
  QThreadPool::globalInstance()->start(downloader);
}

void FileBrowserView::InitializeWidgets(void) {
  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);

  auto filter_area = new QWidget;
  auto filter_layout = new QHBoxLayout;
  filter_area->setLayout(filter_layout);

  d->filter_box = new QLineEdit;
  filter_layout->addWidget(new QLabel(tr("Filter:")));
  filter_layout->addWidget(d->filter_box);
  d->layout->addWidget(filter_area);

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
  if (!text.size()) {
    for (auto &[item, path_id] : d->file_infos) {
      item->setHidden(false);
    }
  } else {
    for (auto &[item, path_id] : d->file_infos) {
      QString path = QString::fromStdString(path_id.first.generic_string());
      item->setHidden(!path.contains(text));
    }
  }

  update();
}

void FileBrowserView::OnDownloadedFileList(FilePathList files) {
  QTreeWidgetItem *root_item = nullptr;

  std::set<std::filesystem::path> has_files;
  for (const auto &[path, file_id] : files) {
    auto base = path.root_path();
    for (std::filesystem::path part : path.parent_path()) {
      base /= part;  // A bit redundant, but follow the same process throughout.
    }
    has_files.emplace(std::move(base));
  }

  // Group the paths into folders that have at least one file in them. This is
  // so that we don't have to see crazy deep folder trees all the time.
  std::map<std::filesystem::path, FilePathList> sub_lists;
  for (auto [path, file_id] : files) {
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
  for (const auto &[parent_path, sub_list] : sub_lists) {
    QTreeWidgetItem *root_item = new QTreeWidgetItem;
    QString sub_path = QString::fromStdString(parent_path.generic_string());
    root_item->setText(0, sub_path);
    d->source_file_tree->addTopLevelItem(root_item);

#ifndef QT_NO_TOOLTIP
    root_item->setToolTip(0, sub_path);
#endif

    std::map<std::filesystem::path, QTreeWidgetItem *> item_map;

    for (const auto &[path, file_id] : sub_list) {
      std::filesystem::path base;
      std::filesystem::path full_base = path;
      QTreeWidgetItem *last = root_item;
      for (std::filesystem::path part : path.lexically_relative(parent_path)) {
        base /= part;
        full_base /= part;
        auto &item = item_map[base.generic_string()];
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
      d->file_infos.emplace(last, std::make_pair(std::move(path), file_id));
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
