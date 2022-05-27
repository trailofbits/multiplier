// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/SQLiteStore.h>

#include <atomic>
#include <cstring>
#include <cstdio>
#include <cinttypes>
#include <deque>
#include <variant>
#include <iostream>
#include <thread>


#include "Database.h"

namespace indexer {

struct DatabaseItem {
  std::string symbol_name;
  uint64_t entity_id;
};

class DatabaseImpl {
 public:
  DatabaseImpl(std::string path) :
    db(std::make_unique<sqlite::Connection>(path)),
    stmt(nullptr) {
    static const char entities_table_create[]
        = "create table if not exists entities "
          " (entity_id integer, symbol text)";
    db->Execute(entities_table_create);
  }

  virtual ~DatabaseImpl() {}

  // Get the prepared statement from the query string that is ready
  // to bind the values
  void PrepareStatement(const std::string &query) {
    // query string should not be empty
    if (query.empty()) {
      std::cerr << "Failed to prepare statement; empty query string" << std::endl;
      return;
    }
    stmt = db->Prepare(query);
  }

  void CommitToDatabase() {
    db->Commit();
  }

  void BindValues(uint64_t entity_id, std::string &symbol) {
    if (!stmt) {
      std::cerr << "Failed to bind values; no statement to bind with";
      return;
    }
    stmt->BindValues(entity_id, symbol);
  }

  void CreateIndexFromEntityTable(void) {
    static const char entities_fts_table_query[]
        = R"(create virtual table if not exists entities_fts using fts5
             (symbol, content='entities'))";
    db->Execute(entities_fts_table_query);
  }

 private:
  friend class Database;

  std::unique_ptr<sqlite::Connection> db;
  std::unique_ptr<sqlite::Statement> stmt;
};

Database::Database(std::filesystem::path workspace_dir)
    : impl(std::make_unique<DatabaseImpl>(workspace_dir.generic_string())) {}

Database::~Database() {}

void Database::StoreEntities(uint64_t entity_id, std::string &symbol) {
  impl->BindValues(entity_id, symbol);
}

void Database::Prepare() {
  static const char entity_insert_query[]
    = "insert into entities (entity_id, symbol) values (?1, ?2)";
  impl->PrepareStatement(entity_insert_query);
}

void Database::Commit() {
  impl->CommitToDatabase();
}

void Database::CreateIndexedTable(void) {
  impl->CreateIndexFromEntityTable();
}

}
