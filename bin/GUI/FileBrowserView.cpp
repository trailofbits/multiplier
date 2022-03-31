// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <QHeaderView>
#include <QThreadPool>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <filesystem>
#include <map>
#include <unordered_map>

#include "FileBrowserView.h"
#include "MainWindow.h"

namespace mx::gui {

struct FileBrowserView::PrivateData final {
  QVBoxLayout *layout{nullptr};
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

  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);

  d->source_file_tree = new QTreeWidget;
  d->layout->addWidget(d->source_file_tree);

  setWindowTitle(tr("File Browser"));
  setLayout(d->layout);

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
  d->source_file_tree->setHeaderHidden(true);
  d->source_file_tree->setColumnCount(1);
  d->source_file_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->source_file_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->source_file_tree->header()->setStretchLastSection(false);

  connect(d->source_file_tree, &QTreeWidget::itemActivated, this,
          &FileBrowserView::OnTreeWidgetItemActivated);
}

void FileBrowserView::OnDownloadedFileList(FilePathList files) {
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
    d->file_infos.emplace(last, std::make_pair(std::move(path), file_id));
  }

  d->source_file_tree->addTopLevelItem(root_item);
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
