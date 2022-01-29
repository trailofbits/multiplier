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

// Should we disable aynchronous insertions to the database? Where possible, we
// enqueue stuff to be bulk-inserted into the database in a single transaction.
DEFINE_bool(disable_async_inserts, false,
            "Disable asynchronous inserts into the SQLite database?");

// Should we disable asynchronous mode, and instead synchronize the SQLite
// engine with the underlying storage (typically the file system)?
DEFINE_bool(disable_async_writes, false,
            "Disable asynchronous writes to the underlying storage engine "
            "(e.g. the file system) containing the SQLite database?");

// Path to the database file. If `:memory:` is used, then the database will be
// temporary and live only in memory.
DEFINE_string(database, ":memory:", "Path to the SQLite database");

namespace mx {
namespace {

// Return an absolute path to the storage location for the SQLite database.
static std::string SQLiteDBName(void) {
  CHECK(!FLAGS_database.empty());
  if (FLAGS_database[0] == ':') {
    return FLAGS_database;
  } else {
    std::error_code ec;
    std::filesystem::path path = FLAGS_database;
    path = std::filesystem::weakly_canonical(path, ec);
    CHECK(!ec)
        << "Could not find absolute path for database file '"
        << FLAGS_database << "': " << ec.message();
    return path.generic_string();
  }
}

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
class StorageImpl final : public sqlite::Database<SQLiteDBName> {
 private:

  // We insert rows into the database in bulk on a dedicated insertion
  // thread -- this increases throughput massively.
  using QueueItem = std::variant<File, std::nullptr_t>;

  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;
  std::thread bulk_insertion_thread;

  void EnableAsynchronousWrites(void);
  void CreateTables(void);
  void CreateBulkInserter(void);

  // Invoked by the bulk insert thread.
  void InsertRow(const File &file);

 public:
  StorageImpl(void);
  ~StorageImpl(void);

  inline void EmplaceRow(File file);
};

StorageImpl::StorageImpl(void) {
  if (!FLAGS_disable_async_writes) {
    EnableAsynchronousWrites();
  }

  CreateTables();

  if (!FLAGS_disable_async_inserts) {
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
  // A file's ID will be the `rowid` of this table.
  static const char files_table_query[]
      = "create table if not exists files "
        " (id integer primary key,"
        "  path text unique,"
        "  tokens blob) without rowid";
  query<files_table_query>();

  // A table that keeps track of IDs.
  static const char ids_table_query[]
      = "create table if not exists ids "
        " (initialized integer primary key,"
        "  next_file_id integer)";
  query<ids_table_query>();

  // Initialize the IDs.
  static const char initialize_ids_table_query[]
      = "insert or ignore into ids (initialized, next_file_id) values (1, 1)";
  query<initialize_ids_table_query>();
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

// Invoked by the bulk insert thread.
void StorageImpl::InsertRow(const File &file) {
  static const char add_file_query[]
      = "insert or ignore into files (id, path, tokens) "
        "values (?1, ?2, ?3)";

  (void) query<add_file_query>(file.id, file.path, file.tokens);
}

inline void StorageImpl::EmplaceRow(File file) {
  if (FLAGS_disable_async_inserts) {
    InsertRow(file);
  } else {
    insertion_queue.enqueue(std::move(file));
  }
}

Storage::~Storage(void) {}

Storage::Storage(void)
    : impl(std::make_shared<StorageImpl>()) {}

void Storage::StoreFile(File file) {
  impl->EmplaceRow(std::move(file));
}

// Reserve `num_ids_to_reserve` file ids, starting at or after
// `prev_max_id`.
Result<FileId, std::string> Storage::ReserveFileIds(
    FileId prev_max_id, uint32_t num_ids_to_reserve) {

  // We don't want to allow the first ID returned to ever be `0`.
  if (!prev_max_id) {
    prev_max_id = 1u;
  }

  // Make sure we always reserve at least one.
  if (!num_ids_to_reserve) {
    num_ids_to_reserve = 1u;
  }

  CHECK_LE(prev_max_id, prev_max_id + num_ids_to_reserve);

  static const char increment_id_query[]
      = "update ids "
        "set next_file_id=max(?1, next_file_id + ?2) "
        "where initialized = 1";

  static const char select_incremented_id_query[]
      = "select next_file_id from ids where initialized = 1";

  uint64_t next_file_id = 0;
  std::stringstream err;

  try {
    StorageImpl::TransactionGuard transaction;
    impl->query<increment_id_query>(
        prev_max_id + num_ids_to_reserve,  // Fudge it.
        num_ids_to_reserve);

    auto fetch_row = impl->query<select_incremented_id_query>();
    if (fetch_row(next_file_id)) {
      CHECK_LT(prev_max_id, next_file_id);
      CHECK_LT(num_ids_to_reserve, next_file_id);
      auto ret_val = next_file_id - num_ids_to_reserve;
      CHECK_LT(ret_val, next_file_id);
      return ret_val;
    }
  } catch (const sqlite::error &error) {
    err
        << "Unable to reserve " << num_ids_to_reserve
        << " file ids starting at or after " << prev_max_id << ": "
        << sqlite3_errstr(error.err_code);
    return err.str();
  }

  err << "Unable to reserve " << num_ids_to_reserve
      << " file ids starting at or after " << prev_max_id;
  return err.str();
}

}  // namespace mx
