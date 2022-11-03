// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace mx {
enum class DeclCategory : unsigned char;
}  // namespace mx
namespace sqlite {
class Connection;
class Statement;
}  // namespace sqlite
namespace mx {

class SymbolDatabaseImpl;

// Database defines the interface for inserting/reading the symbol entries
// from sqlite database. It creates a database reader for querying the
// symbol. The database writer gets instantiated during storing the entities.
class SymbolDatabase {
 private:
  std::shared_ptr<SymbolDatabaseImpl> d;

 public:
  SymbolDatabase(sqlite::Connection& db);

  ~SymbolDatabase(void);

  // non-copyable
  SymbolDatabase(const SymbolDatabase &) = delete;
  SymbolDatabase &operator=(const SymbolDatabase &) = delete;

  void StoreSymbolName(mx::RawEntityId entity_id, mx::DeclCategory category,
                       std::string data);

  std::vector<mx::RawEntityId> QueryEntities(
      const std::string &name, mx::DeclCategory category);

  void Flush(void);
};

} // namespace indexer
