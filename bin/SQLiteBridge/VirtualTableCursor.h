// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once
#include <cstdint>
#include <memory>
#include <multiplier/Result.h>
#include <string>
#include <vector>

struct sqlite3_index_info;
struct sqlite3_context;
struct sqlite3_value;

namespace sqlite_bridge {
class VirtualTableCursor {
public:
  virtual ~VirtualTableCursor() = default;
  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) = 0;
  virtual int Next() = 0;
  virtual int Eof() = 0;
  virtual int Column(sqlite3_context *ctx, int idxCol) = 0;
  virtual mx::Result<std::int64_t, int> RowId() = 0;
};
} // namespace sqlite_bridge