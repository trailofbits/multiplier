// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteStore.h"

#include <cstring>
#include <iostream>
#include <thread>
#include <shared_mutex>
#include <sqlite3.h>
#include <vector>

#include "API.h"

namespace sqlite {

#define MX_VISIT_ENUM(cls, api_name, storage, apply, \
                      pasta_name, type, nth_list) \
    template <typename Reader> \
    inline static unsigned Get_ ## cls ## _ ## pasta_name(const Reader &reader) { \
      return reader.getVal ## storage(); \
    }

#define MX_VISIT_PSEUDO_KIND(cls, storage) \
    inline static unsigned Get_Pseudo_Kind( \
        const mx::ast::Pseudo::Reader &reader, mx::cls *) { \
      return reader.getVal ## storage(); \
    }
#include <multiplier/Visitor.inc.h>

#ifndef NDEBUG
// Nifty to double check that only one connection is being used/created
// per-thread.
static thread_local sqlite3 *tDatabase = nullptr;
#endif

class ConnectionImpl {
 public:
  const std::filesystem::path db_path;
  const bool read_only;
  sqlite3 *db{nullptr};
  std::vector<sqlite3_stmt *> stmts;

  std::shared_mutex busy_handler_lock;
  std::function<int(unsigned)> busy_handler;

  ConnectionImpl(const std::filesystem::path &db_path_,
                 bool read_only);

  ~ConnectionImpl(void);
};

ConnectionImpl::ConnectionImpl(const std::filesystem::path &db_path_,
                               bool read_only_)
    : db_path(db_path_),
      read_only(read_only_),
      busy_handler([] (unsigned) -> int {
        std::this_thread::yield();
        return 1;
      }) {

  int ro_flag = read_only
      ? SQLITE_OPEN_READONLY
      : (SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);

  int ret = sqlite3_open_v2(
      db_path.generic_string().c_str(), &db,
      (ro_flag | SQLITE_OPEN_NOMUTEX |
       SQLITE_OPEN_PRIVATECACHE | SQLITE_OPEN_WAL),
      nullptr);

#ifndef NDEBUG
  assert(!tDatabase);
  tDatabase = db;
#endif

  if (ret != SQLITE_OK) {
    throw Error("Failed to open database", db);
  }

  // When the database has been temporarily locked by another process, this
  // tells SQLite to retry the command/query until it succeeds, rather than
  // returning SQLITE_BUSY immediately.
  //
  // TODO(pag): Should this only happen if `busy_timeout` is `<= 0`?
  ret = sqlite3_busy_handler(
      db,
      +[](void *self_, int num_locks) -> int {
        auto self = reinterpret_cast<ConnectionImpl *>(self_);
        std::function<int(unsigned)> copy_of_busy_handler;
        do {
          std::shared_lock<std::shared_mutex> locker(self->busy_handler_lock);
          copy_of_busy_handler = self->busy_handler;
        } while (false);
        return copy_of_busy_handler(
            (0 < num_locks) ? static_cast<unsigned>(num_locks) : 0u);
      },
      this);

  if (ret != SQLITE_OK) {
    throw Error("Failed to install busy handler", db);
  }

  if (read_only) {
    sqlite3_exec(db, "PRAGMA query_only", nullptr, nullptr, nullptr);
  }
}

ConnectionImpl::~ConnectionImpl(void) {

  // We may be holding onto state in the old busy handler, so replace it.
  sqlite3_busy_handler(
      db,
      +[](void *, int) -> int {
        std::this_thread::yield();
        return 1;
      },
      nullptr);

  for (sqlite3_stmt *stmt : stmts) {
    sqlite3_clear_bindings(stmt);
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
  }

  stmts.clear();

  sqlite3_close(db);
}

Error::Error(const std::string &msg, sqlite3 *db)
    : runtime_error("[SQLite Error] " + msg + ": " +
                    std::string(sqlite3_errmsg(db))) {}

uint32_t QueryResult::NumColumns(void) {
  return static_cast<uint32_t>(sqlite3_column_count(impl.get()));
}

int64_t QueryResult::getInt64(int32_t idx) {
  return sqlite3_column_int64(impl.get(), idx);
}

std::string QueryResult::getText(int32_t idx) {
  sqlite3_stmt *prepared_stmt = impl.get();
  auto ptr = reinterpret_cast<const char *>(
      sqlite3_column_blob(prepared_stmt, idx));
  auto len = sqlite3_column_bytes(prepared_stmt, idx);
  return std::string(ptr, static_cast<size_t>(len));
}

std::string_view QueryResult::getBlob(int32_t idx) {
  sqlite3_stmt *prepared_stmt = impl.get();
  auto ptr = reinterpret_cast<const char *>(
      sqlite3_column_blob(prepared_stmt, idx));
  auto len = sqlite3_column_bytes(prepared_stmt, idx);
  return std::string_view(ptr, static_cast<size_t>(len));
}

size_t Statement::NumParams(void) const noexcept {
  return static_cast<unsigned>(
      sqlite3_bind_parameter_count(impl.get()));
}

void Statement::ClearBoundValues(void) {
  assert(tDatabase == sqlite3_db_handle(impl.get()));
  sqlite3_clear_bindings(impl.get());
}

void Statement::Reset(void) {
#ifndef NDEBUG
  needs_reset = false;
#endif
  ClearBoundValues();
  sqlite3_reset(impl.get());
}

void Statement::Execute(void) {
#ifndef NDEBUG
  needs_reset = false;
#endif

  auto ret = TryExecuteStep();
  if (SQLITE_DONE != ret) {
    auto db = sqlite3_db_handle(impl.get());
    if (SQLITE_ROW == ret) {
      throw Error("Execute() does not expect results. Use executeStep.");
    } else if (ret == sqlite3_errcode(db)) {
      throw Error("Execute() failed with Errorcode", db);
    } else {
      throw Error("Execute() failed with Error", db);
    }
  }

  auto stmt = impl.get();
  sqlite3_clear_bindings(stmt);
  sqlite3_reset(stmt);
}

bool Statement::ExecuteStep(void) {
#ifndef NDEBUG
  needs_reset = true;
#endif

  auto ret = TryExecuteStep();
  if ((SQLITE_ROW != ret) && (SQLITE_DONE != ret)) {
    throw Error("ExecuteStep failed", sqlite3_db_handle(impl.get()));
  }
  return (ret == SQLITE_ROW);
}

QueryResult Statement::Row(void) {
  return QueryResult(impl);
}

int Statement::TryExecuteStep(void) {
  assert(tDatabase == sqlite3_db_handle(impl.get()));
  return sqlite3_step(impl.get());
}

void Statement::bind(const size_t i, const int32_t &value) {
  sqlite3_bind_int(impl.get(), static_cast<int>(i + 1), value);
}

void Statement::bind(const size_t i, const uint32_t &value) {
  sqlite3_bind_int(impl.get(), static_cast<int>(i + 1),
                   static_cast<int32_t>(value));
}

void Statement::bind(const size_t i, const int64_t &value) {
  sqlite3_bind_int64(impl.get(), static_cast<int>(i + 1), value);
}

void Statement::bind(const size_t i, const uint64_t &value) {
  sqlite3_bind_int64(impl.get(), static_cast<int>(i + 1),
                     static_cast<int64_t>(value));
}

void Statement::bind(const size_t i, const double &value) {
  sqlite3_bind_double(impl.get(), static_cast<int>(i + 1), value);
}

void Statement::bind(const size_t i, const std::nullptr_t &) {
  sqlite3_bind_null(impl.get(), static_cast<int>(i + 1));
}

void Statement::bind(const size_t i, const std::nullopt_t &) {
  sqlite3_bind_null(impl.get(), static_cast<int>(i + 1));
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"

void Statement::bind(const size_t i, const char *&value) {
  sqlite3_bind_text64(impl.get(), static_cast<int>(i + 1),
                      value, strlen(value), SQLITE_TRANSIENT,
                      SQLITE_UTF8);
}

void Statement::bind(const size_t i, const std::string &value) {
  sqlite3_bind_blob64(impl.get(), static_cast<int>(i + 1),
                      value.data(), value.size(), SQLITE_TRANSIENT);
}

void Statement::bind(const size_t i, const std::string_view &value) {
  sqlite3_bind_blob64(impl.get(), static_cast<int>(i + 1),
                      value.data(), value.size(), SQLITE_TRANSIENT);
}

#pragma GCC diagnostic pop

static int GetKind(const mx::ast::Decl::Reader &reader) {
  return Get_Decl_Kind(reader);
}

static int GetKind(const mx::ast::Stmt::Reader &reader) {
  return Get_Stmt_Kind(reader);
}

static int GetKind(const mx::ast::Type::Reader &reader) {
  return Get_Type_Kind(reader);
}

static int GetKind(const mx::ast::Attr::Reader &reader) {
  return Get_Attr_Kind(reader);
}

static int GetKind(const mx::ast::Macro::Reader &reader) {
  return Get_Macro_Kind(reader);
}

static int GetKind(const mx::ast::Pseudo::Reader &reader) {
  mx::TemplateArgument *dummy;
  return Get_Pseudo_Kind(reader, dummy);
}

template<typename T>
static void EntityKindFunc(sqlite3_context *ctx, int argc, sqlite3_value **argv) {
  auto blob_ptr = static_cast<const char*>(sqlite3_value_blob(argv[0]));
  auto blob_size = sqlite3_value_bytes(argv[0]);
  std::string blob(blob_ptr, blob_size);
  mx::PackedReaderState package(blob);
  sqlite3_result_int(ctx, GetKind(package.Reader<T>()));
}

Connection::Connection(const std::filesystem::path &db_path,
                       bool read_only)
    : impl(std::make_shared<ConnectionImpl>(db_path, read_only)) {
      CreateFunction("Decl_kind", 1, SQLITE_DETERMINISTIC,
        EntityKindFunc<mx::ast::Decl>, nullptr, nullptr, nullptr);

      CreateFunction("Stmt_kind", 1, SQLITE_DETERMINISTIC,
        EntityKindFunc<mx::ast::Stmt>, nullptr, nullptr, nullptr);

      CreateFunction("Type_kind", 1, SQLITE_DETERMINISTIC,
        EntityKindFunc<mx::ast::Type>, nullptr, nullptr, nullptr);

      CreateFunction("Attr_kind", 1, SQLITE_DETERMINISTIC,
        EntityKindFunc<mx::ast::Attr>, nullptr, nullptr, nullptr);

      CreateFunction("Macro_kind", 1, SQLITE_DETERMINISTIC,
        EntityKindFunc<mx::ast::Macro>, nullptr, nullptr, nullptr);

      CreateFunction("Pseudo_kind", 1, SQLITE_DETERMINISTIC,
        EntityKindFunc<mx::ast::Pseudo>, nullptr, nullptr, nullptr);
    };

// Get the filename used to open the database
std::filesystem::path Connection::GetFilename(void) const {
  return impl->db_path;
}

// Was this connection opened in read-only mode?
bool Connection::IsReadOnly(void) const {
  return impl->read_only;
}

void Connection::CreateFunction(
    std::string func_name, unsigned n_args, int flags,
    void (*x_func)(sqlite3_context *, int, sqlite3_value **),
    void (*x_step)(sqlite3_context *, int, sqlite3_value **),
    void (*x_final)(sqlite3_context *),
    void (*x_destroy)(void *)) {
  assert(tDatabase == impl->db);

  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(
      impl->db, func_name.c_str(), static_cast<int>(n_args), rflags,
      nullptr, x_func, x_step, x_final, x_destroy);
  if (ret != SQLITE_OK) {
    throw Error("Failed to create function", impl->db);
  }
}

void Connection::DeleteFunction(
    std::string func_name, unsigned n_args, int flags) {
  assert(tDatabase == impl->db);

  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(
      impl->db, func_name.c_str(), static_cast<int>(n_args), rflags,
      nullptr, nullptr, nullptr, nullptr, nullptr);
  if (ret != SQLITE_OK) {
    throw Error("Failed to create function", impl->db);
  }
}

// Set a busy handler when the table is locked.
void Connection::SetBusyHandler(std::function<int(unsigned)> func) {
  std::lock_guard<std::shared_mutex> locker(impl->busy_handler_lock);
  impl->busy_handler = std::move(func);
}

void Connection::SetBusyTimeout(std::chrono::milliseconds ms) {
  std::lock_guard<std::shared_mutex> locker(impl->busy_handler_lock);
  impl->busy_handler = [=] (unsigned) {
    std::this_thread::sleep_for (ms);
    return 1;  // Continue busy looping if necessary.
  };
}

void Connection::Execute(const std::string &query) {
  assert(tDatabase == impl->db);

  char *error_msg = nullptr;
  int ret = sqlite3_exec(impl->db, query.c_str(), nullptr, nullptr, &error_msg);
  if (SQLITE_OK != ret) {
    throw Error("Failed to execute query string " + std::string(error_msg));
  }
}

Statement Connection::Prepare(const std::string &query) {
  assert(tDatabase == impl->db);

  sqlite3_stmt *stmt = nullptr;
  char *tail = nullptr;
  auto ret = sqlite3_prepare_v3(
      impl->db, query.c_str(), static_cast<int>(query.size()),
      SQLITE_PREPARE_PERSISTENT, &stmt, const_cast<const char **>(&tail));
  if (SQLITE_OK != ret) {
    throw Error("Failed to prepare statement", impl->db);
  }

  impl->stmts.push_back(stmt);

  return Statement(std::shared_ptr<sqlite3_stmt>(impl, stmt));
}

void Connection::Commit(void) {
  Execute("commit transaction");
}

// Abort the current transaction.
void Connection::Abort(void) {
  Execute("rollback transaction");
}

// Optimize the database.
void Connection::Optimize(void) {
  Execute("pragma optimize");
}

// Return the raw SQLite handle.
std::shared_ptr<sqlite3> Connection::Handle(void) {
  return std::shared_ptr<sqlite3>(impl, impl->db);
}

void Connection::Begin(TransactionKind kind) {
  switch (kind) {
    case TransactionKind::kNormal:
      Execute("BEGIN TRANSACTION");
      return;
    case TransactionKind::kExclusive:
      Execute("BEGIN EXCLUSIVE TRANSACTION");
      return;
    case TransactionKind::kConcurrent:
      Execute("BEGIN CONCURRENT");
      return;
  }
}

} // namespace sqlite
