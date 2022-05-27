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

  using QueryItem = std::variant<DatabaseItem, nullptr_t>;

  DatabaseImpl(std::string path);

  virtual ~DatabaseImpl();

  void Enqueue(QueryItem item);

  void Prepare(const std::string &query);

  void Commit();

  void Bind(uint64_t entity_id, std::string symbol);

  void CreateVirtualTable(void);

 private:
  friend class Database;

  std::unique_ptr<sqlite::Connection> db;
  std::unique_ptr<sqlite::Statement> stmt;
};

DatabaseImpl::DatabaseImpl(std::string path) :
    db(std::make_unique<sqlite::Connection>(path)),
    stmt(nullptr)
{
  static const char entities_table_create[]
      = "create table if not exists entities "
        " (symbol text, entity_id integer)";
  db->Execute(entities_table_create);
}

DatabaseImpl::~DatabaseImpl(void) {}

void DatabaseImpl::Enqueue(QueryItem item) {}

void DatabaseImpl::Prepare(const std::string &query) {
  stmt = db->Prepare(query);
}

void DatabaseImpl::Bind(uint64_t entity_id, std::string symbol) {
  stmt->BindValues(symbol, entity_id);
}

void DatabaseImpl::Commit(void) {
  db->Commit();
}

void DatabaseImpl::CreateVirtualTable(void) {
  static const char entities_fts_table_query[]
      = R"(create virtual table if not exists entities_fts using fts5
           (symbol, content='entities'))";
  db->Execute(entities_fts_table_query);
}

Database::Database(std::filesystem::path workspace_dir)
    : impl(std::make_unique<DatabaseImpl>(workspace_dir.generic_string())) {}

Database::~Database() {}

void Database::StoreEntities(uint64_t entity_id, std::string symbol) {
  impl->Bind(entity_id, symbol);
}

void Database::Prepare() {
  static const char entity_insert_query[]
    = "insert into entities (symbol, entity_id) values (?1, ?2)";
  impl->Prepare(entity_insert_query);
}

void Database::Commit() {
  impl->Commit();
}

void Database::CreateVirtualTable(void) {
  impl->CreateVirtualTable();
}

}
