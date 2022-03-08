#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

include(ExternalProject)

ExternalProject_Add(capnproto
  GIT_REPOSITORY
    https://github.com/capnproto/capnproto.git
  UPDATE_DISCONNECTED
    TRUE
  SOURCE_DIR
    "${CMAKE_CURRENT_BINARY_DIR}/source"
  BINARY_DIR
    "${CMAKE_CURRENT_BINARY_DIR}/build"
  CONFIGURE_COMMAND
    "${CMAKE_COMMAND}"
        -G "${CMAKE_GENERATOR}"
        "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/install"
        -DBUILD_TESTING=OFF
        "${CMAKE_CURRENT_BINARY_DIR}/source"
  BUILD_COMMAND
    "${CMAKE_COMMAND}" --build .
  INSTALL_COMMAND
    "${CMAKE_COMMAND}" --build . --target install
  TEST_COMMAND
    "")