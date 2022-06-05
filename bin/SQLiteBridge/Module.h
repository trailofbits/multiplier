// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once
#include <memory>
#include <multiplier/Result.h>
#include <string>
#include <vector>

struct sqlite3;
struct sqlite3_module;

namespace sqlite_bridge {
class VirtualTable;

class Module {
public:
  virtual ~Module() = default;
  int Register(sqlite3 *db, const std::string &name);
  virtual mx::Result<std::unique_ptr<VirtualTable>, std::string>
  Create(sqlite3 *db, const std::vector<const char *> &args) = 0;
};
} // namespace sqlite_bridge