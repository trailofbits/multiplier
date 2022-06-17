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
#include <sstream>
#include <shared_mutex>

#include "Database.h"


namespace indexer {

namespace details {

inline std::shared_mutex writer_mutex;

}

// SymbolInserter prepares the statement, bind values and commit it to sqlite database
class SymbolInserter {
 public:
  SymbolInserter(sqlite::Connection &db_, uint32_t table_id_) : db(db_) {
    try {
      db.Begin();
      std::stringstream ss;
      ss << "insert into entities_fts" << table_id_ << \
          " (symbol, entity_id) values (?1, ?2)";
      stmt = db.Prepare(ss.str());
    } catch (sqlite::Error &e) {
      std::cerr << "Failed to begin transaction " << e.what() << std::endl;
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
      std::cerr << "Failed to commit " << e.what() << std::endl;
    }
  }

 private:
  sqlite::Connection &db;
  std::shared_ptr<sqlite::Statement> stmt;
};

// DatabaseWriterImpl implements the interface for writing symbol name and entity
// ids to database. It spawns a thread per table for bulk insertion to the database
// It also maintains the the list of active writers per table and uses it to write
// to the table.
//
class DatabaseWriterImpl {
 public:
  using QueueData = std::tuple<std::string, uint64_t>;
  using QueueItem = std::variant<QueueData, std::nullptr_t>;

  DatabaseWriterImpl(std::string path, uint32_t table_id_)
    : db(std::make_unique<sqlite::Connection>(path)) {

    std::stringstream entities_fts_table;
    entities_fts_table << "create virtual table if not exists entities_fts"
        << table_id_ << " using fts5(symbol, entity_id)";

    db->Execute(entities_fts_table.str());
    auto bulk_inserter = [this, table_id_] (void) {
      for (;;) {
        QueueItem item;
        insertion_queue.wait_dequeue(item);

        SymbolInserter sym(*db, table_id_);

        bool should_exit = false;
        do {
          std::visit([&sym, &should_exit] (const auto &arg) {
            using arg_t = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<std::nullptr_t, arg_t>) {
              should_exit = true;
            } else {
              QueueData item = arg;
              sym.BindValues(std::get<0>(item), std::get<1>(item));
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

  ~DatabaseWriterImpl() {
    insertion_queue.enqueue(nullptr);
    bulk_insertion_thread.join();
  }

  void StoreEntities(uint64_t entity_id, std::string &symbol) {
    insertion_queue.enqueue(std::tuple(symbol, entity_id));
  }

  // Get the writer instance and add it to the table if not present
  static std::shared_ptr<DatabaseWriterImpl>
  getWriterInstance(std::string &path, uint32_t table) {
    {
      std::shared_lock<std::shared_mutex> guard(details::writer_mutex);
      if (writers.find(table) != writers.end()) {
        return writers.at(table);
      }
    }

    auto impl = std::make_shared<DatabaseWriterImpl>(path, table);
    std::unique_lock<std::shared_mutex> guard(details::writer_mutex);
    writers[table] = impl;
    return impl;
  }

 private:
  std::unique_ptr<sqlite::Connection> db;

  std::thread bulk_insertion_thread;
  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;

  static std::unordered_map<uint32_t, std::shared_ptr<DatabaseWriterImpl>> writers;
};

// Initialize writers table
std::unordered_map<uint32_t, std::shared_ptr<DatabaseWriterImpl>> DatabaseWriterImpl::writers;

// DatabaseReaderImpl implements the database reader interface for querying the entities.
class DatabaseReaderImpl {
 public:
  DatabaseReaderImpl(std::filesystem::path workspace_dir)
    : db(std::make_unique<sqlite::Connection>(workspace_dir.generic_string())) {}

  void QueryEntities(std::string name, uint32_t table_id,
                     std::function<void(uint64_t, std::string&)> cb) {
    std::stringstream select_query;
    select_query <<  "select * from entities_fts" << table_id
        << " where entities_fts" << table_id << " match ?1";

    try {
      auto stmt = db->Prepare(select_query.str());
      if (!stmt) {
        std::cerr << "Failed to prepare query statement\n";
        return;
      }

      stmt->BindValues(name);

      while(stmt->ExecuteStep()) {
        std::string symbol_name, entity;
        auto result = stmt->GetResult();
        result.Columns(symbol_name, entity);
        auto entity_id = std::strtoull(entity.c_str(), 0, 0);
        std::cerr << entity_id << '\t' << symbol_name << std::endl;
        cb(entity_id, symbol_name);
      }

    } catch(sqlite::Error &e) {
      std::cerr << "Failed to get symbol from database " << e.what() << std::endl;
    }
  }

 private:
  std::unique_ptr<sqlite::Connection> db;
};

Database::Database(std::filesystem::path workspace)
    : reader(std::make_unique<DatabaseReaderImpl>(workspace.generic_string())),
      database_path(workspace.generic_string()) {}

Database::Database(std::string workspace)
    : reader(std::make_unique<DatabaseReaderImpl>(workspace)),
      database_path(workspace) {}

Database::~Database() {}

void Database::StoreEntities(uint64_t entity_id, std::string &symbol, uint32_t category) {
  if (auto impl = DatabaseWriterImpl::getWriterInstance(database_path, category)) {
    impl->StoreEntities(entity_id, symbol);
  }
}

void Database::QueryEntities(std::string name, uint32_t id,
                             std::function<void(uint64_t, std::string&)> cb) {
  reader->QueryEntities(name, id, cb);
}

}
