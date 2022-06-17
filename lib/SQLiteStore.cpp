// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <thread>
#include <iostream>
#include <assert.h>

#include <multiplier/SQLiteStore.h>

namespace sqlite {

QueryResult::QueryResult(Connection& conn, const std::string& query)
  : stmt(std::make_shared<Statement>(conn, query)){}

QueryResult::QueryResult(std::shared_ptr<Statement> stmt_)
  : stmt(stmt_) {}

std::vector<std::string>
QueryResult::GetColumnNames() {
  std::vector<std::string> result;
  auto col_size = NumColumns();
  auto prepared_stmt = stmt->prepareStatement();

  for (auto i = 0u; i < col_size; i++) {
    result.push_back(
        sqlite3_column_name(prepared_stmt, i));
  }
  return result;
}

bool QueryResult::Columns(std::vector<std::string>& row) {
  std::vector<std::string> ret;
  auto col_size = NumColumns();
  auto prepared_stmt = stmt->prepareStatement();

  for (int i = 0; i < col_size; i++) {
    auto col_val = sqlite3_column_text(prepared_stmt, i);

    if (col_val) {
      ret.push_back(std::string(reinterpret_cast<const char*>(col_val)));
    } else {
      ret.push_back("");
    }
  }

  row.swap(ret);
  return true;
}

uint32_t QueryResult::NumColumns() {
  auto prepared_stmt = stmt->prepareStatement();
  return sqlite3_column_count(prepared_stmt);
}

int64_t QueryResult::getInt64(int32_t idx) {
  auto prepared_stmt = stmt->prepareStatement();
  return sqlite3_column_int64(prepared_stmt, idx);
}

std::string QueryResult::getText(int32_t idx) {
  auto prepared_stmt = stmt->prepareStatement();
  auto ptr = reinterpret_cast<const char*>(sqlite3_column_text(prepared_stmt, idx));
  auto len = sqlite3_column_bytes(prepared_stmt, idx);
  return std::string(ptr, len);
}

Statement::Statement(Connection& conn, const std::string& stmt)
    : db(conn), query(stmt)
{
  conn.stmts.emplace_back(this);

  auto getPrepareStatement = [this](void) -> std::shared_ptr<sqlite3_stmt> {
    sqlite3_stmt* stmt;
    char *tail;
    auto ret = sqlite3_prepare_v2(db.GetHandler(), query.c_str(),
                                  static_cast<int>(query.size()),
                                  &stmt, const_cast<const char**>(&tail));
    if (SQLITE_OK != ret) {
      assert(0);
      throw Error("Failed to prepare statement");
    }

    return std::shared_ptr<sqlite3_stmt>(
        stmt, [](sqlite3_stmt* stmt) { sqlite3_finalize(stmt);});
  };

  prepared_stmt = getPrepareStatement();
  num_params = sqlite3_bind_parameter_count(prepared_stmt.get());
}

Statement::~Statement(){}

sqlite3_stmt* Statement::prepareStatement(void){
  return prepared_stmt.get();
}

void Statement::Close() noexcept {
  if (prepared_stmt) {
    sqlite3_finalize(prepared_stmt.get());
    prepared_stmt.reset();
  }
}

void Statement::Execute(){
  auto ret = tryExecuteStep();
  if (SQLITE_DONE != ret) {
    if (SQLITE_ROW == ret) {
      throw Error("Execute() does not expect results. Use executeStep.");
    } else if (ret == sqlite3_errcode(db.GetHandler())) {
      std::cerr << "Execute() failed with Errorcode " << ret << std::endl;
      throw Error("Execute() failed with Errorcode");
    } else {
      throw Error("Execute() failed with Error");
    }
  }
}

bool Statement::ExecuteStep() {
  auto ret = tryExecuteStep();
  if ((SQLITE_ROW != ret) && (SQLITE_DONE != ret)) {
    if (ret == sqlite3_errcode(db.GetHandler())) {
      throw Error("ExecuteStep failed");
    } else {
      sqlite3_reset(prepared_stmt.get());
    }
  }
  return (ret == SQLITE_ROW);
}

QueryResult Statement::GetResult() {
  return QueryResult(shared_from_this());
}


int Statement::tryExecuteStep(void) {
  return sqlite3_step(prepared_stmt.get());
}

void Statement::bind(const size_t i, const int32_t &value) {
  sqlite3_bind_int(prepared_stmt.get(), i + 1, value);
}


void Statement::bind(const size_t i, const uint32_t &value) {
  sqlite3_bind_int(prepared_stmt.get(), i + 1, value);
}

void Statement::bind(const size_t i, const int64_t &value) {
  sqlite3_bind_int64(prepared_stmt.get(), i + 1, value);
}

void Statement::bind(const size_t i, const uint64_t &value) {
  sqlite3_bind_int64(prepared_stmt.get(), i + 1, value);
}

void Statement::bind(const size_t i, const double &value) {
  sqlite3_bind_double(prepared_stmt.get(), i + 1, value);
}

void Statement::bind(const size_t i, const std::nullptr_t &value) {
  sqlite3_bind_null(prepared_stmt.get(), i + 1);
}

void Statement::bind(const size_t i, const char* &value) {
  sqlite3_bind_text(prepared_stmt.get(), i + 1,
                    value, strlen(value), SQLITE_TRANSIENT);
}

void Statement::bind(const size_t i, const std::string &value) {
  sqlite3_bind_text(prepared_stmt.get(), i + 1,
                    value.c_str(), value.size(), SQLITE_TRANSIENT);
}

Connection::Connection(const std::string &db_name,
                       const int busyTimeouts)
                      : dbFilename(db_name)
{
  sqlite3* db_handle;
  const int ret = sqlite3_open(db_name.c_str(), &db_handle);

  sqlite3_exec(db_handle, "pragma synchronous = off",
               nullptr, nullptr, nullptr);
  sqlite3_exec(db_handle, "pragma journal_mode = memory",
               nullptr, nullptr, nullptr);
  sqlite3_exec(db_handle, "pragma temp_store = memory",
               nullptr, nullptr, nullptr);

  db.reset(db_handle);

  if (ret != SQLITE_OK) {
    throw Error("Failed to open database");
  }

  if (busyTimeouts > 0) {
      SetBusyTimeout(busyTimeouts);
  }

  // When the database has been temporarily locked by another process, this
  // tells SQLite to retry the command/query until it succeeds, rather than
  // returning SQLITE_BUSY immediately.
  sqlite3_busy_handler(db.get(),
      [](void *, int) {
        std::this_thread::yield();
        return 1;
      },
      nullptr);

};

void Connection::Close() noexcept {
  while (stmts.empty()) {
    auto stmt = stmts.back();
    stmt->Close();
    stmts.pop_back();
  }

  if (auto db_ = GetHandler()) {
    sqlite3_close(db_);
    db.reset(nullptr);
  }
}

void Connection::CreateFunction(std::string func_name, unsigned n_args, unsigned flags,
                                void (*x_func)(sqlite3_context *, int, sqlite3_value **),
                                void (*x_step)(sqlite3_context *, int, sqlite3_value **),
                                void (*x_final)(sqlite3_context *),
                                void (*x_destroy)(void *)) {
  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(GetHandler(), func_name.c_str(), n_args, rflags,
                                        nullptr, x_func, x_step, x_final, x_destroy);
  if (ret != SQLITE_OK) {
    throw Error("Failed to create function");
  }
}

void Connection::DeleteFunction(std::string func_name, unsigned n_args, unsigned flags) {
  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(GetHandler(), func_name.c_str(), n_args, rflags,
                                        nullptr, nullptr, nullptr, nullptr, nullptr);
  if (ret != SQLITE_OK) {
    throw Error("Failed to create function");
  }
}

void Connection::SetBusyTimeout(const int32_t timeout) {
  const int ret = sqlite3_busy_timeout(GetHandler(), timeout);
  if (ret != SQLITE_OK) {
    throw Error("Failed to set timeout");
  }
}

void Connection::Execute(const std::string& query) {
  char *error_msg;
  if (sqlite3_exec(GetHandler(), query.c_str(),
                   nullptr, nullptr, &error_msg)) {
    throw Error("Failed to execute query string " + std::string(error_msg));
  }
}

std::shared_ptr<Statement> Connection::Prepare(const std::string& query) {
  auto stmt = std::make_shared<Statement>(*this, query);
  return std::move(stmt);
}

QueryResult Connection::ExecuteAndGet(const std::string& stmt) {
  return QueryResult(*this, stmt);
}

void Connection::Deleter::operator()(sqlite3* db) {
  const int ret = sqlite3_close(db);
  assert(SQLITE_OK == ret);
}

void Connection::Commit(void) {
  Execute("commit transaction");
}

void Connection::Begin(void) {
  Execute("begin immediate transaction");
}

} // namespace sqlite
