// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Module.h"

namespace sqlite_bridge {
class MultiplierModule : public Module {
public:
  virtual ~MultiplierModule() = default;
  virtual mx::Result<std::unique_ptr<VirtualTable>, std::string>
  Create(sqlite3 *db, const std::vector<const char *> &args) override;
};
} // namespace sqlite_bridge