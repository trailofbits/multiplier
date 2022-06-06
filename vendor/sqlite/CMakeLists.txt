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
    URL      https://sqlite.org/2022/sqlite-amalgamation-3380500.zip
    URL_HASH SHA3_256=bfad5c42b767520a546251b9876e4a4b127fb651c437b968b149070e09252807
  )
  FetchContent_MakeAvailable(sqlite)

  add_library(SQLite3
    "${sqlite_SOURCE_DIR}/sqlite3.c"
  )
  target_include_directories(SQLite3
    PUBLIC
      "${SQLite3_INCLUDE_DIRS}")
  target_compile_definitions(SQLite3
    PRIVATE
      "-DSQLITE_ENABLE_FTS5"
      "-DSQLITE_ENABLE_RTREE")
  add_library(SQLite::SQLite3 ALIAS SQLite3)

  set(SQLite3_VERSION "3.38.5")
  set(SQLite3_INCLUDE_DIRS "${sqlite_SOURCE_DIR}")
  set(SQLite3_LIBRARIES SQLite::SQLite3)
  set(SQLite3_FOUND TRUE)
endmacro()