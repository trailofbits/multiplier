// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.h>
#include <multiplier/Types.h>

#include <filesystem>
#include <functional>
#include <memory>
#include <optional>
#include <string_view>
#include <unordered_map>
#include <vector>

#include <blockingconcurrentqueue.h>

namespace sqlite {
class Connection;
class Statement;
}  // namespace sqlite
namespace indexer {

class DatabaseWriterImpl;
class DatabaseReaderImpl;

// Database defines the interface for inserting/reading the symbol entries
// from sqlite database. It creates a database reader for querying the
// symbol. The database writer gets instantiated during storing the entities.
class Database {
 public:
  static std::filesystem::path Name(std::filesystem::path path) {
    auto db_path = path.append("db.sqlite");
    return db_path;
  }

  Database(std::filesystem::path workspace);

  Database(std::string workspace);

  virtual ~Database(void);

  // non-copyable
  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;

  void StoreEntities(mx::RawEntityId entity_id, const std::string &data,
                     mx::DeclCategory category);

  std::vector<mx::RawEntityId> QueryEntities(
      const std::string &name, mx::DeclCategory table_id);

 private:
  std::unique_ptr<DatabaseReaderImpl> reader;

  std::string database_path;
};

} // namespace indexer
