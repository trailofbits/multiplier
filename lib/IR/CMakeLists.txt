#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

set(ir_source_include_dir "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/IR")

file(GLOB_RECURSE ir_sources CONFIGURE_DEPENDS RELATIVE_PATH "${CMAKE_CURRENT_LIST_DIR}" "*.cpp")
file(GLOB_RECURSE ir_headers CONFIGURE_DEPENDS RELATIVE_PATH "${ir_source_include_dir}" "*.h")

add_library("mx-mlir" STATIC
  ${ir_headers}
  ${ir_sources}
)

target_include_directories("mx-mlir"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}"
)

set_target_properties("mx-mlir"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    VISIBILITY_INLINES_HIDDEN
      YES
    CXX_VISIBILITY_PRESET
      hidden
    POSITION_INDEPENDENT_CODE
      YES
)

target_link_directories("mx-mlir"
  PRIVATE
    "${MLIR_LIB_DIR}"
)

target_link_libraries("mx-mlir"
  PUBLIC
    "gap::gap"
    "gap::gap-core"
    "std::coroutines"
    "gap::gap-settings"

  PRIVATE
    ${MLIR_LIBS}
    ${VAST_LIBS}
)

if(MX_ENABLE_INSTALL)
  install(
    DIRECTORY
      "${ir_source_include_dir}"
    DESTINATION
      "${MX_INSTALL_INCLUDE_DIR}/IR"
  )

  install(
    TARGETS
      "mx-mlir"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${MX_INSTALL_BIN_DIR}"
    LIBRARY
      DESTINATION
        "${MX_INSTALL_LIB_DIR}"
    ARCHIVE
      DESTINATION
        "${MX_INSTALL_LIB_DIR}"
  )
endif(MX_ENABLE_INSTALL)
