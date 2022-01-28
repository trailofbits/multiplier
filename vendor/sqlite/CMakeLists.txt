#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

include(ExternalProject)

if(APPLE)
  set(sysroot_for_sqlite "-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")
endif(APPLE)

ExternalProject_Add(sqlite3
  URL
    https://www.sqlite.org/2022/sqlite-autoconf-3370200.tar.gz
  URL_HASH
    SHA3_256=3764f471d188ef4e7a70a120f6cb80014dc50bb5fa53406b566508390a32e745
  SOURCE_DIR
    ${CMAKE_CURRENT_BINARY_DIR}/sqlite3/source
  BINARY_DIR
    ${CMAKE_CURRENT_BINARY_DIR}/sqlite3/build
  CONFIGURE_COMMAND
    env "CFLAGS=-DSQLITE_PRINT_BUF_SIZE=256 ${sysroot_for_sqlite}" ${CMAKE_CURRENT_BINARY_DIR}/sqlite3/source/configure  "--prefix=${CMAKE_CURRENT_BINARY_DIR}/install" --enable-fts5 --enable-threadsafe --enable-rtree --enable-static --disable-shared CC=${CMAKE_C_COMPILER}
  BUILD_COMMAND
    make install
  INSTALL_COMMAND
    ""
  TEST_COMMAND
    "")