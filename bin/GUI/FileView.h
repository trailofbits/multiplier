// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <multiplier/Types.h>
#include <optional>
#include <QTabWidget>
#include <vector>

#include "Event.h"

namespace mx {
class Index;
namespace gui {

class Multiplier;

class FileView final : public QTabWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:
  virtual ~FileView(void);

  FileView(Multiplier &multiplier,
           std::filesystem::path file_path,
           FileId file_id,
           QWidget *parent = nullptr);

 private slots:
  MX_DECLARE_DECLARATION_SLOTS

 signals:
  MX_DECLARE_DECLARATION_SIGNALS
};

}  // namespace gui
}  // namespace mx
