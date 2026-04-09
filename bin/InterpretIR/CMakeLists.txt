#
# Copyright (c) 2024-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable("mx-interpret-ir"
  "InterpretIR.cpp"
)

target_link_libraries("mx-interpret-ir"
  PRIVATE
    "mx-example-index"
)

set_target_properties("mx-interpret-ir"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    RUNTIME_OUTPUT_DIRECTORY
      "${PROJECT_BINARY_DIR}/${MX_INSTALL_BIN_DIR}"
)

target_include_directories("mx-interpret-ir"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../Examples"
)

if(MX_ENABLE_INSTALL AND NOT MX_ENABLE_BOOTSTRAP)
  install(
    TARGETS
      "mx-interpret-ir"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
  )
endif()
