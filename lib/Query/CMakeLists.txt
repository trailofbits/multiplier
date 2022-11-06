#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

add_library("mx-syntex"
  "AST.h"
  "AST.cpp"
  "Grammar.h"
  "Grammar.cpp"
  "NodeKind.h"
  "Query.h"
  "Query.cpp"
)

target_include_directories("mx-syntex"
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries("mx-syntex"
  PRIVATE
    "absl::hash"
    "absl::raw_hash_set"
  PUBLIC
    "mx-api"
    "mx-util"
)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "mx-syntex"
    EXPORT "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
    LIBRARY
      DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE
      DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER
      DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/${lower_project_name}"
  )
endif(MX_ENABLE_INSTALL)
