// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <iostream>
#include <sqlite3.h>
#include <thread>

#include <multiplier/SQLiteStore.h>

namespace sqlite {

Error::Error(const std::string &msg, sqlite3 *db)
    : runtime_error("[SQLite Error] " + msg + ": " +
                    std::string(sqlite3_errmsg(db))){};

int32_t Marshal<int32_t>::read(sqlite3_stmt *stmt, int index) {
  return sqlite3_column_int(stmt, index);
}

uint32_t Marshal<uint32_t>::read(sqlite3_stmt *stmt, int index) {
  return sqlite3_column_int(stmt, index);
}

int64_t Marshal<int64_t>::read(sqlite3_stmt *stmt, int index) {
  return sqlite3_column_int64(stmt, index);
}

uint64_t Marshal<uint64_t>::read(sqlite3_stmt *stmt, int index) {
  return sqlite3_column_int64(stmt, index);
}

std::string Marshal<std::string>::read(sqlite3_stmt *stmt, int index) {
  auto len = sqlite3_column_bytes(stmt, index);
  auto data = reinterpret_cast<const char *>(sqlite3_column_blob(stmt, index));
  return std::string(data, len);
}

std::string_view Marshal<std::string_view>::read(sqlite3_stmt *stmt,
                                                 int index) {
  auto len = sqlite3_column_bytes(stmt, index);
  auto data = reinterpret_cast<const char *>(sqlite3_column_blob(stmt, index));
  return std::string_view(data, len);
}

const char *Marshal<const char *>::read(sqlite3_stmt *stmt, int index) {
  return reinterpret_cast<const char *>(sqlite3_column_text(stmt, index));
}

std::nullptr_t Marshal<std::nullptr_t>::read(sqlite3_stmt *, int) { return {}; }

void Marshal<int32_t>::bind(sqlite3_stmt *prepared_stmt, int i, int32_t value) {
  sqlite3_bind_int(prepared_stmt, i + 1, value);
}

void Marshal<uint32_t>::bind(sqlite3_stmt *prepared_stmt, int i,
                             uint32_t value) {
  sqlite3_bind_int(prepared_stmt, i + 1, value);
}

void Marshal<int64_t>::bind(sqlite3_stmt *prepared_stmt, int i, int64_t value) {
  sqlite3_bind_int64(prepared_stmt, i + 1, value);
}

void Marshal<uint64_t>::bind(sqlite3_stmt *prepared_stmt, int i,
                             uint64_t value) {
  sqlite3_bind_int64(prepared_stmt, i + 1, value);
}

void Marshal<std::nullptr_t>::bind(sqlite3_stmt *prepared_stmt, int i,
                                   std::nullptr_t) {
  sqlite3_bind_null(prepared_stmt, i + 1);
}

void Marshal<const char *>::bind(sqlite3_stmt *prepared_stmt, int i,
                                 const char *value) {
  sqlite3_bind_text(prepared_stmt, i + 1, value, strlen(value),
                    SQLITE_TRANSIENT);
}

void Marshal<std::string>::bind(sqlite3_stmt *prepared_stmt, int i,
                                const std::string &value) {
  sqlite3_bind_blob64(prepared_stmt, i + 1, value.data(), value.size(),
                      SQLITE_TRANSIENT);
}

void Marshal<std::string_view>::bind(sqlite3_stmt *prepared_stmt, int i,
                                     std::string_view value) {
  sqlite3_bind_blob64(prepared_stmt, i + 1, value.data(), value.size(),
                      SQLITE_TRANSIENT);
}

Connection::Connection(const std::filesystem::path &db_name, bool readonly,
                       const int busyTimeouts)
    : dbFilename(db_name) {
  sqlite3 *db_handle;
  int ro_flag = readonly ? SQLITE_OPEN_READONLY
                         : (SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);
  const int ret = sqlite3_open_v2(db_name.generic_string().c_str(), &db_handle,
                                  ro_flag | SQLITE_OPEN_NOMUTEX, nullptr);

  sqlite3_exec(db_handle, "pragma synchronous = off", nullptr, nullptr,
               nullptr);
  sqlite3_exec(db_handle, "pragma journal_mode = memory", nullptr, nullptr,
               nullptr);
  sqlite3_exec(db_handle, "pragma temp_store = memory", nullptr, nullptr,
               nullptr);

  db = std::shared_ptr<sqlite3>(db_handle, Deleter{});

  if (ret != SQLITE_OK) {
    throw Error("Failed to open database", db_handle);
  }

  if (busyTimeouts > 0) {
    SetBusyTimeout(busyTimeouts);
  }

  // When the database has been temporarily locked by another process, this
  // tells SQLite to retry the command/query until it succeeds, rather than
  // returning SQLITE_BUSY immediately.
  sqlite3_busy_handler(
      db.get(),
      [](void *, int) {
        std::this_thread::yield();
        return 1;
      },
      nullptr);
};

void Deleter::operator()(sqlite3 *db) { sqlite3_close_v2(db); }

void Deleter::operator()(sqlite3_stmt *stmt) { sqlite3_finalize(stmt); }

void Connection::CreateFunction(
    std::string func_name, unsigned n_args, unsigned flags,
    void (*x_func)(sqlite3_context *, int, sqlite3_value **),
    void (*x_step)(sqlite3_context *, int, sqlite3_value **),
    void (*x_final)(sqlite3_context *), void (*x_destroy)(void *)) {
  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(GetHandler(), func_name.c_str(), n_args,
                                        rflags, nullptr, x_func, x_step,
                                        x_final, x_destroy);
  if (ret != SQLITE_OK) {
    throw Error("Failed to create function", GetHandler());
  }
}

void Connection::DeleteFunction(std::string func_name, unsigned n_args,
                                unsigned flags) {
  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(GetHandler(), func_name.c_str(), n_args,
                                        rflags, nullptr, nullptr, nullptr,
                                        nullptr, nullptr);
  if (ret != SQLITE_OK) {
    throw Error("Failed to create function", GetHandler());
  }
}

void Connection::SetBusyTimeout(const int32_t timeout) {
  const int ret = sqlite3_busy_timeout(GetHandler(), timeout);
  if (ret != SQLITE_OK) {
    throw Error("Failed to set timeout", GetHandler());
  }
}

void Connection::Execute(std::string_view query) {
  auto q = Prepare(query);
  q.Execute();
}

void Connection::Commit(void) { Execute("commit transaction"); }

void Connection::Begin(bool exclusive) {
  if (exclusive) {
    Execute("begin exclusive transaction");
  } else {
    Execute("begin transaction");
  }
}

Transaction::Transaction(Connection &db) : db(db) {}

void Transaction::lock(void) { db.Begin(true); }

void Transaction::unlock(void) { db.Commit(); }

} // namespace sqlite
