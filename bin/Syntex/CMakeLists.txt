#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable("syntex-index"
  "AST.cpp"
  "AST.h"
  "Grammar.cpp"
  "Grammar.h"
  "Index.cpp"
)

target_link_libraries("syntex-index"
  PRIVATE
    "mx-api"
    "mx-util"
    glog::glog
    gflags::gflags
)

# TODO: Add syntex-query.

set_target_properties("syntex-index" PROPERTIES LINKER_LANGUAGE CXX)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "syntex-index"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
  )
endif()