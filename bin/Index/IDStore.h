// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <string_view>

#include <multiplier/Types.h>

namespace rocksdb {
class ColumnFamilyHandle;
class DB;
}  // namespace rocksdb
namespace indexer {

// Persistent mapping from keys to values.
class IDStore {
 private:
  std::unique_ptr<rocksdb::DB> rocks_db;
  rocksdb::ColumnFamilyHandle *cf_handle;

 public:
  ~IDStore(void);
  IDStore(std::filesystem::path workspace_dir);

  mx::RawEntityId GetOrSet(std::string_view key, mx::RawEntityId val);
};

}  // namespace indexer
