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
#include <zstd.h>

#include "API.h"
#include "SQLiteCompression.h"

namespace std {

template <>
struct default_delete<ZSTD_CCtx> {
  inline void operator()(ZSTD_CCtx *cctx) {
    ZSTD_freeCCtx(cctx);
  }
};

template <>
struct default_delete<ZSTD_DCtx> {
  inline void operator()(ZSTD_DCtx *cctx) {
    ZSTD_freeDCtx(cctx);
  }
};

}  // namespace std

namespace sqlite {

#define MX_VISIT_PSEUDO_KIND(cls, storage) \
    inline static unsigned Get_Pseudo_Kind( \
        const mx::ast::Pseudo::Reader &reader, mx::cls *) { \
      return reader.getVal ## storage(); \
    }
#include <multiplier/Visitor.inc.h>

class ConnectionImpl {
 public:
  const std::filesystem::path db_path;
  const bool read_only;
  sqlite3 *db{nullptr};
  std::vector<sqlite3_stmt *> stmts;

  std::shared_mutex busy_handler_lock;
  std::function<int(unsigned)> busy_handler;

  std::unique_ptr<ZSTD_CCtx> compression_ctx;
  std::unique_ptr<ZSTD_DCtx> decompression_ctx;

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
      }),
      compression_ctx(ZSTD_createCCtx()),
      decompression_ctx(ZSTD_createDCtx()) {

  int ro_flag = read_only
      ? SQLITE_OPEN_READONLY
      : (SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);

  int ret = sqlite3_open_v2(
      db_path.generic_string().c_str(), &db,
      (ro_flag | SQLITE_OPEN_NOMUTEX |
       SQLITE_OPEN_PRIVATECACHE | SQLITE_OPEN_WAL),
      nullptr);

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

template<typename T>
static void EntityFragmentId(sqlite3_context *ctx, int, sqlite3_value **argv) {
  mx::EntityId id(static_cast<mx::RawEntityId>(sqlite3_value_int64(argv[0])));
  auto unpacked = id.Unpack();
  if (!std::holds_alternative<T>(unpacked)) {
    sqlite3_result_error(
        ctx, "The id does not correspond to the specified type", -1);
    return;
  }

  auto entity_id = std::get<T>(unpacked);
  mx::SpecificEntityId<mx::FragmentId> packed(entity_id);
  sqlite3_result_int64(ctx, static_cast<int64_t>(packed.Pack()));
}

template<typename T>
static void EntityOffset(sqlite3_context *ctx, int, sqlite3_value **argv) {
  mx::EntityId id(static_cast<mx::RawEntityId>(sqlite3_value_int64(argv[0])));
  auto unpacked = id.Unpack();
  if (!std::holds_alternative<T>(unpacked)) {
    sqlite3_result_error(
        ctx, "The id does not correspond to the specified type", -1);
    return;
  }

  auto entity_id = std::get<T>(unpacked);
  if constexpr (sizeof(mx::EntityOffset) == 8u) {
    sqlite3_result_int64(
        ctx, static_cast<mx::SignedEntityOffset>(entity_id.offset));
  } else {
    sqlite3_result_int(
        ctx, static_cast<mx::SignedEntityOffset>(entity_id.offset));
  }
}

template<typename T>
static void EntityKind(sqlite3_context *ctx, int, sqlite3_value **argv) {
  mx::EntityId id(static_cast<mx::RawEntityId>(sqlite3_value_int64(argv[0])));
  auto unpacked = id.Unpack();
  if (!std::holds_alternative<T>(unpacked)) {
    sqlite3_result_error(
        ctx, "The id does not correspond to the specified type", -1);
    return;
  }

  auto entity_id = std::get<T>(unpacked);
  sqlite3_result_int(ctx, static_cast<int>(entity_id.kind));
}

template<>
void EntityKind<mx::ast::Pseudo>(sqlite3_context *ctx, int, sqlite3_value **) {
  // TODO(frabert): This needs to change once we store pseudos other than
  //                Designators
  sqlite3_result_int(ctx, static_cast<int>(mx::PseudoKind::DESIGNATOR));
}

Connection::Connection(const std::filesystem::path &db_path,
                       bool read_only)
    : impl(std::make_shared<ConnectionImpl>(db_path, read_only)) {
  CreateFunction("Decl_kind", 1, SQLITE_DETERMINISTIC,
                 EntityKind<mx::DeclarationId>, nullptr, nullptr, nullptr);

  CreateFunction("Stmt_kind", 1, SQLITE_DETERMINISTIC,
                 EntityKind<mx::StatementId>, nullptr, nullptr, nullptr);

  CreateFunction("Type_kind", 1, SQLITE_DETERMINISTIC,
                 EntityKind<mx::TypeId>, nullptr, nullptr, nullptr);

  CreateFunction("Attr_kind", 1, SQLITE_DETERMINISTIC,
                 EntityKind<mx::AttributeId>, nullptr, nullptr, nullptr);

  CreateFunction("Macro_kind", 1, SQLITE_DETERMINISTIC,
                 EntityKind<mx::MacroId>, nullptr, nullptr, nullptr);

  CreateFunction("Pseudo_kind", 1, SQLITE_DETERMINISTIC,
                 EntityKind<mx::ast::Pseudo>, nullptr, nullptr, nullptr);

  CreateFunction("Decl_fragment", 1, SQLITE_DETERMINISTIC,
                 EntityFragmentId<mx::DeclarationId>, nullptr, nullptr,
                 nullptr);

  CreateFunction("Stmt_fragment", 1, SQLITE_DETERMINISTIC,
                 EntityFragmentId<mx::StatementId>, nullptr, nullptr, nullptr);

  CreateFunction("Type_fragment", 1, SQLITE_DETERMINISTIC,
                 EntityFragmentId<mx::TypeId>, nullptr, nullptr, nullptr);

  CreateFunction("Attr_fragment", 1, SQLITE_DETERMINISTIC,
                 EntityFragmentId<mx::AttributeId>, nullptr, nullptr, nullptr);

  CreateFunction("Macro_fragment", 1, SQLITE_DETERMINISTIC,
                 EntityFragmentId<mx::MacroId>, nullptr, nullptr, nullptr);

  CreateFunction("Pseudo_fragment", 1, SQLITE_DETERMINISTIC,
                 EntityFragmentId<mx::DesignatorId>, nullptr, nullptr, nullptr);

  CreateFunction("Decl_offset", 1, SQLITE_DETERMINISTIC,
                 EntityOffset<mx::DeclarationId>, nullptr, nullptr, nullptr);

  CreateFunction("Stmt_offset", 1, SQLITE_DETERMINISTIC,
                 EntityOffset<mx::StatementId>, nullptr, nullptr, nullptr);

  CreateFunction("Type_offset", 1, SQLITE_DETERMINISTIC,
                 EntityOffset<mx::TypeId>, nullptr, nullptr, nullptr);

  CreateFunction("Attr_offset", 1, SQLITE_DETERMINISTIC,
                 EntityOffset<mx::AttributeId>, nullptr, nullptr, nullptr);

  CreateFunction("Macro_offset", 1, SQLITE_DETERMINISTIC,
                 EntityOffset<mx::MacroId>, nullptr, nullptr, nullptr);

  CreateFunction("Pseudo_offset", 1, SQLITE_DETERMINISTIC,
                 EntityOffset<mx::DesignatorId>, nullptr, nullptr, nullptr);

  CreateFunction("zstd_compress", 1, SQLITE_DETERMINISTIC,
                 ZstdCompress, nullptr, nullptr, nullptr,
                 impl->compression_ctx.get());

  CreateFunction("zstd_compress", 2, SQLITE_DETERMINISTIC,
                 ZstdCompressDict, nullptr, nullptr, nullptr,
                 impl->compression_ctx.get());

  CreateFunction("zstd_decompress", 1, SQLITE_DETERMINISTIC,
                 ZstdDecompress, nullptr, nullptr, nullptr,
                 impl->decompression_ctx.get());

  CreateFunction("zstd_decompress", 2, SQLITE_DETERMINISTIC,
                 ZstdDecompressDict, nullptr, nullptr, nullptr,
                 impl->decompression_ctx.get());

  CreateFunction("zstd_create_cdict", 1, 0,
                 ZstdCreateCDict, nullptr, nullptr, nullptr,
                 impl->compression_ctx.get());

  CreateFunction("zstd_create_ddict", 1, 0,
                 ZstdCreateDDict, nullptr, nullptr, nullptr,
                 impl->decompression_ctx.get());
}

// Get the filename used to open the database
std::filesystem::path Connection::GetFilename(void) const {
  return impl->db_path;
}

// Was this connection opened in read-only mode?
bool Connection::IsReadOnly(void) const {
  return impl->read_only;
}

void Connection::CreateFunction(
    const char *func_name, unsigned n_args, int flags,
    void (*x_func)(sqlite3_context *, int, sqlite3_value **),
    void (*x_step)(sqlite3_context *, int, sqlite3_value **),
    void (*x_final)(sqlite3_context *),
    void (*x_destroy)(void *), void *pApp) {

  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(
      impl->db, func_name, static_cast<int>(n_args), rflags,
      pApp, x_func, x_step, x_final, x_destroy);
  if (ret != SQLITE_OK) {
    throw Error("Failed to create function", impl->db);
  }
}

void Connection::DeleteFunction(
    const char *func_name, unsigned n_args, int flags) {

  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(
      impl->db, func_name, static_cast<int>(n_args), rflags,
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
  char *error_msg = nullptr;
  int ret = sqlite3_exec(impl->db, query.c_str(), nullptr, nullptr, &error_msg);
  if (SQLITE_OK != ret) {
    throw Error("Failed to execute query string " + std::string(error_msg));
  }
}

Statement Connection::Prepare(const std::string &query) {
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
