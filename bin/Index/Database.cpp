// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/SQLiteStore.h>

#include <glog/logging.h>
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
#include <mutex>

#include "Database.h"

namespace indexer {
namespace details {
static std::shared_mutex gWriterMutex;
}  // namespace details

// SymbolInserter prepares the statement, bind values and commit it to sqlite database
class SymbolInserter {
 public:
  SymbolInserter(sqlite::Connection &db_, uint32_t table_id_)
      : db(db_) {
    std::stringstream insert_query;
    insert_query
        << "insert or ignore into entities_fts" << table_id_
        << " (rowid, symbol) values (?1, ?2)";
    try {
      db.Begin();
      stmt = db.Prepare(insert_query.str());
    } catch (sqlite::Error &e) {
      LOG(ERROR) << "Failed to begin transaction " << e.what();
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
    } catch (sqlite::Error &e) {
      LOG(ERROR) << "Failed to commit " << e.what();
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
  using QueueData = std::pair<mx::RawEntityId, std::string>;
  using QueueItem = std::variant<QueueData, std::nullptr_t>;

  DatabaseWriterImpl(std::string &path, uint32_t table_id_)
    : db(std::make_unique<sqlite::Connection>(path)) {

    std::stringstream entities_fts_table;
    entities_fts_table
        << "create virtual table if not exists entities_fts"
        << table_id_ << " using fts5(content='', symbol)";

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
            } else if constexpr (std::is_same_v<QueueData, arg_t>) {
              sym.BindValues(arg.first, std::move(arg.second));
            } else {
              LOG(FATAL)
                  << "Unknown data kind";
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

  ~DatabaseWriterImpl(void) {
    insertion_queue.enqueue(nullptr);
    bulk_insertion_thread.join();
  }

  void StoreEntities(mx::RawEntityId entity_id, const std::string &symbol) {
    insertion_queue.enqueue(QueueData(entity_id, symbol));
  }

  // Get the writer instance and add it to the table if not present
  static std::shared_ptr<DatabaseWriterImpl>
  getWriterInstance(const std::string &path, mx::DeclCategory table);

 private:
  friend class Database;

  std::unique_ptr<sqlite::Connection> db;

  std::thread bulk_insertion_thread;
  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;

  // TODO(pag): Why is this a global variable?
  static std::unordered_map<mx::DeclCategory,
                            std::shared_ptr<DatabaseWriterImpl>>
      gWriters;
};

// Initialize writers table.
//
// TODO(pag): Why is this a global variable?
std::unordered_map<mx::DeclCategory, std::shared_ptr<DatabaseWriterImpl>>
DatabaseWriterImpl::gWriters;

// Get the writer instance and add it to the table if not present
std::shared_ptr<DatabaseWriterImpl>
DatabaseWriterImpl::getWriterInstance(
    const std::string &path, mx::DeclCategory table) {
  
  std::shared_lock<std::shared_mutex> guard(details::gWriterMutex);
  if (gWriters.find(table) != gWriters.end()) {
    return gWriters.at(table);
  }
  return nullptr;
}

// DatabaseReaderImpl implements the database reader interface for querying
// the entities.
class DatabaseReaderImpl {
 public:
  DatabaseReaderImpl(std::filesystem::path workspace_dir)
    : db(std::make_unique<sqlite::Connection>(
          workspace_dir.generic_string())) {}

  std::vector<mx::RawEntityId> QueryEntities(const std::string &name,
                                             uint32_t table_id) {

    std::stringstream select_query;
    select_query
        << "select rowid from entities_fts" << table_id
        << " where entities_fts" << table_id << " match ?1";
    std::vector<mx::RawEntityId> entity_ids;
    try {
      auto stmt = db->Prepare(select_query.str());
      if (!stmt) {
        LOG(ERROR) << "Failed to prepare query statement";
        return entity_ids;
      }

      stmt->BindValues(name);
      while (stmt->ExecuteStep()) {
        auto result = stmt->GetResult();
        mx::RawEntityId entity_id = mx::kInvalidEntityId;
        result.Columns(entity_id);
        entity_ids.push_back(entity_id);
      }

    } catch (sqlite::Error &e) {
      LOG(ERROR) << "Failed to get symbol from database " << e.what();
    }

    return entity_ids;
  }

 private:
  std::unique_ptr<sqlite::Connection> db;
};

Database::Database(std::filesystem::path workspace)
    : reader(std::make_unique<DatabaseReaderImpl>(workspace.generic_string())),
      database_path(workspace.generic_string()) {

  // Initialize database writer at one time. It will create table for each
  // category. This is avoid error when looking for table that has no entry
  // and otherwise table have not existed.
  std::unique_lock<std::shared_mutex> guard(
      details::gWriterMutex, std::defer_lock);
  
  // try acquiring the lock
  if (guard.try_lock()) {
    if (DatabaseWriterImpl::gWriters.empty()) {
      for (auto category : mx::EnumerationRange<mx::DeclCategory>()) {
        DatabaseWriterImpl::gWriters[category] =
            std::make_shared<DatabaseWriterImpl>(
                database_path, static_cast<uint32_t>(category));
      }
    }
  }
}

Database::Database(std::string workspace)
    : reader(std::make_unique<DatabaseReaderImpl>(workspace)),
      database_path(workspace) {}

Database::~Database() {}

void Database::StoreEntities(mx::RawEntityId entity_id,
                             const std::string &symbol,
                             mx::DeclCategory category) {
  if (auto impl = DatabaseWriterImpl::getWriterInstance(
          database_path, category)) {
    impl->StoreEntities(entity_id, symbol);
  }
}

std::vector<mx::RawEntityId> Database::QueryEntities(
    const std::string &name, mx::DeclCategory id) {
  return reader->QueryEntities(name, static_cast<uint32_t>(id));
}

}  // namespace indexer
