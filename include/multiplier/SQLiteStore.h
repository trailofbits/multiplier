// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <optional>
#include <sqlite3.h>
#include <string>
#include <vector>

namespace sqlite {

class Connection;
class Statement;

template <typename T, typename Enable = void> struct Marshal;

template <> struct Marshal<int32_t> {
  static void bind(sqlite3_stmt *stmt, int index, int32_t value);
  static int32_t read(sqlite3_stmt *stmt, int index);
};

template <> struct Marshal<uint32_t> {
  static void bind(sqlite3_stmt *stmt, int index, uint32_t value);
  static uint32_t read(sqlite3_stmt *stmt, int index);
};

template <> struct Marshal<int64_t> {
  static void bind(sqlite3_stmt *stmt, int index, int64_t value);
  static int64_t read(sqlite3_stmt *stmt, int index);
};

template <> struct Marshal<uint64_t> {
  static void bind(sqlite3_stmt *stmt, int index, uint64_t value);
  static uint64_t read(sqlite3_stmt *stmt, int index);
};

template <typename T>
struct Marshal<T, std::enable_if_t<std::is_integral_v<T>>> {
  static void bind(sqlite3_stmt *stmt, int index, T value) {
    Marshal<int64_t>::bind(stmt, index, static_cast<int64_t>(value));
  }

  static uint64_t read(sqlite3_stmt *stmt, int index) {
    return static_cast<T>(Marshal<int64_t>::read(stmt, index));
  }
};

template <> struct Marshal<std::string> {
  static void bind(sqlite3_stmt *stmt, int index, const std::string &value);
  static std::string read(sqlite3_stmt *stmt, int index);
};

template <> struct Marshal<std::string_view> {
  static void bind(sqlite3_stmt *stmt, int index, std::string_view value);
  static std::string_view read(sqlite3_stmt *stmt, int index);
};

template <> struct Marshal<const char *> {
  static void bind(sqlite3_stmt *stmt, int index, const char *value);
  static const char *read(sqlite3_stmt *stmt, int index);
};

template <> struct Marshal<std::nullptr_t> {
  static void bind(sqlite3_stmt *stmt, int index, std::nullptr_t);
  static std::nullptr_t read(sqlite3_stmt *stmt, int index);
};

class Error : public std::runtime_error {
 public:
  Error(const std::string &msg) : runtime_error("[SQLite Error] " + msg) {}
  Error(const std::string &msg, sqlite3 *db);
};

struct Deleter {
  void operator()(sqlite3 *db);
  void operator()(sqlite3_stmt *stmt);
};

template <typename... Columns> class Query final {
  std::shared_ptr<sqlite3_stmt> stmt;
  std::shared_ptr<sqlite3> db;
  int param_count;

  template <typename... Params, size_t... Is>
  void bind(std::index_sequence<Is...>, Params... params) const {
    (Marshal<Params>::bind(stmt.get(), Is, params), ...);
  }

  static sqlite3_stmt *clone(sqlite3 *db, sqlite3_stmt *s) {
    sqlite3_stmt *new_stmt;
    if (sqlite3_prepare_v2(db, sqlite3_sql(s), -1, &new_stmt, nullptr) !=
        SQLITE_OK) {
      throw Error("Error cloning statement", db);
    }
    return new_stmt;
  }

 public:
  Query(std::shared_ptr<sqlite3_stmt> stmt, std::shared_ptr<sqlite3> db)
      : stmt(stmt), db(db),
        param_count(sqlite3_bind_parameter_count(stmt.get())) {
    if (sizeof...(Columns) != sqlite3_column_count(stmt.get())) {
      throw Error("Invalid number of columns");
    }
  }
  Query(const Query &) = delete;
  Query &operator=(const Query &) = delete;
  Query(Query &&) = default;
  Query &operator=(Query &&) = default;

  template <typename... Params> void Bind(Params... params) const {
    if (sizeof...(Params) != param_count) {
      throw Error("Invalid number of parameters");
    }
    bind(std::make_index_sequence<sizeof...(Params)>(), params...);
  }

  class iterator {
    std::shared_ptr<sqlite3_stmt> stmt;
    std::shared_ptr<sqlite3> db;

    std::tuple<Columns...> res;

    template <typename T> static void putInto(T &dest, T value) {
      dest = value;
    }

    template <size_t... Is> void read(std::index_sequence<Is...>) {
      (putInto(std::get<Is>(res), Marshal<Columns>::read(stmt.get(), Is)), ...);
    }

    void advance() {
      auto ret = sqlite3_step(stmt.get());
      if (ret == SQLITE_DONE) {
        stmt = nullptr;
      } else if (ret == SQLITE_ROW) {
        read(std::make_index_sequence<sizeof...(Columns)>());
      } else {
        throw Error("Error while enumerating results",
                    sqlite3_db_handle(stmt.get()));
      }
    }

   public:
    iterator(std::shared_ptr<sqlite3_stmt> stmt, std::shared_ptr<sqlite3> db)
        : stmt(stmt), db(db) {
      advance();
    }

    bool operator==(const iterator &b) const { return stmt == b.stmt; }

    bool operator!=(const iterator &b) const { return stmt != b.stmt; }

    const std::tuple<Columns...> &operator*() const { return res; }

    iterator &operator++() {
      advance();
      return *this;
    }

    const std::tuple<Columns...> *operator->() const { return &res; }

    operator bool() const { return stmt != nullptr; }
  };

  iterator begin() const {
    sqlite3_reset(stmt.get());
    return iterator(stmt, db);
  }
  iterator end() const { return iterator(nullptr, nullptr); }
};

template <typename Column> class Query<Column> final {
  std::shared_ptr<sqlite3_stmt> stmt;
  std::shared_ptr<sqlite3> db;
  int param_count;

  template <typename... Params, size_t... Is>
  void bind(std::index_sequence<Is...>, Params... params) const {
    (Marshal<Params>::bind(stmt.get(), Is, params), ...);
  }

  static sqlite3_stmt *clone(sqlite3 *db, sqlite3_stmt *s) {
    sqlite3_stmt *new_stmt;
    if (sqlite3_prepare_v2(db, sqlite3_sql(s), -1, &new_stmt, nullptr) !=
        SQLITE_OK) {
      throw Error("Error cloning statement", db);
    }
    return new_stmt;
  }

 public:
  Query(std::shared_ptr<sqlite3_stmt> stmt, std::shared_ptr<sqlite3> db)
      : stmt(stmt), db(db),
        param_count(sqlite3_bind_parameter_count(stmt.get())) {
    if (1 != sqlite3_column_count(stmt.get())) {
      throw Error("Invalid number of columns");
    }
  }
  Query(const Query &) = delete;
  Query &operator=(const Query &) = delete;
  Query(Query &&) = default;
  Query &operator=(Query &&) = default;

  template <typename... Params> void Bind(Params... params) const {
    if (sizeof...(Params) != param_count) {
      throw Error("Invalid number of parameters");
    }
    bind(std::make_index_sequence<sizeof...(Params)>(), params...);
  }

  class iterator {
    std::shared_ptr<sqlite3_stmt> stmt;
    std::shared_ptr<sqlite3> db;

    Column res;

    void advance() {
      auto ret = sqlite3_step(stmt.get());
      if (ret == SQLITE_DONE) {
        stmt = nullptr;
      } else if (ret == SQLITE_ROW) {
        res = Marshal<Column>::read(stmt.get(), 0);
      } else {
        throw Error("Error while enumerating results",
                    sqlite3_db_handle(stmt.get()));
      }
    }

   public:
    iterator(std::shared_ptr<sqlite3_stmt> stmt, std::shared_ptr<sqlite3> db)
        : stmt(stmt), db(db) {
      advance();
    }

    bool operator==(const iterator &b) const { return stmt == b.stmt; }

    bool operator!=(const iterator &b) const { return stmt != b.stmt; }

    const Column &operator*() const { return res; }

    iterator &operator++() {
      advance();
      return *this;
    }

    const Column *operator->() const { return &res; }

    operator bool() const { return stmt != nullptr; }
  };

  iterator begin() const {
    sqlite3_reset(stmt.get());
    return iterator(stmt, db);
  }
  iterator end() const { return iterator(nullptr, nullptr); }
};

template <> class Query<> final {
  std::shared_ptr<sqlite3_stmt> stmt;
  std::shared_ptr<sqlite3> db;
  int param_count;

  template <typename... Params, size_t... Is>
  void bind(std::index_sequence<Is...>, Params... params) const {
    (Marshal<Params>::bind(stmt.get(), Is, params), ...);
  }

  static sqlite3_stmt *clone(sqlite3 *db, sqlite3_stmt *s) {
    sqlite3_stmt *new_stmt;
    if (sqlite3_prepare_v2(db, sqlite3_sql(s), -1, &new_stmt, nullptr) !=
        SQLITE_OK) {
      throw Error("Error cloning statement", db);
    }
    return new_stmt;
  }

 public:
  Query(std::shared_ptr<sqlite3_stmt> stmt, std::shared_ptr<sqlite3> db)
      : stmt(stmt), db(db),
        param_count(sqlite3_bind_parameter_count(stmt.get())) {
    if (0 != sqlite3_column_count(stmt.get())) {
      throw Error("Invalid number of columns");
    }
  }
  Query(const Query &) = delete;
  Query &operator=(const Query &) = delete;
  Query(Query &&) = default;
  Query &operator=(Query &&) = default;

  template <typename... Params> void Bind(Params... params) const {
    if (sizeof...(Params) != param_count) {
      throw Error("Invalid number of parameters");
    }
    bind(std::make_index_sequence<sizeof...(Params)>(), params...);
  }

  void Execute() const {
    sqlite3_reset(stmt.get());
    if (sqlite3_step(stmt.get()) != SQLITE_DONE) {
      throw Error("Error executing query", db.get());
    }
  }
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
  Connection(const std::filesystem::path &filename, bool readonly = false,
             const int busyTimeouts = 0);

  // non-copyable
  Connection(const Connection &) = delete;
  Connection &operator=(const Connection &) = delete;

  // Close the database connection and cleanup all cached statements
  ~Connection(void) = default;

  // Execute statements without results
  void Execute(std::string_view query);

  // Get prepared statements before executing to database
  template <typename... Columns>
  Query<Columns...> Prepare(std::string_view stmt) {
    sqlite3_stmt *new_stmt;
    if (sqlite3_prepare_v2(db.get(), stmt.data(), static_cast<int>(stmt.size()),
                           &new_stmt, nullptr) != SQLITE_OK) {
      throw Error("Error cloning statement", db.get());
    }
    return Query<Columns...>(std::shared_ptr<sqlite3_stmt>(new_stmt, Deleter{}),
                             db);
  }

  // Begin transactions to the database
  void Begin(bool exclusive = false);

  // Commit transactions to the database
  void Commit(void);

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
  std::string GetFilename(void) const { return dbFilename; }

 private:
  friend class Statement;

  // Get the raw pointer to SQLite connection handler
  sqlite3 *GetHandler(void) const { return db.get(); }

  std::shared_ptr<sqlite3> db;
  std::string dbFilename;
};

} // namespace sqlite
