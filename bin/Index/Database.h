// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <functional>
#include <memory>
#include <optional>
#include <string_view>

namespace indexer {

static inline
std::filesystem::path sqlite_dbname(std::filesystem::path path) {
  auto db_path = path.append("db.sqlite");
  return db_path;
}

class DatabaseImpl;

class Database {
 public:
  Database(std::filesystem::path workspace_dir);

  Database(std::string workspace_dir);

  virtual ~Database(void);

  // non-copyable
  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;

  // Store the entity ids and symbol name in sqlite table
  void StoreEntities(uint64_t entity_id, std::string &data);

  // Prepare statement to bind values to and commit
  void Prepare();

  void Commit();

  // Create indexed table that will enable text based seaching
  // on entity table
  void CreateIndexedTable(void);

 private:
  std::unique_ptr<DatabaseImpl> impl;
};

} // namespace indexer
