#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library(concurrentqueue INTERFACE)

target_include_directories(concurrentqueue INTERFACE
  "${CMAKE_CURRENT_LIST_DIR}/src")