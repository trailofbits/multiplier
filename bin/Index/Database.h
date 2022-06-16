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

#include <blockingconcurrentqueue.h>

namespace sqlite {
class Connection;
class Statement;
}

namespace indexer {

class Database {
 public:
  using QueueData = std::tuple<std::string, uint64_t, const char*>;
  using QueueItem = std::variant<QueueData, std::nullptr_t>;

  static std::filesystem::path Name(std::filesystem::path path) {
    auto db_path = path.append("db.sqlite");
    return db_path;
  }

  Database(std::filesystem::path workspace_dir);

  Database(std::string workspace_dir);

  virtual ~Database(void);

  // non-copyable
  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;

  // Store the entity ids and symbol name in sqlite table
  void StoreEntities(uint64_t entity_id, std::string &data, const char*);

  void QuerySymbol(std::string name, std::function<
                   void(uint64_t, std::string&, std::string&)> cb);

 private:
  std::unique_ptr<sqlite::Connection> db;

  std::thread bulk_insertion_thread;
  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;

  //std::map<uint32_t, std::string> table_map;
};

} // namespace indexer
