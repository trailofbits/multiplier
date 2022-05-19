// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QRunnable>
#include <QTreeWidgetItem>
#include <QWidget>

#include <memory>
#include <multiplier/Index.h>

namespace mx::gui {

class MainWindow;

class DownloadFileListThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  const Index index;
  void run(void);

 public:
  inline explicit DownloadFileListThread(Index index_)
      : index(std::move(index_)) {}

 signals:
  void DownloadedFileList(FilePathList list);
};

class FileBrowserView final : public QWidget {
  Q_OBJECT

 public:
  FileBrowserView(MainWindow *mw, QWidget *parent=nullptr);
  virtual ~FileBrowserView(void);

  void DownloadFileListInBackground(Index index);
  void Clear(void);

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);

 private slots:
  void OnDownloadedFileList(FilePathList files);
  void OnTreeWidgetItemActivated(QTreeWidgetItem *item, int);

 signals:
  void SourceFileDoubleClicked(std::filesystem::path, mx::FileId file_id);
  void Connected(void);
};

}  // namespace mx::gui
