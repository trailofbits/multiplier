// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <multiplier/Index.h>
#include <optional>
#include <QPaintEvent>
#include <QRunnable>
#include <QTextBrowser>
#include <QTabWidget>
#include <QUrl>

namespace mx::gui {

class DownloadFileThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  const Index index;
  const FileId file_id;

  void run(void) final;

 public:
  virtual ~DownloadFileThread(void);
  inline explicit DownloadFileThread(Index index_, FileId file_id_)
      : index(std::move(index_)),
        file_id(file_id_) {}

 signals:
  void DownloadedFile(bool failed);
  void RenderedFile(QString html);
};

class FileView final : public QTabWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:
  virtual ~FileView(void);
  FileView(Index index_, std::filesystem::path file_path,
           FileId file_id, QWidget *parent = nullptr);

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  void DownloadFileInBackground(Index index, FileId file_id);
  void InitializeWidgets(void);

 private slots:
  void OnDownloadedFile(bool failed);
  void OnRenderedFile(QString html);
  void OnClickToken(const QUrl &url);

 signals:
  void FragmentTokensClicked(std::vector<RawEntityId> ids);
};

}  // namespace mx::gui
