#
# Copyright (c) 2024-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")

# Fetch the submodule if we don't yet have it.
if(NOT EXISTS "${src_dir}/CMakeLists.txt")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule update --init vendor/intervaltree/src
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()

add_library(intervaltree INTERFACE)

target_include_directories(intervaltree INTERFACE
  "${CMAKE_CURRENT_LIST_DIR}/src")

target_compile_definitions(intervaltree INTERFACE
  USE_INTERVAL_TREE_NAMESPACE
)
