#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

include(FetchContent)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
  sqlite
  URL      https://www.sqlite.org/2024/sqlite-amalgamation-3460000.zip
  URL_HASH SHA3_256=1221eed70de626871912bfca144c00411f0c30d3c2b7935cff3963b63370ef7c
)

FetchContent_MakeAvailable(sqlite)

add_library("mx-sqlite" STATIC
  "${sqlite_SOURCE_DIR}/sqlite3.c"
)

target_include_directories("mx-sqlite"
  PUBLIC
    ${sqlite_SOURCE_DIR}
)

target_compile_definitions("mx-sqlite"
  PRIVATE
    $<$<CONFIG:Debug>:SQLITE_DEBUG=1>
    "-DSQLITE_ENABLE_FTS5"
    "-DSQLITE_ENABLE_RTREE"
    "-DSQLITE_UNTESTABLE"
    "-DSQLITE_OMIT_DECLTYPE"
    "-DSQLITE_OMIT_DEPRECATED"
    "-DSQLITE_OMIT_PROGRESS_CALLBACK"
    "-DSQLITE_OMIT_SHARED_CACHE"
    "-DSQLITE_OMIT_LOAD_EXTENSION"
    "-DSQLITE_LIKE_DOESNT_MATCH_BLOBS"
    "-DSQLITE_DEFAULT_MEMSTATUS=0"
    "-DSQLITE_MAX_EXPR_DEPTH=0"
    "-DSQLITE_THREADSAFE=2"
)

# TODO(pag): Consider installing sqlite.h into the header

set_target_properties("mx-sqlite"
  PROPERTIES
    LINKER_LANGUAGE
      C
    VISIBILITY_INLINES_HIDDEN
      YES
    PUBLIC_HEADER
      "${sqlite_SOURCE_DIR}/sqlite3.h"
    C_VISIBILITY_PRESET
      hidden
    POSITION_INDEPENDENT_CODE
      YES
)
