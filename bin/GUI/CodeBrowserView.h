// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QRunnable>
#include <QWidget>

#include <filesystem>
#include <memory>
#include <multiplier/Index.h>
#include <vector>

namespace mx {
class Index;

namespace gui {

class Multiplier;

// The code browser is responsible for displaying one or more files of code.
class CodeBrowserView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);

 public:
  virtual ~CodeBrowserView(void);

  CodeBrowserView(Multiplier &multiplier_, QWidget *parent=nullptr);

  void OpenFile(std::filesystem::path path, FileId file_id);
  void OpenEntities(std::vector<RawEntityId> ids);

  void Clear(void);

 public slots:
  void OnDownloadedFileList(FilePathList files);

 private slots:
  void OnCloseFileViewTab(int index);
  void ScrollToTokenInFile(FileId file_id, RawEntityId scroll_target);
};

// Thread that goes and downloads and structures the relevant code in the
// background.
class LocateEntitiesThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) Q_DECL_FINAL;

  LocateEntitiesThread(void) = delete;

 public:
  virtual ~LocateEntitiesThread(void);

  LocateEntitiesThread(const Index &index_, std::vector<RawEntityId> ids);

 signals:
  void OpenEntityInFile(FileId file_id, RawEntityId scroll_target);
};

}  // namespace gui
}  // namespace mx
