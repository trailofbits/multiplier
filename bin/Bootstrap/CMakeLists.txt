#
# Copyright (c) 2022-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(exe_name "mx-bootstrap-pasta")

option(MX_BOOTSTRAP_PASTA "Set to ON to bootstrap PASTA" ON)
option(MX_BOOTSTRAP_VAST "Set to ON to bootstrap VAST" ON)

add_library("mx-bootstrap" STATIC
  "Bootstrap.cpp"
  "Bootstrap.h"
)

target_link_libraries("mx-bootstrap"
  PUBLIC
    pasta::pasta
)

target_compile_features("mx-bootstrap"
  PUBLIC
    "cxx_std_${CMAKE_CXX_STANDARD}"
)

set_target_properties("mx-bootstrap"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
)

# `mx-bootstrap` works by running PASTA on itself. To be successful at this, it
# needs to know the actual include directories of Multiplier and its
# dependencies. We pass those in at the first two arguments.
set(install_include_dir "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
list(GET LLVM_INCLUDE_DIRS 0 dependencies_include_dir)

target_include_directories("mx-bootstrap" PUBLIC
    ${LLVM_INCLUDE_DIRS}
  )

if(MX_BOOTSTRAP_PASTA)
  add_executable("mx-bootstrap-pasta"
    "PASTA.cpp"
    "${PROJECT_SOURCE_DIR}/bin/Index/Entity.h"
  )
  
  target_link_libraries("mx-bootstrap-pasta"
    PRIVATE
      "mx-bootstrap"
  )
  
  set(generated_pasta_files
    "${MX_BOOTSTRAP_LIB_AST_CAPNP}"
    "${MX_BOOTSTRAP_LIB_DIR}"
    "${MX_BOOTSTRAP_INCLUDE_DIR}"
    "${MX_BOOTSTRAP_INDEX_SERIALIZE_H}"
    "${MX_BOOTSTRAP_INDEX_SERIALIZE_CPP}"
    "${MX_BOOTSTRAP_INCLUDE_VISITOR_INC_H}"
    "${MX_BOOTSTRAP_INDEX_PASTA_CPP}"
    "${MX_BOOTSTRAP_INDEX_PASTA_H}"
  )
  
  # Run `mx-bootstrap-pasta` to auto-generate the files.
  add_custom_command(
    TARGET
      "mx-bootstrap-pasta"
    POST_BUILD
    BYPRODUCTS
      ${generated_pasta_files}
    COMMAND
      "mx-bootstrap-pasta"
      "${install_include_dir}"
      "${dependencies_include_dir}"
      "${LLVM_INCLUDE_DIR}"
      ${generated_pasta_files}
    COMMENT
      "Bootstrapping Multiplier"
  )
endif(MX_BOOTSTRAP_PASTA)

if(MX_BOOTSTRAP_VAST)
  add_executable("mx-bootstrap-vast"
    "VAST.cpp"
    "${PROJECT_SOURCE_DIR}/bin/Index/Entity.h"
  )
  
  target_link_libraries("mx-bootstrap-vast"
    PRIVATE
      "mx-bootstrap"

      ${MLIR_LIBS}
      ${VAST_LIBS}
  )
  
  # Run `mx-bootstrap-vast` to auto-generate the files.
  add_custom_command(
    TARGET
      "mx-bootstrap-vast"
    POST_BUILD
    COMMAND
      "mx-bootstrap-vast"
      "${install_include_dir}"
      "${dependencies_include_dir}"
      "${LLVM_INCLUDE_DIR}"
    COMMENT
      "Bootstrapping Multiplier"
  )
endif(MX_BOOTSTRAP_VAST)
