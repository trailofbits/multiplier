#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

include(FetchContent)

macro(DownloadSQLite3)
  FetchContent_Declare(
    sqlite
    URL      https://sqlite.org/2022/sqlite-amalgamation-3390400.zip
    URL_HASH SHA3_256=96894cf2c57f76ccbeda41aa6ff0ce1f6b093deced8335801d38ddb34ec9690e
    DOWNLOAD_EXTRACT_TIMESTAMP FALSE
  )
  FetchContent_MakeAvailable(sqlite)

  add_library(SQLite3 STATIC
    "${sqlite_SOURCE_DIR}/sqlite3.c"
  )
  target_include_directories(SQLite3
    PUBLIC
      "${sqlite_SOURCE_DIR}")

  target_compile_definitions(SQLite3
    PRIVATE
      "-DSQLITE_ENABLE_FTS5"
      "-DSQLITE_ENABLE_RTREE"
      "-DSQLITE_THREADSAFE=2")
  set_target_properties(SQLite3
    PROPERTIES
      C_VISIBILITY_PRESET   default
      CXX_VISIBILITY_PRESET default
  )
  add_library(SQLite::SQLite3 ALIAS SQLite3)

  set(SQLite3_VERSION "3.39.4")
  set(SQLite3_INCLUDE_DIRS "${sqlite_SOURCE_DIR}")
  set(SQLite3_LIBRARIES SQLite::SQLite3)
  set(SQLite3_FOUND TRUE)
endmacro()