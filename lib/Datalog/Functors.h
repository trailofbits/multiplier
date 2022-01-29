// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>
#include <multiplier/SQLite.h>

#include <array>
#include <cstdint>
#include <filesystem>
#include <blockingconcurrentqueue.h>
#include <optional>
#include <sstream>
#include <system_error>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <flatbuffers/flatbuffers.h>
#include <drlojekyll/Runtime/Runtime.h>

DEFINE_string(database, ":memory:", "Path to the SQLite database");

namespace mx {
namespace {

static std::string SQLiteDBName(void) {
  CHECK(!FLAGS_database.empty());
  if (FLAGS_database[0] == ':') {
    return FLAGS_database;
  } else {
    std::error_code ec;
    std::filesystem::path path =
        std::filesystem::weakly_canonical(FLAGS_database, ec);
    CHECK(!ec)
        << "Could not find absolute path for database file '"
        << FLAGS_database << "': " << ec.message();
    return path.generic_string();
  }
}

using DBType = sqlite::Database<SQLiteDBName>;

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

struct File {
  FileId id;
  std::string path;
  hyde::rt::Bytes tokens;
};

template <>
class DatabaseFunctors<hyde::rt::StdStorage> {
 private:
  DBType sql;
  // We insert rows into the database in bulk on a dedicated insertion
  // thread -- this increases throughput massively.
  using QueueItem
      = std::variant<File, std::nullptr_t>;
  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;
  std::thread bulk_insertion_thread;

 public:

  DatabaseFunctors(void) {
    DBType::post_connection_hook = [] (sqlite3 *db_handle) {
      sqlite3_exec(db_handle, "pragma synchronous = off",
                   nullptr, nullptr, nullptr);
      sqlite3_exec(db_handle, "pragma journal_mode = memory",
                   nullptr, nullptr, nullptr);
      sqlite3_exec(db_handle, "pragma temp_store = memory",
                   nullptr, nullptr, nullptr);
    };

    // A file's ID will be the `rowid` of this table.
    static const char files_table_query[]
        = "create table if not exists files "
          " (id integer primary key,"
          "  path text unique,"
          "  tokens blob) without rowid";
    sql.query<files_table_query>();

    // A table that keeps track of IDs.
    static const char ids_table_query[]
        = "create table if not exists ids "
          " (initialized integer primary key,"
          "  next_file_id integer)";
    sql.query<ids_table_query>();

    // Initialize the IDs.
    static const char initialize_ids_table_query[]
        = "insert or ignore into ids (initialized, next_file_id) values (1, 1)";
    sql.query<initialize_ids_table_query>();

    auto bulk_inserter = [this] (void) {
      for (;;) {
        QueueItem item;
        insertion_queue.wait_dequeue(item);
        sql.beginTransaction();

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

        sql.commitTransaction();
        if (should_exit) {
          break;
        }
      }
    };
    bulk_insertion_thread = std::thread(bulk_inserter);
  }

  ~DatabaseFunctors(void) {
    insertion_queue.enqueue(nullptr);
    bulk_insertion_thread.join();
  }

  // Invoked by the bulk insert thread.
  void InsertRow(const File &file) {
    static const char add_file_query[]
        = "insert or ignore into files (id, path, tokens) "
          "values (?1, ?2, ?3)";

    auto result = sql.query<add_file_query>(
        file.id, file.path, file.tokens);
  }

  // Allocate `reserve_size` file IDs, where we expect the last allocated
  // reservation to end at `last_id`.
  std::optional<FileId> allocate_file_ids_bbf(
      FileId last_id, uint32_t reserve_size) {

    static const char increment_id_query[]
        = "update ids "
          "set next_file_id=max(?1, next_file_id + ?2) "
          "where initialized = 1";

    static const char select_incremented_id_query[]
        = "select next_file_id from ids where initialized = 1";

    uint64_t next_file_id = 0;

    try {
      DBType::TransactionGuard transaction;
      sql.query<increment_id_query>(
          last_id + reserve_size,  // Fudge it.
          reserve_size);

      auto fetch_row = sql.query<select_incremented_id_query>();
      if (fetch_row(next_file_id)) {
        CHECK_LT(last_id, next_file_id);
        CHECK_LT(reserve_size, next_file_id);
        return next_file_id - reserve_size;
      }
    } catch (const sqlite::error &error) {
      LOG(ERROR)
          << "Unable to reserve " << reserve_size << " file ids: "
          << sqlite3_errstr(error.err_code);
      return std::nullopt;
    }

    LOG(ERROR)
        << "Unable to reserve " << reserve_size << " file ids";
    return std::nullopt;
  }

  // Persist a file by adding it to the bulk inserter thread.
  bool persist_file_bbb(FileId id, std::string path, ::hyde::rt::Bytes tokens) {
    File file;
    file.id = id;
    file.path = std::move(path);
    file.tokens = std::move(tokens);
    insertion_queue.enqueue(std::move(file));
    return true;
  }

  std::vector<std::tuple<FileId, std::string>> revive_file_ids_ffb(
      uint32_t X) {
    return {};
  }

//  inline static std::string source_path_bf(const hyde::rt::Bytes &bytes) {
//    auto command = flatbuffers::GetRoot<CompileCommand>(bytes.data());
//    return command->SourcePath()->str();
//  }
//
//  inline static std::string parent_path_bf(const std::string &path_) {
//    return std::filesystem::path(path_).parent_path().generic_string();
//  }
};

}  // namespace mx
