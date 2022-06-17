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
#include <unordered_map>

#include <blockingconcurrentqueue.h>

namespace sqlite {
class Connection;
class Statement;
}

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

  void StoreEntities(uint64_t entity_id, std::string &data, uint32_t category);

  void QueryEntities(std::string name, uint32_t table_id,
                     std::function<void(uint64_t, std::string&)> cb);

 private:
  std::unique_ptr<DatabaseReaderImpl> reader;

  std::string database_path;
};

} // namespace indexer
