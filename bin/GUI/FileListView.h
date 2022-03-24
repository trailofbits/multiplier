// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QTreeWidgetItem>
#include <QWidget>

#include <memory>
#include <multiplier/API.h>

namespace mx::gui {

class FileListView final : public QWidget {
  Q_OBJECT

public:
  FileListView(QWidget *parent=nullptr);
  virtual ~FileListView() override;

  void Set(FileList files);
  void Clear(void);

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

private slots:
  void OnTreeWidgetItemActivated(QTreeWidgetItem *item, int);

signals:
  void SourceFileDoubleClicked(mx::FileId file_id);
};

}  // namespace mx::gui
