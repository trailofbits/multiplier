#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

corrosion_import_crate(MANIFEST_PATH src/Cargo.toml)

add_custom_command(
    OUTPUT ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_INCLUDEDIR}/weggli.h
    COMMAND
        ${CBINDGEN} ${CMAKE_CURRENT_SOURCE_DIR}/src/
        -o ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_INCLUDEDIR}/weggli.h
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/src/lib.rs)

# Adds target for generating weggli.h
add_custom_target(weggli_header DEPENDS ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_INCLUDEDIR}/weggli.h)

add_dependencies(weggli_native weggli_header)