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
#include <QTabWidget>

#include "CodeView.h"

namespace mx::gui {

class FileView final : public QTabWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:
  virtual ~FileView(void);
  FileView(Index index_, std::filesystem::path file_path,
           FileId file_id, const CodeTheme &theme_=CodeTheme::DefaultTheme(),
           QWidget *parent = nullptr);

 private slots:
  void OnDeclarationsClicked(std::vector<RawEntityId> ids, Qt::MouseButton);

 signals:
  void DeclarationsClicked(std::vector<RawEntityId> ids, Qt::MouseButton);
};

}  // namespace mx::gui
