#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(exe_name "mx-bootstrap")

add_executable("${exe_name}"
  Main.cpp
)

set_target_properties("${exe_name}"
  PROPERTIES
    LINKER_LANGUAGE
      CXX)

target_link_libraries("${exe_name}"
  PRIVATE
    pasta::pasta
)

# `mx-bootstrap` works by running PASTA on itself. To be successful at this, it
# needs to know the actual include directories of Multiplier and its
# dependencies. We pass those in at the first two arguments.
set(install_include_dir "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
set(dependencies_include_dir "${VCPKG_ROOT_INSTALL_DIR}/${VCPKG_TARGET_TRIPLET}/${CMAKE_INSTALL_INCLUDEDIR}")

set(generated_files
  "${MX_BOOTSTRAP_LIB_AST_CAPNP}"
  "${MX_BOOTSTRAP_LIB_AST_H}"
  "${MX_BOOTSTRAP_LIB_AST_CPP}"
  "${MX_BOOTSTRAP_INCLUDE_AST_H}"
  "${MX_BOOTSTRAP_INDEX_SERIALIZE_H}"
  "${MX_BOOTSTRAP_INDEX_SERIALIZE_CPP}"
)

# Run `mx-bootstrap` to auto-generate the files.
add_custom_command(
  TARGET
    "${exe_name}"
  POST_BUILD
  BYPRODUCTS
    ${generated_files}
  COMMAND
    "${exe_name}"
    "${install_include_dir}"
    "${dependencies_include_dir}"
    ${generated_files}
  COMMENT
    "Bootstrapping Multiplier"
)