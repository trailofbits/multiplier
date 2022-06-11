// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT1

#include "MultiplierModule.h"
#include <cassert>
#include <multiplier/AST.h>

#ifdef _WIN32
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT extern "C" __attribute__((visibility("default")))
#endif

EXPORT int sqlite3_sqlitebridge_init(sqlite3 *db, char **pzErrMsg,
                                     const sqlite3_api_routines *pApi) {
  int rc = SQLITE_OK;
  SQLITE_EXTENSION_INIT2(pApi);

#define MX_BEGIN_ENUM_CLASS(NAME, ...)                                         \
  rc = sqlite3_create_function(db, #NAME, 1,                                   \
  SQLITE_UTF8 | SQLITE_DETERMINISTIC, nullptr,                                 \
  [](sqlite3_context* ctx, int argc, sqlite3_value** argv) {                   \
    assert(argc == 1);                                                         \
    std::string input{reinterpret_cast<const char*>(sqlite3_value_text(argv[0]))};

#define MX_ENUM_CLASS_ENTRY(NAME, ENTRY, ...)                                  \
  if (input == #ENTRY) {                                                       \
    sqlite3_result_int64(ctx, static_cast<std::int64_t>(mx::NAME::ENTRY));     \
  } else

#define MX_END_ENUM_CLASS(NAME)                                                \
  { sqlite3_result_null(ctx); }                                                \
  }, nullptr, nullptr);                                                        \
  if (rc != SQLITE_OK) {                                                       \
    return rc;                                                                 \
  }
#undef EXPORT
#include <multiplier/Visitor.inc.h>

  rc = sqlite3_create_function(
      db, "containing", 2, SQLITE_UTF8 | SQLITE_DETERMINISTIC, nullptr,
      [](sqlite3_context *ctx, int argc, sqlite3_value **argv) {
        sqlite3_result_int(ctx, 0);
      },
      nullptr, nullptr);
  if (rc != SQLITE_OK) {
    return rc;
  }

  rc = (new sqlite_bridge::MultiplierModule())->Register(db, "multiplier");
  if (rc != SQLITE_OK) {
    return rc;
  }

  return (new sqlite_bridge::ConnectionModule())
      ->Register(db, "MultiplierConnection");
}