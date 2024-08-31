#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

find_package(Git REQUIRED)

execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${MX_VENDOR_INSTALL_DIR}")

add_subdirectory(capnproto)
add_subdirectory(gflags)
add_subdirectory(glog)  # Depends on gflags
add_subdirectory(concurrentqueue)
add_subdirectory(reproc)
add_subdirectory(sqlite)
add_subdirectory(zstd)
add_subdirectory(xxhash)
add_subdirectory(rocksdb)  # Depends on zstd, gflags
add_subdirectory(llvm-project)  # Depends on zstd
add_subdirectory(pasta)  # Depends on llvm-project
add_subdirectory(gap)  # Depends on llvm-project
add_subdirectory(vast)  # Depends on gap, llvm-project
add_subdirectory(intervaltree)

if(MX_ENABLE_RE2)
  add_subdirectory(abseil)
  add_subdirectory(re2)  # Depends on abseil
endif()
