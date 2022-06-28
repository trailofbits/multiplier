// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QRunnable>
#include <QWidget>

#include <memory>
#include <multiplier/Index.h>

QT_BEGIN_NAMESPACE
class QTreeWidgetItem;
QT_END_NAMESPACE

namespace mx {

class Index;

namespace gui {

class Multiplier;
struct FileBrowserConfiguration;

// Shows a tree of files that were indexed. The tree is slightly compressed
// by accumulating together directories that don't contain any indexed source
// files.
class FileBrowserView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);

 public:
  FileBrowserView(FileBrowserConfiguration &config_, QWidget *parent=nullptr);
  virtual ~FileBrowserView(void);

  void Clear(void);
  void Focus(void);

 public slots:
  void OnDownloadedFileList(FilePathList files);

 private slots:
  void OnTreeWidgetItemActivated(QTreeWidgetItem *item, int);
  void OnFilterFileView(const QString &filter);

 signals:
  void SourceFileDoubleClicked(std::filesystem::path, RawEntityId file_id);
  void Connected(void);
};

// Downloads the file list in the background.
class DownloadFileListThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  const Index index;
  void run(void) Q_DECL_FINAL;

 public:
  inline explicit DownloadFileListThread(Index index_)
      : index(std::move(index_)) {}

 signals:
  void DownloadedFileList(FilePathList list);
};

}  // namespace gui
}  // namespace mx
