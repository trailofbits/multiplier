#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(MX_PY_VERSION 3.11)
find_package(Python3 REQUIRED COMPONENTS Development.SABIModule)

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

file(GLOB_RECURSE generated_sources CONFIGURE_DEPENDS RELATIVE_PATH "${CMAKE_CURRENT_LIST_DIR}/Generated" "*.cpp")

add_library("mx-python" STATIC
  "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/Bindings/Python.h"

  ${generated_sources}

  "Binding.cpp"
  "Binding.h"
  "Entity.cpp"
  "Error.cpp"
  "Error.h"
  "FileLocationCache.cpp"
  "Forward.h"  # Auto-generated.
  "Module.cpp"  # Auto-generated.
  "Types.cpp"  # Auto-generated.
  "Types.h"
)

set_target_properties("mx-python"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/Bindings/Python.h"
    VISIBILITY_INLINES_HIDDEN
      YES
    CXX_VISIBILITY_PRESET
      default
    POSITION_INDEPENDENT_CODE
      YES
    COMPILE_FEATURES
      cxx_std_20
    INTERFACE_COMPILE_FEATURES
      cxx_std_20
)

target_include_directories("mx-python"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}"
)

target_link_libraries("mx-python"
  PUBLIC
    Python3::SABIModule
  PRIVATE
    "mx-api"
)
