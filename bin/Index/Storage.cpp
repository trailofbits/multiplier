// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Storage.h"

#include <blockingconcurrentqueue.h>
#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <multiplier/SQLite.h>
#include <sstream>
#include <system_error>
#include <variant>

namespace indexer {
namespace {

// TODO(pag): This is pretty ugly, but is a design requirement of the current
//            way that the SQLite wrapper works.
static std::string gSQLitePath;

}  // namespace

// These explicit specializations enable the SQLite wrapper to transparently
// serialize then compress, and decompress then deserialize, protobuf Messages
// that are passed as parameter or column binds.

template <>
constexpr auto sqlite::user_serialize_fn<hyde::rt::Bytes> =
    [] (const hyde::rt::Bytes &data) -> sqlite::blob {
      if (data.empty()) {
        return sqlite::blob_view{};
      } else {
        std::string_view sv(reinterpret_cast<const char *>(&(data.front())),
                            data.size());
        return sqlite::blob_view{std::move(sv)};
      }
    };

// Core implementation of persistent storage.
class StorageImpl final : public sqlite::Database<gSQLitePath> {
 private:

  // We insert rows into the database in bulk on a dedicated insertion
  // thread -- this increases throughput massively.
  using QueueItem = std::variant<File, std::nullptr_t>;

  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;
  std::thread bulk_insertion_thread;

  const StorageOptions options;

  void EnableAsynchronousWrites(void);
  void CreateTables(void);
  void CreateBulkInserter(void);

//  // Invoked by the bulk insert thread.
//  void InsertRow(const File &file);

 public:
  StorageImpl(const StorageOptions &options_);
  ~StorageImpl(void);

//  inline void EmplaceRow(File file);
};

StorageImpl::StorageImpl(const StorageOptions &options_)
    : options(options_) {
  if (!options.disable_async_writes) {
    EnableAsynchronousWrites();
  }

  try {
    StorageImpl::TransactionGuard transaction;
    CreateTables();

  } catch (const sqlite::error &error) {
    LOG(FATAL)
        << "Unable to create tables: " << sqlite3_errstr(error.err_code);
  }

  if (!options.disable_async_inserts) {
    CreateBulkInserter();
  }
}

StorageImpl::~StorageImpl(void) {
  insertion_queue.enqueue(nullptr);
  bulk_insertion_thread.join();
}

void StorageImpl::EnableAsynchronousWrites(void) {
  post_connection_hook = [] (sqlite3 *db_handle) {
    sqlite3_exec(db_handle, "pragma synchronous = off",
                 nullptr, nullptr, nullptr);
    sqlite3_exec(db_handle, "pragma journal_mode = memory",
                 nullptr, nullptr, nullptr);
    sqlite3_exec(db_handle, "pragma temp_store = memory",
                 nullptr, nullptr, nullptr);
  };
}

void StorageImpl::CreateTables(void) {
//  // A table that keeps track of IDs.
//  static const char ids_table_query[]
//      = "create table if not exists ids "
//        " (initialized integer primary key not null,"
//        "  next_file_id integer not null,"
//        "  next_job_id integer not null,"
//        "  next_tld_id integer not null,"
//        "  next_entity_id integer) without rowid";
//  query<ids_table_query>();
//
//  static const char files_table_query[]
//      = "create table if not exists files "
//        " (id integer primary key not null,"
//        "  path text unique not null,"
//        "  tokens blob not null) without rowid";
//  query<files_table_query>();
//
//  static const char jobs_table_query[]
//      = "create table if not exists jobs "
//        " (id integer primary key not null,"
//        "  job blob not null) without rowid";
//  query<jobs_table_query>();
//
//  static const char tlds_table_query[]
//      = "create table if not exists tlds "
//        " (id integer primary key not null,"
//        "  job_id integer not null,"
//        "  file_id integer not null) without rowid";
//  query<tlds_table_query>();
//
//  static const char entities_table_query[]
//      = "create table if not exists entities "
//        " (id integer not null,"
//        "  tld_id integer not null,"
//        "  entity blob not null,"
//        "  primary key (id, tld_id)) without rowid";
//  query<entities_table_query>();
//
//  // Initialize the IDs.
//  static const char initialize_ids_table_query[]
//      = "insert or ignore into ids "
//        "(initialized, next_file_id, next_job_id, next_tld_id, next_entity_id) "
//        "values (1, 1, 1, 1, 1)";
//  query<initialize_ids_table_query>();
}

void StorageImpl::CreateBulkInserter(void) {
   std::thread([this] (void) {
    for (;;) {
      QueueItem item;
      insertion_queue.wait_dequeue(item);
      beginTransaction();

      int transaction_size = 0;
      bool should_exit = false;
      do {
        std::visit([this, &should_exit] (const auto &arg) {
          using arg_t = std::decay_t<decltype(arg)>;
          if constexpr (std::is_same_v<std::nullptr_t, arg_t>) {
            // A nullptr_t queue item is our signal to exit.
            should_exit = true;
          } else {
            InsertRow(arg);
          }
        }, item);
        if (should_exit || ++transaction_size == 10000) {
          break;
        }
      } while (insertion_queue.try_dequeue(item)
               || insertion_queue.wait_dequeue_timed(item, 10 * 1000));

      commitTransaction();
      if (should_exit) {
        break;
      }
    }
  }).swap(bulk_insertion_thread);
}

//// Invoked by the bulk insert thread.
//void StorageImpl::InsertRow(const File &file) {
//  static const char add_file_query[]
//      = "insert or ignore into files (id, path, tokens) "
//        "values (?1, ?2, ?3)";
//
//  (void) query<add_file_query>(file.id, file.path, file.tokens);
//}
//
//inline void StorageImpl::EmplaceRow(File file) {
//  if (options.disable_async_inserts) {
//    InsertRow(file);
//  } else {
//    insertion_queue.enqueue(std::move(file));
//  }
//}

Storage::~Storage(void) {}

Storage::Storage(const StorageOptions &options) {
  gSQLitePath = options.path.generic_string();  // TODO(pag): Ugh.
  impl = std::make_shared<StorageImpl>(options);
}

//void Storage::StoreFile(File file) {
//  impl->EmplaceRow(std::move(file));
//}

}  // namespace indexer
