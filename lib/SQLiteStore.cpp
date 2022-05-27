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

std::vector<std::string>
QueryResult::getColumnNames() {
  std::vector<std::string> result;
  int col_size = numColumns();
  for (int i = 0; i < col_size; i++) {
    result.push_back(
        sqlite3_column_name(stmt->GetPreparedStatement(), i));
  }
  return result;
}

bool QueryResult::next(std::vector<std::string>& row) {
  if (!next()) {
    return false;
  }

  std::vector<std::string> ret;
  int col_size = numColumns();
  const unsigned char * col_val;

  for (int i = 0; i < col_size; i++) {
    col_val = sqlite3_column_text(stmt->GetPreparedStatement(), i);

    if (col_val) {
      ret.push_back(std::string((char *)col_val));
    }
    else {
      ret.push_back("");
    }
  }

  row.swap(ret);
  return true;
}

int QueryResult::numColumns() {
  return sqlite3_column_count(stmt->GetPreparedStatement());
}

bool QueryResult::next() {
  return (sqlite3_step(stmt->GetPreparedStatement()) == 100);
}

Statement::Statement(Connection& conn, const std::string& stmt)
    : db(conn), query(stmt)
{
  conn.stmts.emplace_back(this);
  prepared_stmt = prepareStatement();
  num_params = sqlite3_bind_parameter_count(GetPreparedStatement());
}

Statement::~Statement(){}

std::shared_ptr<sqlite3_stmt> Statement::prepareStatement(void){
  sqlite3_stmt* stmt;
  char *tail;
  auto ret = sqlite3_prepare_v2(db.GetHandler(), query.c_str(),
                                static_cast<int>(query.size()),
                                &stmt, const_cast<const char**>(&tail));
  if (SQLITE_OK != ret) {
    throw error("Failed to prepare statement");
  }

  return std::shared_ptr<sqlite3_stmt>(
      stmt, [](sqlite3_stmt* stmt) { sqlite3_finalize(stmt);});
}

sqlite3_stmt* Statement::GetPreparedStatement() const {
  sqlite3_stmt* stmtPtr = prepared_stmt.get();
  if (!stmtPtr) {
    throw error("Statement is not prepared.");
  }
  return stmtPtr;
}

void Statement::close() noexcept {
  auto stmt = GetPreparedStatement();
  if (stmt) {
    sqlite3_finalize(stmt);
    stmt = nullptr;
  }
}

void Statement::executeStep() {
  int result = sqlite3_step(GetPreparedStatement());
  int ext_res = sqlite3_extended_errcode(db.GetHandler());
  if (result != 101 || sqlite3_reset(GetPreparedStatement()) != 0) {
    db.Execute("ROLLBACK");
    close();
    throw error("Failed to execute steps.");
  }
}

void Statement::bind(const size_t i, const int32_t &value) {
  sqlite3_bind_int(GetPreparedStatement(), i + 1, value);
}


void Statement::bind(const size_t i, const uint32_t &value) {
  sqlite3_bind_int(GetPreparedStatement(), i + 1, value);
}

void Statement::bind(const size_t i, const int64_t &value) {
  sqlite3_bind_int64(GetPreparedStatement(), i + 1, value);
}

void Statement::bind(const size_t i, const uint64_t &value) {
  sqlite3_bind_int64(GetPreparedStatement(), i + 1, value);
}

void Statement::bind(const size_t i, const double &value) {
  sqlite3_bind_double(GetPreparedStatement(), i + 1, value);
}

void Statement::bind(const size_t i, const std::nullptr_t &value) {
  sqlite3_bind_null(GetPreparedStatement(), i + 1);
}

void Statement::bind(const size_t i, const char* &value) {
  sqlite3_bind_text(GetPreparedStatement(), i + 1,
                    value, strlen(value), SQLITE_TRANSIENT);
}

void Statement::bind(const size_t i, const std::string &value) {
  sqlite3_bind_text(GetPreparedStatement(), i + 1,
                    value.c_str(), value.size(), SQLITE_TRANSIENT);
}

Connection::Connection(const std::string &db_name,
                       const int busyTimeouts)
                      : dbFilename(db_name),
                        last_error_message(nullptr)
{
  sqlite3* db_handle;
  const int ret = sqlite3_open(db_name.c_str(), &db_handle);
  db.reset(db_handle);

  if (ret != SQLITE_OK) {
    throw error("Failed to open database");
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
    stmt->close();
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
    throw error("Failed to create function");
  }
}

void Connection::DeleteFunction(std::string func_name, unsigned n_args, unsigned flags) {
  int rflags = flags | SQLITE_UTF8;
  auto ret = sqlite3_create_function_v2(GetHandler(), func_name.c_str(), n_args, rflags,
                                        nullptr, nullptr, nullptr, nullptr, nullptr);
  if (ret != SQLITE_OK) {
    throw error("Failed to create function");
  }
}

void Connection::SetBusyTimeout(const int32_t timeout) {
  const int ret = sqlite3_busy_timeout(GetHandler(), timeout);
  if (ret != SQLITE_OK) {
    throw error("Failed to set timeout");
  }
}

void Connection::Execute(const std::string& query) {
  if (sqlite3_exec(GetHandler(), query.c_str(),
                   nullptr, nullptr, &last_error_message)) {
    throw error(last_error_message);
  }
}

std::unique_ptr<Statement> Connection::Prepare(const std::string& query) {
  Execute("begin transaction");
  auto stmt = std::make_unique<Statement>(*this, query);
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

} // namespace sqlite
