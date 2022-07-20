#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable("syntex-index" "Index.cpp")

target_link_libraries("syntex-index"
  PRIVATE
    "mx-api"
    "mx-util"
    "mx-syntex"
    glog::glog
    gflags::gflags
)

add_executable("${PROJECT_NAME}::syntex-index" ALIAS "syntex-index")
set_target_properties("syntex-index" PROPERTIES LINKER_LANGUAGE CXX)

add_executable("syntex-query" "Query.cpp")

target_link_libraries("syntex-query"
  PRIVATE
    "mx-api"
    "mx-util"
    "mx-syntex"
    glog::glog
    gflags::gflags
)

add_executable("${PROJECT_NAME}::syntex-query" ALIAS "syntex-query")
set_target_properties("syntex-query" PROPERTIES LINKER_LANGUAGE CXX)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "syntex-index"
      "syntex-query"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
  )
endif()
