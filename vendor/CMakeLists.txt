#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

find_package(Git REQUIRED)

if(MX_ENABLE_INSTALL)
  set(MX_VENDOR_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}")
else()
  set(MX_VENDOR_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/install")
  execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${MX_VENDOR_INSTALL_DIR}")
endif()

add_subdirectory(capnproto)
add_subdirectory(gflags)
add_subdirectory(glog)  # Depends on gflags
add_subdirectory(concurrentqueue)
add_subdirectory(reproc)
add_subdirectory(sqlite)
add_subdirectory(gap)
add_subdirectory(zstd)
add_subdirectory(xxhash)
add_subdirectory(rocksdb)  # Depends on zstd, gflags
add_subdirectory(llvm-project)  # Depends on zstd
add_subdirectory(pasta)  # Depends on llvm-project

if(MX_ENABLE_RE2)
  add_subdirectory(abseil)
  add_subdirectory(re2)  # Depends on abseil
endif()

if(MX_ENABLE_PYTHON_BINDINGS)
  add_subdirectory(nanobind)
endif()
