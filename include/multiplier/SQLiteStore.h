// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <optional>

extern "C" {
struct sqlite3;
struct sqlite3_context;
struct sqlite3_stmt;
struct sqlite3_value;
}  // extern C
namespace sqlite {

class Connection;
class Statement;

class Error : public std::runtime_error {
 public:
  Error(const std::string &msg) : runtime_error("[SQLite Error] " + msg) {}
  Error(const std::string &msg, sqlite3 *db);
};

class QueryResult {
 private:
  void column_dispatcher(int& idx, std::string& arg) {
    arg = getText(idx);
    idx++;
  }

  void column_dispatcher(int& idx, std::string_view& arg) {
    arg = getBlob(idx);
    idx++;
  }

  void column_dispatcher(int& idx, std::nullopt_t& arg) {
    idx++;
  }

  template<typename T, typename = std::enable_if_t<std::is_integral_v<T> || std::is_enum_v<T>>>
  void column_dispatcher(int& idx, T& arg) {
    arg = static_cast<T>(getInt64(idx));
    idx++;
  }

  template<typename T>
  void column_dispatcher(int& idx, std::optional<T>& arg) {
    if(isNull(idx)) {
      arg = {};
      idx++;
      return;
    }
    T value;
    column_dispatcher(idx, value);
    arg = value;
  }

 public:
  ~QueryResult() = default;

  std::vector<std::string> GetColumnNames(void);

  uint32_t NumColumns(void);

  bool Columns(std::vector<std::string> &row);

  template <typename... Ts>
  void Columns(Ts &&...args) {
    if (static_cast<int>(sizeof...(args)) > NumColumns()) {
      throw Error("Failed to read columns; no of arguments are less than column size");
    }

    int idx = 0;
    (column_dispatcher(idx, std::forward<Ts>(args)), ...);
  }

 private:
  friend class Statement;
  friend class Connection;

  QueryResult(Connection &conn, const std::string &query);

  QueryResult(std::shared_ptr<Statement> stmt_);

  int64_t getInt64(int32_t idx);

  std::string getText(int32_t idx);
  std::string_view getBlob(int32_t idx);
  bool isNull(int32_t idx);

  std::shared_ptr<Statement> stmt;
};

class Statement : public std::enable_shared_from_this<Statement> {
 public:

  // Compile and register a sqlite query with the database connection
  Statement(Connection &conn, const std::string &stmt);

  // non-copyable
  Statement(const Statement &) = delete;
  Statement &operator=(const Statement &) = delete;

  ~Statement();

  // Bind values with a sqlite statement. It does not
  // support binding to a blob yet
  template<typename... Args>
  void BindValues(Args... args) {
    if (sizeof...(Args) > num_params) {
      std::string msg = "Too many arguments to bind() " + std::to_string(num_params) +
          " expected " + std::to_string(sizeof...(Args)) + " specified";
      throw Error(msg);
    }
    size_t i = 0;
    reset();
    bind_many(i, args...);
  }

  void Execute(void);

  bool ExecuteStep(void);

  QueryResult GetResult(void);

  void Close() noexcept;

  void Reset();

 private:
  friend class QueryResult;

  int tryExecuteStep(void);

  // Binding functions for the statements
  void bind(const size_t i, const int32_t &value);

  void bind(const size_t i, const uint32_t &value);

  void bind(const size_t i, const int64_t &value);

  void bind(const size_t i, const uint64_t &value);

  void bind(const size_t i, const double &value);

  void bind(const size_t i, const std::nullptr_t &value);

  void bind(const size_t i, const char *&value);

  void bind(const size_t i, const std::string &value);

  void bind(const size_t i, const std::string_view &value);

  template<typename T>
  void bind(const size_t i, const std::optional<T> &value) {
    if(value.has_value()) {
      bind(i, value.value());
    } else {
      bind(i, nullptr);
    }
  }

  void reset();

  template<typename T>
  void bind_many(size_t i, T &value) {
    bind(i, value);
  }

  template<typename T, typename... Args>
  void bind_many(size_t i, T &value, Args... args) {
    bind(i, value);
    i++;
    bind_many(i, args...);
  }


  sqlite3_stmt *prepareStatement(void);

  // Database connection instance
  Connection &db;

  // prepared statement cached
  std::shared_ptr<sqlite3_stmt> prepared_stmt;
  std::string query;
  unsigned num_params;
};

class Transaction {
 public:
  Transaction(Connection &db);
  void lock();
  void unlock();

 private:
  Connection &db;
};

class Connection {
 public:

  // Uses sqlite3_open to open the database at the specified path
  Connection(const std::filesystem::path &filename,
             bool readonly = false,
             const int busyTimeouts = 0);

  // non-copyable
  Connection(const Connection &) = delete;
  Connection &operator=(const Connection &) = delete;

  // Close the database connection and cleanup all cached statements
  ~Connection(void) = default;

  // Execute statements without results
  void Execute(const std::string &query);

  // Get prepared statements before executing to database
  std::shared_ptr<Statement> Prepare(const std::string &stmt);

  // Begin transactions to the database
  void Begin(bool exclusive = false);

  // Commit transactions to the database
  void Commit(void);

  // Execute a query and fetch the results
  QueryResult ExecuteAndGet(const std::string &query);

   // Set a busy timeout when the table is locked.
  void SetBusyTimeout(const int timeouts);

  // Attach custom function to your sqlite database
  void CreateFunction(std::string func_name, unsigned n_args, unsigned flags,
                      void (*x_func)(sqlite3_context *, int, sqlite3_value **),
                      void (*x_step)(sqlite3_context *, int, sqlite3_value **),
                      void (*x_final)(sqlite3_context *),
                      void (*x_destroy)(void *));

  // Delete custom function from the sqlite database
  void DeleteFunction(std::string func_name, unsigned n_args, unsigned flags);

   // Get the filename used to open the database
  std::string GetFilename(void) const {
      return dbFilename;
  }

  // close database connection
  void Close(void) noexcept;

  struct Deleter {
    void operator()(sqlite3 *db);
  };

 private:
  friend class Statement;

   // Get the raw pointer to SQLite connection handler
  sqlite3 *GetHandler(void) const {
    return db.get();
  }

  std::unique_ptr<sqlite3, Deleter> db;
  std::string dbFilename;
  std::vector<Statement*> stmts;
};

}
