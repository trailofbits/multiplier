// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once
#include <memory>
#include <multiplier/Result.h>
#include <optional>
#include <sqlite3ext.h>
#include <string>
#include <vector>

struct sqlite3;
struct sqlite3_index_info;
struct sqlite3_context;
struct sqlite3_value;

namespace sqlite_bridge {
class VirtualTableCursor;

class VirtualTable {
public:
  virtual ~VirtualTable() = default;
  virtual std::optional<std::string> Init(sqlite3 *db) = 0;
  virtual int BestIndex(sqlite3_index_info *info) = 0;
  virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int> Open() = 0;
  virtual int FindFunction(int nArg, const std::string &name,
                           void (**pxFunc)(sqlite3_context *, int,
                                           sqlite3_value **),
                           void **ppArg);
  virtual int Update(const std::vector<sqlite3_value *> &args,
                     sqlite3_int64 *row_id);
};
} // namespace sqlite_bridge