// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <chrono>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <functional>
#include <memory>
#include <multiplier/Types.h>
#include <optional>
#include <string>

extern "C" {
struct sqlite3;
struct sqlite3_context;
struct sqlite3_stmt;
struct sqlite3_value;
}  // extern C
namespace sqlite {

#define MX_ENABLE_SQLITE_LOGGING 0

class Connection;
class ConnectionImpl;
class Statement;

class Error : public std::runtime_error {
 public:
  Error(const std::string &msg) : std::runtime_error("[SQLite Error] " + msg) {}
  Error(const std::string &msg, sqlite3 *db);
};

class QueryResult {
 private:
  friend class Statement;

  std::shared_ptr<sqlite3_stmt> impl;

  inline QueryResult(std::shared_ptr<sqlite3_stmt> impl_)
      : impl(std::move(impl_)) {}

  int64_t getInt64(int32_t idx);
  std::string getText(int32_t idx);
  std::string_view getBlob(int32_t idx);

 public:
  uint32_t NumColumns(void);

  // Typed.
  template <typename... Ts>
  void Columns(Ts &&...args) {
#ifndef NDEBUG
    if (static_cast<int>(sizeof...(args)) > NumColumns()) {
      throw Error("Failed to read columns; no of arguments are less than column size");
    }
#endif

    int idx = 0;
    auto column_dispatcher = [this, &idx] (auto &&arg) {
      using arg_t = std::decay_t<decltype(arg)>;
      if constexpr (std::is_integral_v<arg_t>) {
        arg = static_cast<arg_t>(getInt64(idx));
      } else if constexpr (std::is_same_v<std::string, arg_t>) {
        arg = getText(idx);
      } else if constexpr (std::is_same_v<std::filesystem::path, arg_t>) {
        arg = getText(idx);
      } else if constexpr (std::is_same_v<std::string_view, arg_t>) {
        arg = getBlob(idx);
      } else if constexpr (std::is_same_v<mx::EntityId, arg_t>) {
        arg = mx::EntityId(static_cast<mx::RawEntityId>(getInt64(idx)));
      } else if constexpr (std::is_same_v<std::nullopt_t, arg_t> ||
                           std::is_same_v<std::nullptr_t, arg_t>) {
        ;
      } else {
        throw Error("Can't read column data; Type not supported!");
      }
      idx++;
    };

    (column_dispatcher(std::forward<Ts>(args)), ...);
  }
};

class Statement {
 private:
  friend class Connection;

  std::shared_ptr<sqlite3_stmt> impl;

#ifndef NDEBUG
  bool needs_reset{false};
#endif

#if MX_ENABLE_SQLITE_LOGGING
  bool logged{false};
#endif

  inline Statement(std::shared_ptr<sqlite3_stmt> impl_)
      : impl(std::move(impl_)) {}

 public:
  Statement(void) = delete;

  // Bind values with a sqlite statement. In the case of binding to a blob,
  // a copy of the underlying data is made.
  template<typename... Args>
  void BindValues(Args... args) {
#ifndef NDEBUG
    if (auto num_params = NumParams(); sizeof...(Args) > num_params) {
      std::string msg =
          "Too many arguments to bind() " + std::to_string(num_params) +
          " expected " + std::to_string(sizeof...(Args)) + " specified";
      throw Error(msg);
    }
#endif
    size_t i = 0;
//    Reset();
    assert(!needs_reset);
    bind_many(i, std::move(args)...);
  }

  // Bind values with a sqlite statement. In the case of binding to a blob,
  // no copy of the underlying data is made. Instead, we assume that the passed-
  // in data will live at least as long as the SQLite transaction.
  template<typename... Args>
  void BindValuesWithoutCopying(const Args&... args) {
#ifndef NDEBUG
    if (auto num_params = NumParams(); sizeof...(Args) > num_params) {
      std::string msg =
          "Too many arguments to bind() " + std::to_string(num_params) +
          " expected " + std::to_string(sizeof...(Args)) + " specified";
      throw Error(msg);
    }
#endif
    size_t i = 0;
//    Reset();
    assert(!needs_reset);
    bind_many_nocopy(i, args...);
  }

  void Execute(void);

  bool ExecuteStep(void);

  QueryResult Row(void);

  void ClearBoundValues(void);
  void Reset(void);

 private:
  friend class QueryResult;

  size_t NumParams(void) const noexcept;

  // Binding functions for the statements
  void bind(size_t i, int32_t value);
  inline void bind_nocopy(const size_t i, const int32_t &value) {
    bind(i, value);
  }

  void bind(size_t i, uint32_t value);
  inline void bind_nocopy(const size_t i, const uint32_t &value) {
    bind(i, value);
  }

  void bind(size_t i, int64_t value);
  inline void bind_nocopy(const size_t i, const int64_t &value) {
    bind(i, value);
  }

  void bind(size_t i, uint64_t value);
  inline void bind_nocopy(const size_t i, const uint64_t &value) {
    bind(i, value);
  }

  void bind(size_t i, double value);
  inline void bind_nocopy(const size_t i, const double &value) {
    bind(i, value);
  }

  void bind(size_t i, std::nullptr_t);
  inline void bind_nocopy(const size_t i, const std::nullptr_t &value) {
    bind(i, value);
  }

  void bind(size_t i, std::nullopt_t);
  inline void bind_nocopy(const size_t i, const std::nullopt_t &value) {
    bind(i, value);
  }

  inline void bind(size_t i, const char *value) {
    if (!value) {
      bind(i, std::string_view("", 0));
    } else {
      bind(i, std::string_view(value, strlen(value)));
    }
  }

  inline void bind_nocopy(size_t i, const char *&value) {
    if (!value) {
      bind_nocopy(i, std::string_view("", 0));
    } else {
      bind_nocopy(i, std::string_view(value, strlen(value)));
    }
  }

  inline void bind(size_t i, std::string value) {
    if (value.empty()) {
      bind(i, std::string_view("", 0));
    } else {
      bind(i, std::string_view(value.data(), value.size()));
    }
  }

  inline void bind_nocopy(size_t i, const std::string &value) {
    if (value.empty()) {
      bind_nocopy(i, std::string_view("", 0));
    } else {
      bind_nocopy(i, std::string_view(value.data(), value.size()));
    }
  }

  void bind(size_t i, std::string_view value);
  void bind_nocopy(size_t i, const std::string_view &value);

  inline void bind(size_t i, std::filesystem::path value) {
    bind(i, value.generic_string());
  }

  inline void bind_nocopy(size_t i, const std::filesystem::path &value) {
    bind(i, value.generic_string());  // Actually copies.
  }

  inline void bind(size_t i, mx::EntityId value) {
    bind(i, value.Pack());
  }

  inline void bind_nocopy(size_t i, const mx::EntityId &value) {
    bind_nocopy(i, value.Pack());
  }

  template<typename T>
  void bind_many(size_t i, T value) {
    bind(i, std::move(value));
  }

  template<typename T, typename... Args>
  void bind_many(size_t i, T value, Args... args) {
    bind(i, std::move(value));
    i++;
    bind_many(i, std::move(args)...);
  }

  template<typename T>
  void bind_many_nocopy(size_t i, const T &value) {
    bind_nocopy(i, value);
  }

  template<typename T, typename... Args>
  void bind_many_nocopy(size_t i, const T &value, const Args&... args) {
    bind_nocopy(i, value);
    i++;
    bind_many_nocopy(i, args...);
  }

 public:
  using Ptr = std::shared_ptr<Statement>;
};

enum class TransactionKind {
  kNormal,
  kExclusive,
  kConcurrent
};

// TODO(pag): Refactor this. A connection should contain a shared pointer for
//            ease of copying, and then a connection should own the statements,
//            but statements should wrap a shared pointer that aliases/extends
//            the connection's lifetime. Destruction should close the database.
class Connection {
 private:
  std::shared_ptr<ConnectionImpl> impl;

  Connection(void) = delete;

 public:

  // Uses sqlite3_open to open the database at the specified path
  explicit Connection(const std::filesystem::path &db_path,
                      bool read_only = false);

  Connection(Connection &&) = default;
  Connection &operator=(Connection &&) noexcept = default;

  // Copying a connection makes a new connection.
  Connection(const Connection &conn)
      : Connection(conn.GetFilename(), conn.IsReadOnly()) {}

  // Assigning moves a copy of a new connection.
  inline Connection &operator=(const Connection &conn) {
    return *this = Connection(conn);
  }

  // Execute statements without results
  void Execute(const std::string &query);

  // Get prepared statements before executing to database
  Statement Prepare(const std::string &stmt);

  // Begin transactions to the database
  void Begin(TransactionKind);

  // Commit transactions to the database
  void Commit(void);

  // Abort the current transaction.
  void Abort(void);

  // Optimize the database.
  void Optimize(void);

  // Return the raw SQLite handle.
  std::shared_ptr<sqlite3> Handle(void);

  // Set a busy handler when the table is locked. If `func` returns `0` then
  // SQLite will only call it once. If `func` returns non-zero then SQLite can
  // call it an arbitrary number of times. The argument to `func` is the number
  // of times this function has already been called for a given locking event.
  void SetBusyHandler(std::function<int(unsigned)> func);

   // Set a busy timeout when the table is locked.
  void SetBusyTimeout(std::chrono::milliseconds ms);

  // Attach custom function to your sqlite database
  void CreateFunction(const char *func_name, unsigned n_args, int flags,
                      void (*x_func)(sqlite3_context *, int, sqlite3_value **),
                      void (*x_step)(sqlite3_context *, int, sqlite3_value **),
                      void (*x_final)(sqlite3_context *),
                      void (*x_destroy)(void *), void* pApp = nullptr);

  // Delete custom function from the sqlite database
  void DeleteFunction(const char *func_name, unsigned n_args, int flags);

  // Get the filename used to open the database
  std::filesystem::path GetFilename(void) const;

  // Was this connection opened in read-only mode?
  bool IsReadOnly(void) const;
};

class Transaction {
 public:
  inline ~Transaction(void) {
    db.Commit();
  }

  inline Transaction(Connection &db_)
      : db(db_) {
    db.Begin(TransactionKind::kNormal);
  }

 private:
  Connection &db;
};

class AbortingTransaction {
 public:
  inline ~AbortingTransaction(void) {
    db.Abort();
  }

  inline AbortingTransaction(Connection &db_)
      : db(db_) {
    db.Begin(TransactionKind::kNormal);
  }

 private:
  Connection &db;
};

class AbortingConcurrentTransaction {
 public:
  inline ~AbortingConcurrentTransaction(void) {
    db.Abort();
  }

  inline AbortingConcurrentTransaction(Connection &db_)
      : db(db_) {
    db.Begin(TransactionKind::kConcurrent);
  }

 private:
  Connection &db;
};

class ConcurrentTransaction {
 public:
  inline ~ConcurrentTransaction(void) {
    db.Commit();
  }

  inline ConcurrentTransaction(Connection &db_)
      : db(db_) {
    db.Begin(TransactionKind::kConcurrent);
  }

 private:
  Connection &db;
};

class ExclusiveTransaction {
 public:
  inline ~ExclusiveTransaction(void) {
    db.Commit();
  }

  inline ExclusiveTransaction(Connection &db_)
      : db(db_) {
    db.Begin(TransactionKind::kExclusive);
  }

 private:
  Connection &db;
};

}  // namespace sqlite
