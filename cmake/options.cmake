#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type")
set(CMAKE_EXPORT_COMPILE_COMMANDS true CACHE BOOL "Generate the compile_commands.json file (forced)" FORCE)
set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ standard version")

set(MX_INSTALL_LIB_DIR "${CMAKE_INSTALL_LIBDIR}" CACHE PATH "Directory in which Multiplier libraries will be installed")
set(MX_INSTALL_BIN_DIR "${CMAKE_INSTALL_BINDIR}" CACHE PATH "Directory in which Multiplier binaries will be installed")
set(MX_INSTALL_INCLUDE_DIR "${CMAKE_INSTALL_INCLUDEDIR}/multiplier" CACHE PATH "Directory in which Multiplier headers will be installed")
set(MX_INSTALL_SHARE_DIR "${CMAKE_INSTALL_DATADIR}" CACHE PATH "Directory in which Multiplier CMake files will be installed")

option(MX_USE_VENDORED_CAPNPROTO "Set to OFF to disable default building of Cap'n Proto as a vendored library." ON)
option(MX_USE_VENDORED_GLOG "Set to OFF to disable default building of Google glog as a vendored library." ON)
option(MX_USE_VENDORED_GFLAGS "Set to OFF to disable default building of gflags as a vendored library." ON)
option(MX_USE_VENDORED_ZSTD "Set to OFF to disable default building of ZStandard as a vendored library." ON)
option(MX_USE_VENDORED_REPROC "Set to OFF to disable default building of reproc/reproc++ as a vendored library." ON)
option(MX_USE_VENDORED_GAP "Set to OFF to disable default building of gap as a vendored library." ON)
option(MX_USE_VENDORED_CLANG "Set to OFF to disable default building of Clang/LLVM as a vendored library." ON)
option(MX_USE_VENDORED_PASTA "Set to OFF to disable default building of PASTA as a vendored library." ON)
option(MX_USE_VENDORED_ABSEIL "Set to OFF to disable default building of Abseil as a vendored library." ON)
option(MX_USE_VENDORED_RE2 "Set to OFF to disable default building of RE2 as a vendored library." ON)
option(MX_USE_VENDORED_ROCKSDB "Set to OFF to disable default building of RocksDB as a vendored library." ON)
option(MX_USE_VENDORED_XXHASH "Set to OFF to disable default building of xxHash as a vendored library." ON)
option(MX_USE_VENDORED_NANOBIND "Set to OFF to disable default building of nanobind as a vendored library." ON)

option(MX_ENABLE_BOOTSTRAP "Set to ON to enable re-bootstrapping of some auto-generated files." OFF)
option(MX_ENABLE_INSTALL "Set to ON to enable the install target" ON)
option(MX_ENABLE_RE2 "Set to OFF to disable RE2 integration" ON)
option(MX_ENABLE_VAST "Set to OFF to disable VAST integration" ON)
option(MX_ENABLE_PYTHON_BINDINGS "Set to ON to enable Python bindings" OFF)