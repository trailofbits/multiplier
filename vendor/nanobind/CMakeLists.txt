#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT MX_USE_VENDORED_NANOBIND)
  
  if(DEFINED nanobind_DIR)
      message(NOTICE "nanobind_DIR is defined, using it instead of invoking module")
  else()
      execute_process(
          COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
          OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE NB_DIR
          COMMAND_ERROR_IS_FATAL ANY)
      list(APPEND CMAKE_PREFIX_PATH "${NB_DIR}")
  endif()

  find_package(nanobind CONFIG QUIET)
  if(nanobind_FOUND)
    return()
  endif()
endif()

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")

# Fetch the submodule if we don't yet have it.
if(NOT EXISTS "${src_dir}/CMakeLists.txt")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule update --init --recursive src
    WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
endif()

add_subdirectory("${src_dir}")
