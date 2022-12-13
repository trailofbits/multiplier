#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

set(source_include_dir "${PROJECT_SOURCE_DIR}/include/${lower_project_name}")
set(binary_include_dir "${PROJECT_BINARY_DIR}/include/${lower_project_name}")

# Auto-generate C++ headers and sources from our Cap'n Proto schemas.
capnp_generate_cpp(MX_RPC_SOURCES MX_RPC_HEADERS RPC.capnp)
capnp_generate_cpp(MX_AST_SOURCES MX_AST_HEADERS AST.capnp)  # Bootstrapped file.

# Generate the commands to copy the headers into the binary include directory.
set(copied_headers "")
set(copy_headers_commands "")
foreach(capnp_header_path ${MX_RPC_HEADERS} ${MX_AST_HEADERS})
  get_filename_component(header_name "${capnp_header_path}" NAME)
  set(output_header_path "${binary_include_dir}/${header_name}")
  list(APPEND copied_headers $<BUILD_INTERFACE:${output_header_path}>)
  list(APPEND copy_headers_commands
    COMMAND
    "${CMAKE_COMMAND}"
    -E
    copy
    "${capnp_header_path}"
    "${output_header_path}"
  )
endforeach()

# Copy the auto-generated headers into the binary include directory.
add_custom_command(
  OUTPUT
    ${copied_headers}
  
  COMMAND "${CMAKE_COMMAND}" -E make_directory "${binary_include_dir}"
  ${copy_headers_commands}

  DEPENDS
    ${MX_RPC_HEADERS}
    ${MX_AST_HEADERS}

  COMMENT
    "Exporting Cap'n Proto-generated headers"

  VERBATIM
)

add_custom_target("copy_headers"
  DEPENDS
    ${copied_headers}
)

set(common_headers
  "${source_include_dir}/Compress.h"
  "${source_include_dir}/Result.h"
  "${source_include_dir}/Re2.h"
  "${source_include_dir}/Types.h"
  "${source_include_dir}/Weggli.h"
)

add_library("mx-common" STATIC
  ${common_headers}
  "${source_include_dir}/IndexStorage.h"
  
  "Compress.cpp"
  "IndexStorage.cpp"
  "Re2.cpp"
  "Re2.h"
  "SQLiteStore.cpp"
  "SymbolDatabase.cpp"
  "Types.cpp"
  "Weggli.cpp"

  # Auto-generated.
  ${copied_headers}
  ${MX_AST_SOURCES}
  ${MX_RPC_SOURCES}
)

add_dependencies("mx-common"
  "copy_headers"
)

target_link_libraries("mx-common"
  PUBLIC
    "CapnProto::capnp-rpc"
    SQLite::SQLite3
    gap::gap
    gap::gap-core
    std::coroutines
    gap::gap-settings
  PRIVATE
    $<BUILD_INTERFACE:concurrentqueue>
    "ZLIB::ZLIB"
)

if(MX_ENABLE_RE2)
  target_link_libraries("mx-common"
    PRIVATE
      "re2::re2"
  )
else()
  target_compile_definitions("mx-common"
    PUBLIC
      "MX_DISABLE_RE2")
endif()


if(MX_ENABLE_WEGGLI)
  target_link_libraries("mx-common"
    PRIVATE
      "weggli_native::static"
  )
else()
  target_compile_definitions("mx-common"
    PUBLIC
      "MX_DISABLE_WEGGLI")
endif()

target_include_directories("mx-common"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}"
)

set_target_properties("mx-common"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${common_headers}"
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
      "mx-common"
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
