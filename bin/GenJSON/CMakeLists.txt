#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_custom_target(GenJSON ALL
    COMMAND
        "${CMAKE_C_COMPILER}" -E -P "-I${PROJECT_SOURCE_DIR}/include"
        -o "${CMAKE_CURRENT_BINARY_DIR}/Multiplier.json"
        "${CMAKE_CURRENT_SOURCE_DIR}/Multiplier.json.c"
)

if(MX_ENABLE_INSTALL)
  install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/Multiplier.json"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/multiplier
  )
endif()
