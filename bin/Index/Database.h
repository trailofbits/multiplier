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

class DatabaseImpl;

// Database defines the interface for inserting/reading the symbol entries
// from sqlite database. It creates a database reader for querying the
// symbol. The database writer gets instantiated during storing the entities.
class Database {
 private:
  std::shared_ptr<DatabaseImpl> d;

 public:
  Database(std::filesystem::path workspace_dir);

  ~Database(void);

  // non-copyable
  Database(const Database &) = delete;
  Database &operator=(const Database &) = delete;

  void StoreSymbolName(mx::RawEntityId entity_id, mx::DeclCategory category,
                       std::string data);

  std::vector<mx::RawEntityId> QueryEntities(
      const std::string &name, mx::DeclCategory category);

  void Flush(void);
};

} // namespace indexer
