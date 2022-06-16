// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/SQLiteStore.h>

#include <variant>
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

// Class to insert symbol into database
class SymbolInserter {
 public:
  SymbolInserter(sqlite::Connection &db_) : db(db_) {
    try {
      db.Begin();
      stmt = db.Prepare("insert into entities_fts (symbol, entity_id, kind) values (?1, ?2, ?3)");
    } catch (sqlite::Error &e) {
      std::cerr << "Failed to begin transaction " << e.what();
    }
  }

  template<typename... Args>
  void BindValues(Args... args){
    if (stmt) {
      stmt->BindValues(args ...);
    }
  }

  ~SymbolInserter() {
    try {
      if (stmt) {
        stmt->Execute();
      }
      db.Commit();
    }catch(sqlite::Error &e) {
      std::cerr << "Failed to commit transaction " << e.what();
    }
  }

 private:
  sqlite::Connection &db;
  std::shared_ptr<sqlite::Statement> stmt;

};

Database::Database(std::filesystem::path workspace_dir)
    :  db(std::make_unique<sqlite::Connection>(workspace_dir.generic_string())) {

  static const char entities_fts_table_query[]
      = R"(create virtual table if not exists entities_fts using fts5
           (symbol, entity_id, kind))";
  db->Execute(entities_fts_table_query);

  auto bulk_inserter = [this] (void) {
     for (;;) {
       QueueItem item;
       insertion_queue.wait_dequeue(item);

       SymbolInserter sym(*db.get());

       bool should_exit = false;
       do {
         std::visit([&sym, &should_exit] (const auto &arg) {
           using arg_t = std::decay_t<decltype(arg)>;
           if constexpr (std::is_same_v<std::nullptr_t, arg_t>) {
             should_exit = true;
           } else {
             QueueData item = arg;
             sym.BindValues(std::get<0>(item), std::get<1>(item), std::get<2>(item));
           }
         }, item);

       } while (insertion_queue.try_dequeue(item)
           || insertion_queue.wait_dequeue_timed(item, 10 * 1000));
       if (should_exit) {
         break;
       }
     }
   };

  bulk_insertion_thread = std::thread(bulk_inserter);
}

Database::~Database() {
  insertion_queue.enqueue(nullptr);
  bulk_insertion_thread.join();
}

void Database::StoreEntities(uint64_t entity_id, std::string &symbol, const char *category) {
  insertion_queue.enqueue(std::tuple(symbol, entity_id, category));
}

void Database::QuerySymbol(
    std::string name, std::function<void(uint64_t, std::string&, std::string&)> cb) {
  static const char select_query[] =
      "select * from entities_fts where entities_fts match ?1";

  try {
    auto stmt = db->Prepare(select_query);
    if (!stmt) {
      std::cerr << "Failed to prepare query statement\n";
      return;
    }

    stmt->BindValues(name);

    while(stmt->ExecuteStep()) {
      std::vector<std::string> entry;
      auto result = stmt->GetResult();
      result.Columns(entry);
      if (entry.size() >= 3) {
        auto symbol_name = entry[0];
        auto entity_id = std::strtoull(entry[1].c_str(), 0, 0);
        auto kind = entry[2];
        cb(entity_id, symbol_name, kind);
      }
    }

  } catch(sqlite::Error &e) {
    std::cerr << "Failed to get symbol from database " << e.what();
  }
}

}
