#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

include(FetchContent)

macro(DownloadSQLite3)

  #FetchContent_Declare(
  #  sqlite
  #  GIT_REPOSITORY https://github.com/sqlite/sqlite.git
  #  GIT_TAG 5dd26c5ed1446616fd3b831a03b718ef6d6ce0c7 # begin-concurrent-3.39
  #  GIT_SHALLOW
  #)

  FetchContent_Declare(
    sqlite
    URL      https://sqlite.org/2022/sqlite-amalgamation-3400000.zip
    URL_HASH SHA3_256=362a64ad2891c6ff7552f039f3f233d49da984446be0862183eb5cef0d665969
  )
  
  FetchContent_MakeAvailable(sqlite)

  add_library(SQLite3 STATIC
    "${sqlite_SOURCE_DIR}/sqlite3.c"
  )
  
  target_include_directories(SQLite3
    PUBLIC
      "${sqlite_SOURCE_DIR}"
  )

  target_compile_definitions(SQLite3
    PRIVATE
      $<$<CONFIG:Debug>:SQLITE_DEBUG=1>
      "-DSQLITE_ENABLE_FTS5"
      "-DSQLITE_ENABLE_RTREE"
      "-DSQLITE_UNTESTABLE"
      "-DSQLITE_OMIT_DECLTYPE"
      "-DSQLITE_OMIT_DEPRECATED"
      "-DSQLITE_OMIT_PROGRESS_CALLBACK"
      "-DSQLITE_OMIT_SHARED_CACHE"
      "-DSQLITE_LIKE_DOESNT_MATCH_BLOBS"
      "-DSQLITE_DEFAULT_MEMSTATUS=0"
      "-DSQLITE_MAX_EXPR_DEPTH=0"
      "-DSQLITE_THREADSAFE=2"
  )
  
  set_target_properties(SQLite3
    PROPERTIES
      C_VISIBILITY_PRESET   default
      CXX_VISIBILITY_PRESET default
  )
  
  add_library(SQLite::SQLite3 ALIAS SQLite3)

  set(SQLite3_VERSION "3.40.0")
  set(SQLite3_INCLUDE_DIRS "${sqlite_SOURCE_DIR}")
  set(SQLite3_LIBRARIES SQLite::SQLite3)
  set(SQLite3_FOUND TRUE)
endmacro()