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

class EventLocations;
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

  // Open a file in a tab.
  //
  // NOTE(pag): This does not set the file to be the active widget.
  void OpenFile(std::filesystem::path path, FileId file_id, bool show=false);

  // Request for one or more entities to be opened.
  void OpenEntities(const EventLocations &);

  void Clear(void);

 public slots:
  void OnDownloadedFileList(FilePathList files);

 private slots:
  void OnCloseFileViewTab(int index);

  // When a tab is changed.
  void OnChangeTab(int index);

  // Scroll to a specific target location in a file. If the file isn't open yet
  // then open it. If it is open but not the active view, then set it to the
  // active view.
  void ScrollToTokenInFile(FileId file_id, RawEntityId scroll_target,
                           unsigned counter);

 signals:
  void CurrentFile(FileId file_id);
};

// Thread that goes and downloads and structures the relevant code in the
// background.
class LocateEntitiesThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void RunOnToken(Token file_tok);
  void run(void) Q_DECL_FINAL;

  LocateEntitiesThread(void) = delete;

 public:
  virtual ~LocateEntitiesThread(void);

  LocateEntitiesThread(const Index &index_, const EventLocations &ids,
                       unsigned counter);

 signals:
  void OpenEntityInFile(FileId file_id, RawEntityId scroll_target,
                        unsigned counter);
};

}  // namespace gui
}  // namespace mx
