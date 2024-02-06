#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

find_package(Git REQUIRED)

find_package(CapnProto CONFIG REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(concurrentqueue MODULE REQUIRED)
find_package(reproc CONFIG REQUIRED)
find_package(SQLite3 MODULE REQUIRED)
find_package(gap CONFIG REQUIRED)
find_package(zstd CONFIG REQUIRED)
find_package(xxHash CONFIG REQUIRED)
find_package(RocksDB CONFIG REQUIRED)  # Depends on zstd, gflags
find_package(LLVM CONFIG REQUIRED)
find_package(MLIR CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)
find_package(pasta CONFIG REQUIRED)  # Depends on llvm-project
find_package(VAST CONFIG REQUIRED)  # Depends on gap, llvm-project

if(MX_ENABLE_RE2)
  find_package(absl CONFIG REQUIRED)
  find_package(re2 CONFIG REQUIRED)  # Depends on abseil
endif()
