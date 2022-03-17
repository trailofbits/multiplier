#
# Copyright (c) 2020-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT TARGET reproc AND NOT TARGET reproc++)
  add_subdirectory(
    "${CMAKE_CURRENT_LIST_DIR}/../reproc"
    "${CMAKE_BINARY_DIR}/vendor/reproc"
    EXCLUDE_FROM_ALL
  )
endif()
