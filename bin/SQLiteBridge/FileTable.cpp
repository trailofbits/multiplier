// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include "Adapters.h"
#include "Tables.h"
#include "VirtualTableCursor.h"
#include <multiplier/Types.h>
#include <optional>

namespace sqlite_bridge {

FileTable::FileTable(mx::EntityProvider::Ptr ep) : index(ep) {}

constexpr const char *schema = R"cpp(
CREATE TABLE vtable(
    id INTEGER NOT NULL,
    name TEXT NOT NULL,
    PRIMARY KEY (Id))
)cpp";

std::optional<std::string> FileTable::Init(sqlite3 *db) {
  int err = sqlite3_declare_vtab(db, schema);
  if (err != SQLITE_OK) {
    return sqlite3_errmsg(db);
  }

  return std::nullopt;
}

int FileTable::BestIndex(sqlite3_index_info *info) { return 0; }

using Result = mx::Result<std::unique_ptr<VirtualTableCursor>, int>;
template <> struct TypeAdapter<mx::FilePathList::value_type> {
  int GetColumn(const mx::FilePathList::value_type &obj, sqlite3_context *ctx,
                int idxCol) {
    switch (idxCol) {
    case 0:
      sqlite3_result_int64(ctx, obj.second.value);
      return SQLITE_OK;
    case 1:
      sqlite3_result_text(ctx, obj.first.c_str(), -1, SQLITE_TRANSIENT);
      return SQLITE_OK;
    default:
      return SQLITE_ERROR;
    }
  }

  std::int64_t
  GetRowId(const std::pair<const std::filesystem::path, mx::FileId> &obj) {
    return obj.second.value;
  }
};

Result FileTable::Open() {
  auto cursor{std::make_unique<CollectionAdapter<mx::FilePathList>>(
      index.file_paths())};
  return Result(std::move(cursor));
}
} // namespace sqlite_bridge