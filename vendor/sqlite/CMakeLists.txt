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
  URL      https://sqlite.org/2022/sqlite-amalgamation-3400000.zip
  URL_HASH SHA3_256=362a64ad2891c6ff7552f039f3f233d49da984446be0862183eb5cef0d665969
)

FetchContent_MakeAvailable(sqlite)

add_library("mx-sqlite" STATIC
  "${sqlite_SOURCE_DIR}/sqlite3.c"
)

target_include_directories("mx-sqlite"
  PUBLIC
    $<BUILD_INTERFACE:${sqlite_SOURCE_DIR}>
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

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "mx-sqlite"
    EXPORT "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
    LIBRARY
      DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE
      DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER
      DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/${lower_project_name}"
  )
endif(MX_ENABLE_INSTALL)
