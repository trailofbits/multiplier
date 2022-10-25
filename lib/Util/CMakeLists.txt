#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

set(source_include_dir "${PROJECT_SOURCE_DIR}/include/${lower_project_name}")
set(binary_include_dir "${PROJECT_BINARY_DIR}/include/${lower_project_name}")

set(util_headers
  "${source_include_dir}/Action.h"
  "${source_include_dir}/BloomFilter.h"
  "${source_include_dir}/Compiler.h"
  "${source_include_dir}/Compress.h"
  "${source_include_dir}/Endian.h"
  "${source_include_dir}/Executor.h"
  "${source_include_dir}/Int.h"
  "${source_include_dir}/PersistentMap.h"
  "${source_include_dir}/ProgressBar.h"
  "${source_include_dir}/Signal.h"
  "${source_include_dir}/Serialize.h"
  "${source_include_dir}/SQLiteStore.h"
  "${source_include_dir}/Subprocess.h"
  "${source_include_dir}/WorkerPool.h"

  # Auto-generated.
  "${MX_BOOTSTRAP_INCLUDE_DIR}/AST.h"
  "${MX_BOOTSTRAP_INCLUDE_PASTA_H}"
)

add_library("mx-util"
  STATIC
    ${util_headers}

    "Action.cpp"
    "BloomFilter.cpp"
    "Executor.cpp"
    "PersistentMap.cpp"
    "ProgressBar.cpp"
    "Signal.cpp"
    "Subprocess.cpp"
    "SymbolDatabase.cpp"
    "WorkerPool.cpp"
    "SQLiteStore.cpp"

    # Auto-generated
    "${MX_BOOTSTRAP_LIB_UTIL_PASTA_CPP}"
)

target_compile_definitions("mx-util"
  PRIVATE
    "MX_DISABLE_API"
)

target_link_libraries("mx-util"
  PUBLIC
    "mx-common"
    "glog::glog"
    $<BUILD_INTERFACE:concurrentqueue>
    $<BUILD_INTERFACE:gflags::gflags>
    $<BUILD_INTERFACE:SQLite::SQLite3>
  PRIVATE
    $<BUILD_INTERFACE:reproc++>
)

set_target_properties("mx-util"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${util_headers}"
    VISIBILITY_INLINES_HIDDEN
      YES
    CXX_VISIBILITY_PRESET
      hidden
    POSITION_INDEPENDENT_CODE
      YES
)

target_include_directories("mx-util"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "mx-util"
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
  install(DIRECTORY "${MX_BOOTSTRAP_INCLUDE_DIR}" TYPE INCLUDE)
endif(MX_ENABLE_INSTALL)
