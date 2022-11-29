// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/SymbolDatabase.h>

#include <array>
#include <cassert>
#include <cstdint>
#include <deque>
#include <multiplier/AST.h>
#include <multiplier/SQLiteStore.h>
#include <sstream>
#include <thread>
#include <variant>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <blockingconcurrentqueue.h>
#pragma GCC diagnostic pop

namespace mx {

struct ExitSignal {};
struct FlushSignal {};
using SymbolToInsert = std::tuple<mx::RawEntityId,
                                  mx::DeclCategory, std::string>;
using QueueItem = std::variant<SymbolToInsert, FlushSignal, ExitSignal>;

// DatabaseWriterImpl implements the interface for writing symbol name and entity
// ids to database. It spawns a thread per table for bulk insertion to the database
// It also maintains the the list of active writers per table and uses it to write
// to the table.
//
class SymbolDatabaseImpl {
 public:
  friend class Database;

  sqlite::Connection &db;

  std::thread bulk_insertion_thread;
  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;

  static constexpr unsigned kNumCategories =
      mx::NumEnumerators(mx::DeclCategory{});

  std::array<std::shared_ptr<sqlite::Statement>, kNumCategories>
      insert_symbol_stmt;

  SymbolDatabaseImpl(sqlite::Connection &db);

  ~SymbolDatabaseImpl(void);
};

SymbolDatabaseImpl::~SymbolDatabaseImpl(void) {
  insertion_queue.enqueue(ExitSignal{});
  bulk_insertion_thread.join();
}

SymbolDatabaseImpl::SymbolDatabaseImpl(sqlite::Connection &db)
    : db(db) {

  for (auto i = 0u; i < kNumCategories; ++i) {
    std::stringstream entities_symbols_table;
    entities_symbols_table
        << "create table if not exists 'mx::entities_symbols_"
        << i << "' (symbol TEXT)";
    db.Execute(entities_symbols_table.str());

    std::stringstream insert_query;
    insert_query
        << "insert or ignore into 'mx::entities_symbols_"
        << i << "' (rowid, symbol) values (?1, ?2)";

    insert_symbol_stmt[i] = db.Prepare(insert_query.str());
  }

  auto bulk_inserter = [this, &db] (void) {
    sqlite::Connection local_db{db.GetFilename()};
    std::array<std::shared_ptr<sqlite::Statement>, kNumCategories>
      local_insert_symbol_stmt;

    for (auto i = 0u; i < kNumCategories; ++i) {
      std::stringstream insert_query;
      insert_query
          << "insert or ignore into 'mx::entities_symbols_"
          << i << "' (rowid, symbol) values (?1, ?2)";

      local_insert_symbol_stmt[i] = local_db.Prepare(insert_query.str());
    }

    for (bool should_exit = false; !should_exit; ) {
      QueueItem item;

      // Go get the first thing.
      insertion_queue.wait_dequeue(item);

      local_db.Begin();

      unsigned transaction_size = 0u;
      bool should_flush = false;

      std::array<unsigned, kNumCategories> num_symbols;
      for (auto &num : num_symbols) {
        num = 0u;
      }

      do {
        std::visit([&, this] (const auto &arg) {
          using arg_t = std::decay_t<decltype(arg)>;
          
          // Exit signal.
          if constexpr (std::is_same_v<ExitSignal, arg_t>) {
            should_exit = true;
            should_flush = true;

          // Flush signal.
          } else if constexpr (std::is_same_v<FlushSignal, arg_t>) {
            should_flush = true;

          // Insert a symbol name.
          } else if constexpr (std::is_same_v<SymbolToInsert, arg_t>) {
            auto i = static_cast<unsigned>(std::get<1>(arg));
            ++num_symbols[i];
            ++transaction_size;
            local_insert_symbol_stmt[i]->BindValues(
                std::get<0>(arg), std::move(std::get<2>(arg)));
            local_insert_symbol_stmt[i]->Execute();

          } else {
            assert(false);
            //LOG(FATAL)
            //    << "Unknown data kind";
          }
        }, item);

        if (transaction_size >= 10000) {
          should_flush = true;
        }

        if (should_flush) {
          break;
        }

      // Try to get the next thing.
      } while (insertion_queue.try_dequeue(item) ||
               insertion_queue.wait_dequeue_timed(item, 10 * 1000));

      for (auto i = 0u; i < kNumCategories; ++i) {
        if (num_symbols[i]) {
          num_symbols[i] = 0u;
        }
      }

      local_db.Commit();
    }
  };

  bulk_insertion_thread = std::thread(bulk_inserter);

  // See: https://en.wikipedia.org/wiki/Unicode_character_property#General_Category
  

  // std::stringstream entities_fts_table;
  // entities_fts_table
  //     << "create virtual table if not exists entities_fts_" << table_id_
  //     << " using fts5(symbol, content='', detail=full, tokenize=\"trigram\")";  // 'unicode61' 'categories' 'L* N* Pc' 
  // db->Execute(entities_fts_table.str());
}

SymbolDatabase::SymbolDatabase(sqlite::Connection &db)
    : d(std::make_shared<SymbolDatabaseImpl>(db)) {}

SymbolDatabase::~SymbolDatabase(void) {}

void SymbolDatabase::Flush(void) {
  d->insertion_queue.enqueue(FlushSignal{});
}

void SymbolDatabase::StoreSymbolName(mx::RawEntityId entity_id,
                               mx::DeclCategory category,
                               std::string symbol) {
  d->insertion_queue.enqueue(
      SymbolToInsert(entity_id, category, std::move(symbol)));
}

std::vector<mx::RawEntityId> SymbolDatabase::QueryEntities(
    const std::string &name, mx::DeclCategory category) {

  auto table_id = static_cast<unsigned>(category);

  std::vector<mx::RawEntityId> entity_ids;
  std::string like_name = name;
  std::replace(like_name.begin(), like_name.end(), '*', '%');

  // Strip off trailing globs.
  while (!like_name.empty() && like_name.back() == '%') {
    like_name.pop_back();
  }

  // Strip off leading globs.
  std::reverse(like_name.begin(), like_name.end());
  while (!like_name.empty() && like_name.back() == '%') {
    like_name.pop_back();
  }
  std::reverse(like_name.begin(), like_name.end());

  if (like_name.empty()) {
    return entity_ids;
  }

  std::stringstream select_query;
  select_query
      << "select rowid, symbol "
      << "from 'mx::entities_symbols_" << table_id << "' "
      << "where symbol like '%' || ?1 || '%'";

  // select_query
  //     << "select rowid from entities_fts_" << table_id
  //     << " where entities_fts" << table_id << " match ?1 || '*'";
  try {
    auto stmt = d->db.Prepare(select_query.str());
    if (!stmt) {
      //LOG(ERROR) << "Failed to prepare query statement";
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
    //LOG(ERROR) << "Failed to get symbol from database " << e.what();
  }

  return entity_ids;
}

}  // namespace indexer
