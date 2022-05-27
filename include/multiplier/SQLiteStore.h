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


#include <sqlite3.h>

namespace sqlite {

class Connection;
class Statement;

class error : public std::runtime_error {
 public:
  error(const std::string& msg) :runtime_error("[SQLite Error] " + msg) {};
};

class QueryResult {
 public:
  QueryResult(Connection& conn, const std::string& query);

  std::vector<std::string> getColumnNames();

  int numColumns();

  bool next(std::vector<std::string>& row);

 private:
  friend class Statement;

  bool next();

  std::shared_ptr<Statement> stmt;
};

class Statement {
 public:

  // Compile and register a sqlite query with the database connection
  Statement(Connection& conn, const std::string& stmt);

  // non-copyable
  Statement(const Statement&) = delete;
  Statement& operator=(const Statement&) = delete;

  ~Statement();

  // Bind values with a sqlite statement. It does not
  // support binding to a blob yet
  template<typename... Args>
  void BindValues(Args... args) {
    if (sizeof...(Args) > num_params) {
      std::string msg = "Too many arguments to bind() " +
          std::to_string(num_params) + " expected " +
          std::to_string(sizeof...(Args)) + " specified";
      throw error(msg);
    }
    size_t i = 0;
    bind_many(i, args...);
    executeStep();
  }

  // Close sqlite statement
  void close() noexcept;

  // Get prepared statement
  sqlite3_stmt* GetPreparedStatement() const;

 private:

  // Execute a sqlite statement
  void executeStep();

  // Binding functions for the statements
  void bind(const size_t i, const int32_t &value);

  void bind(const size_t i, const uint32_t &value);

  void bind(const size_t i, const int64_t &value);

  void bind(const size_t i, const uint64_t &value);

  void bind(const size_t i, const double &value);

  void bind(const size_t i, const std::nullptr_t &value);

  void bind(const size_t i, const char* &value);

  void bind(const size_t i, const std::string &value);

  template<typename T>
  void bind_many(size_t i, T& value) {
    bind(i, value);
    i++;
  }

  template<typename T, typename... Args>
  void bind_many(size_t i, T& value, Args... args) {
    bind(i, value);
    i++;
    bind_many(i, args...);
  }


  std::shared_ptr<sqlite3_stmt> prepareStatement();

  // Database connection instance
  Connection &db;

  // prepared statement cached
  std::shared_ptr<sqlite3_stmt> prepared_stmt;
  std::string query;
  int num_params;

};

class Connection {
 public:

  // Uses sqlite3_open to open the database at the specified path
  Connection(const std::string &filename,
             const int busyTimeouts = 0);

  // Uses sqlite3_open to open the database at the specified path
  Connection(const std::filesystem::path &filename,
             const int busyTimeouts = 0);

  // non-copyable
  Connection(const Connection&) = delete;
  Connection& operator=(const Connection&) = delete;

  // Close the database connection and cleanup all cached statements
  ~Connection() = default;

  // Execute statements without results
  void Execute(const std::string& query);


  // Get prepared statements before executing to database
  std::unique_ptr<Statement> Prepare(const std::string& stmt);

  // Commit transactions to the database
  void Commit(void);

  // Execute a query and fetch the results
  QueryResult ExecuteAndGet(const std::string& query);

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
  std::string GetFilename() const {
      return dbFilename;
  }

  // close database connection
  void Close() noexcept;

  struct Deleter {
    void operator()(sqlite3* db);
  };

 private:
  friend class Statement;

   // Get the raw pointer to SQLite connection handler
  sqlite3* GetHandler() const {
    return db.get();
  }

  std::unique_ptr<sqlite3, Deleter> db;
  std::string dbFilename;
  std::vector<Statement*> stmts;
};

}
