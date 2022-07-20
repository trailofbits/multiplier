#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library("mx-syntex"
  "Private.h"
  "Public/Syntex.h"
  "AST.cpp"
  "Grammar.cpp"
  "Query.cpp"
  )

target_include_directories("mx-syntex"
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Public"
  )

target_link_libraries("mx-syntex"
  PRIVATE
  "mx-api"
  "mx-util"
  glog::glog
  )
