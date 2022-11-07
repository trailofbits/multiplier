#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable("syntex-query" "SyntexQuery.cpp")

target_link_libraries("syntex-query"
  PRIVATE
    gflags
    glog::glog
    "mx-api"
)

install(
  TARGETS
    "syntex-query"
  EXPORT
    "${PROJECT_NAME}Targets"
  RUNTIME
    DESTINATION
      "${CMAKE_INSTALL_BINDIR}"
)

add_executable("predicate-example" "PredicateExample.cpp")

target_link_libraries("predicate-example"
  PRIVATE
    gflags
    glog::glog
    "mx-api"
)
