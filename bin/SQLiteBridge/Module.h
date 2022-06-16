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

// FIXME(frabert): Only eponymous-only modules support DELETE/INSERT/UPDATE
// queries with the current API.

class Module {
public:
  virtual ~Module() = default;
  virtual int Register(sqlite3 *db, const std::string &name);
  virtual mx::Result<std::unique_ptr<VirtualTable>, std::string>
  Create(sqlite3 *db, const std::vector<const char *> &args) = 0;
};

class EponymousOnlyModule : public Module {
public:
  virtual ~EponymousOnlyModule() = default;
  virtual int Register(sqlite3 *db, const std::string &name) override;
};
} // namespace sqlite_bridge