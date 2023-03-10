#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

set(source_include_dir "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/Analysis")

set(analysis_headers
  "${source_include_dir}/Taint.h"
)

add_library("mx-analysis" STATIC
  "${analysis_headers}"
  "Taint.cpp"
)

target_link_libraries("mx-analysis"
  PUBLIC
    "mx-api"
)

target_compile_options("mx-analysis"
  PRIVATE
    "-Wno-unknown-warning-option"
    "-Wno-pragmas"
)

target_include_directories("mx-analysis"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}"
)

set_target_properties("mx-analysis"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${analysis_headers}"
    VISIBILITY_INLINES_HIDDEN
      YES
    CXX_VISIBILITY_PRESET
      hidden
    POSITION_INDEPENDENT_CODE
      YES
    COMPILE_FEATURES
      cxx_std_20
    INTERFACE_COMPILE_FEATURES
      cxx_std_20
)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "mx-analysis"
    EXPORT
      "${PROJECT_NAME}Targets"
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
        "${CMAKE_INSTALL_INCLUDEDIR}/${lower_project_name}/Analysis"
  )
endif(MX_ENABLE_INSTALL)
