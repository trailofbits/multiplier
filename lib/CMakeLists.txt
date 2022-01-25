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
  "${source_include_dir}/Executor.h"
  "${source_include_dir}/Result.h"
  "${source_include_dir}/Signal.h"
  "${source_include_dir}/Subprocess.h"
  "${source_include_dir}/Types.h"
  "${source_include_dir}/WorkerPool.h"
)

add_library("util"
  STATIC
    ${util_headers}

    "Action.cpp"
    "Executor.cpp"
    "Signal.cpp"
    "Subprocess.cpp"
    "Types.cpp"
    "WorkerPool.cpp"
)

target_include_directories("util"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries("util"
  PRIVATE
    $<BUILD_INTERFACE:concurrentqueue>
  PUBLIC
    glog::glog
    gflags::gflags
    pasta::pasta
)

set_target_properties("util"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${util_headers}"
)

target_compile_features("util"
  PUBLIC
    cxx_std_20
)

add_subdirectory("Datalog")

# util relies on auto-generated headers from the Datalog code, but the Datalog
# server client code also relies on util. Thus we need to interpose util
# compilation after the Dr. Lojekyll compiler generates files, but before any
# of those files are actually compiled.
add_dependencies("util"
  "copy_datalog_server_headers"
)

set(public_headers
  ${copied_headers}
  "${source_include_dir}/Datalog.h"
  "${source_include_dir}/Tool.h"
)

add_library("tool"
  STATIC
    ${public_headers}
    
    "Database.h"
    "Database.cpp"
    "Tool.cpp"
)


add_library("${PROJECT_NAME}::tool" ALIAS "tool")
set_target_properties("tool" PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries("tool"
  PRIVATE
    $<BUILD_INTERFACE:datalog_server_client>
    
  PUBLIC
    DrLojekyll::Runtime
    "util")

set_target_properties("tool"
  PROPERTIES
    PUBLIC_HEADER "${public_headers}")

target_include_directories("tool"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/lib>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_library("tool_main" OBJECT
  ${public_headers}

  "ToolMain.cpp")


add_library("${PROJECT_NAME}::tool_main" ALIAS "tool_main")
set_target_properties("tool_main" PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries("tool_main"
  PUBLIC
    glog::glog
    gflags::gflags
    "tool")

set_target_properties("tool_main"
  PROPERTIES
    PUBLIC_HEADER "${public_headers}")

target_include_directories("tool_main"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

if(MX_ENABLE_INSTALL)

  install(
    TARGETS
      "util"
      "tool"
      "tool_main"
    EXPORT "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "bin"
    LIBRARY
      DESTINATION
        "lib"
    ARCHIVE
      DESTINATION
        "lib"
    PUBLIC_HEADER
      DESTINATION
        "include/${lower_project_name}"
  )
endif(MX_ENABLE_INSTALL)
