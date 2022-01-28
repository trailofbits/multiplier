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
#include <optional>
#include <sstream>
#include <system_error>
#include <string>
#include <tuple>
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

template <>
class DatabaseFunctors<hyde::rt::StdStorage> {
 private:
  DBType sql;
  sqlite3 *db_handle{nullptr};

 public:

  DatabaseFunctors(void) {
    DBType::post_connection_hook = [this] (sqlite3 *db_handle) {
      sqlite3_exec(db_handle, "pragma synchronous = off",
                   nullptr, nullptr, nullptr);
      sqlite3_exec(db_handle, "pragma journal_mode = memory",
                   nullptr, nullptr, nullptr);
      sqlite3_exec(db_handle, "pragma temp_store = memory",
                   nullptr, nullptr, nullptr);
      this->db_handle = db_handle;
    };

    // A file's ID will be the `rowid` of this table.
    static const char files_table_query[]
        = "create table if not exists files "
          " (path text primary key,"
          "  tokens blob)";
    sql.query<files_table_query>();
  }

  inline static std::string source_path_bf(const hyde::rt::Bytes &bytes) {
    auto command = flatbuffers::GetRoot<CompileCommand>(bytes.data());
    return command->SourcePath()->str();
  }

  inline static std::string parent_path_bf(const std::string &path_) {
    return std::filesystem::path(path_).parent_path().generic_string();
  }

  std::optional<uint64_t> get_or_create_file_id_bbf(
      const std::string &path, const ::hyde::rt::Bytes &tokens) {
    static const char add_file_query[]
        = "insert or ignore into files (path, tokens) "
          "values (?1, ?2)";

    auto result = sql.query<add_file_query>(path, tokens);
    if (auto code = result.resultCode(); code == SQLITE_DONE) {
      auto row_id = sqlite3_last_insert_rowid(db_handle);
      return static_cast<uint64_t>(row_id);
    } else {
      LOG(ERROR)
          << "Error adding file " << path << " to database: "
          << ::sqlite3_errstr(code);
      return std::nullopt;
    }
  }

  std::vector<std::tuple<std::string, uint64_t>> revive_file_ids_bff(
      uint32_t X) {
    return {};
  }
};

}  // namespace mx
