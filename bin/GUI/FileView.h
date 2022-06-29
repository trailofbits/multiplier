// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Types.h>
#include <optional>
#include <QWidget>
#include <vector>

#include "Event.h"

// NOTE(pag): Put last for Qt.
#include <filesystem>

namespace mx {
class Index;
namespace gui {

class Multiplier;

class FileView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:
  virtual ~FileView(void);

  FileView(Multiplier &multiplier, std::filesystem::path file_path,
           RawEntityId file_id, QWidget *parent = nullptr);

  void ScrollToToken(RawEntityId eid) const;

 private slots:
  void ActOnTokenPressEvent(EventLocations locs);

 signals:
  void TokenPressEvent(EventSource source, EventLocations locs);
};

}  // namespace gui
}  // namespace mx
