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

file(GLOB frontend_headers CONFIGURE_DEPENDS "${MX_BOOTSTRAP_INCLUDE_DIR}/Frontend/*.h")
file(GLOB frontend_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Frontend/*.cpp")

file(GLOB ast_headers CONFIGURE_DEPENDS "${MX_BOOTSTRAP_INCLUDE_DIR}/AST/*.h")
file(GLOB ast_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/AST/*.cpp")

set(ir_source_include_dir "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/IR")

file(GLOB_RECURSE ir_sources CONFIGURE_DEPENDS RELATIVE_PATH "${CMAKE_CURRENT_LIST_DIR}" "*.cpp")
file(GLOB_RECURSE ir_headers CONFIGURE_DEPENDS RELATIVE_PATH "${ir_source_include_dir}" "*.h")

# Configure the version to include the git hash.
#
# TODO(pag): This only tracks the hash that was present at CMake configure time.
get_patch_from_git(MX_GIT_HASH)
configure_file(Version.cpp.in "${PROJECT_BINARY_DIR}/lib/Version.cpp" @ONLY)

add_library("mx-serialize" INTERFACE
  ${MX_AST_SOURCES}
  ${MX_RPC_SOURCES}
)

set_target_properties("mx-serialize"
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

target_link_libraries("mx-serialize"
  INTERFACE
    "CapnProto::capnp"
)

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

set(api_headers
  "${source_include_dir}/AST.h"  # Auto-generated.
  "${source_include_dir}/Frontend.h"  # Auto-generated.
  "${source_include_dir}/Compiler.h"
  "${source_include_dir}/Entity.h"
  "${source_include_dir}/Fragment.h"
  "${source_include_dir}/Index.h"
  "${source_include_dir}/IR.h"  # Auto-generated.
  "${source_include_dir}/Iterator.h"
  "${source_include_dir}/Re2.h"
  "${source_include_dir}/Reference.h"
  "${source_include_dir}/Types.h"
)

add_library("mx-api" OBJECT
  ${api_headers}

  ${frontend_sources}  # Auto-generated
  ${ast_sources}  # Auto-generated
  ${ir_sources}  # Auto-generated

  $<BUILD_INTERFACE:${source_include_dir}/Database.h>
  $<BUILD_INTERFACE:${MX_BOOTSTRAP_INCLUDE_VISITOR_INC_H}>
  
  "Attr.h"
  "Attr.cpp"
  "CachingEntityProvider.cpp"
  "CachingEntityProvider.h"
  "Compilation.h"
  "Compilation.cpp"
  "CXXBaseSpecifier.h"
  "Database.cpp"
  "Decl.h"
  "Decl.cpp"
  "Designator.h"
  "Entity.h"
  "EntityProvider.cpp"
  "EntityProvider.h"
  "File.cpp"
  "FileImpl.cpp"
  "File.h"
  "Fragment.cpp"
  "FragmentEntity.h"
  "FragmentImpl.cpp"
  "Fragment.h"
  "Index.cpp"
  "InvalidEntityProvider.cpp"
  "InvalidEntityProvider.h"
  "Macro.h"
  "Macro.cpp"
  "Pseudo.h"
  "Pseudo.cpp"
  "Re2.cpp"
  "Re2.h"
  "Re2Impl.cpp"
  "Re2Impl.h"
  "Reference.cpp"
  "Reference.h"
  "SQLiteEntityProvider.cpp"
  "SQLiteEntityProvider.h"
  "SQLiteStore.cpp"
  "SQLiteStore.h"
  "Stmt.h"
  "Stmt.cpp"
  "TemplateArgument.h"
  "TemplateParameterList.h"
  "ThreadLocal.cpp"
  "ThreadLocal.h"
  "TokenContext.cpp"
  "TokenContext.h"
  "Token.cpp"
  "Token.h"
  "TokenTree.cpp"
  "TokenTree.h"
  "Type.h"
  "Type.cpp"
  "Types.h"
  "Types.cpp"
  "Util.h"
  "Util.cpp"

  # Auto-generated.
  ${copied_headers}

  "${PROJECT_BINARY_DIR}/lib/Version.cpp"
)

add_dependencies("mx-api"
  "copy_headers"
)

target_link_libraries("mx-api"
  PUBLIC
    "gap::gap"
    "gap::gap-core"
    "gap::gap-settings"
    "std::coroutines"
  PRIVATE
    "mx-serialize"
    "mx-sqlite"
    "zstd::libzstd_static"
    "concurrentqueue"
    ${MLIR_LIBS}
    ${VAST_LIBS}
)

target_link_directories("mx-api"
  PRIVATE
    "$<BUILD_INTERFACE:${MLIR_LIB_DIR}>"
)

target_compile_definitions("mx-api"
  PUBLIC
    $<BUILD_INTERFACE:MX_BUILD>
)

if(NOT MX_ENABLE_PYTHON_BINDINGS)
  target_compile_definitions("mx-api"
    PUBLIC
      "MX_DISABLE_PYTHON_BINDINGS")
endif()

if(MX_ENABLE_RE2)
  target_link_libraries("mx-api"
    PRIVATE
      re2::re2)
else()
  target_compile_definitions("mx-api"
    PUBLIC
      "MX_DISABLE_RE2")
endif()

target_compile_options("mx-api"
  PRIVATE
    "-Wno-unknown-warning-option"
    "-Wno-pragmas"
)

target_include_directories("mx-api"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${MX_INSTALL_INCLUDE_DIR}>
  PRIVATE
    "$<BUILD_INTERFACE:${LLVM_INCLUDE_DIRS};${LLVM_INCLUDE_DIR};${MLIR_INCLUDE_DIRS}>"
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}"
)

set_target_properties("mx-api"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${api_headers}"
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

add_library("multiplier" SHARED
  "Shared.cpp"  # Dummy file.
)

target_include_directories("multiplier"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${MX_INSTALL_INCLUDE_DIR}>
)

target_link_libraries("multiplier"
  PUBLIC
    "gap::gap"
    "gap::gap-core"
    "gap::gap-settings"
    "std::coroutines"
    "$<BUILD_INTERFACE:mx-api>"
)

set_target_properties("multiplier"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
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

    # NOTE(pag): This is important! We need to emulate the shape of the
    #            install directories, so that install targets behave in the
    #            same way to local build targets w.r.t. shared library
    #            resolution. This places `libmultiplier.so` in the `lib/` sub-
    #            directory, where we also place copies of `libLTO.so` and
    #            `libRemarks.so`. This mirrors the organization inside of
    #            `<install-prefix>/lib`. This same-shapedness is necessary for
    #            how we fiddle with the RPATH, and do symlinking for Python
    #            extensions.
    LIBRARY_OUTPUT_DIRECTORY
      "${PROJECT_BINARY_DIR}/${MX_INSTALL_LIB_DIR}"
)

if(MX_ENABLE_INSTALL AND NOT MX_ENABLE_BOOTSTRAP)
  install(
    FILES
      ${ast_headers}
    DESTINATION
      "${MX_INSTALL_INCLUDE_DIR}/${lower_project_name}/AST"
  )  
  install(
    FILES
      ${frontend_headers}
    DESTINATION
      "${MX_INSTALL_INCLUDE_DIR}/${lower_project_name}/Frontend"
  )
  install(
    FILES
      ${api_headers}
    DESTINATION
      "${MX_INSTALL_INCLUDE_DIR}/${lower_project_name}"
  )
  install(
    DIRECTORY
      "${ir_source_include_dir}"
    DESTINATION
      "${MX_INSTALL_INCLUDE_DIR}/multiplier"
  )
  install(
    TARGETS
      "multiplier"
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
    PUBLIC_HEADER
      DESTINATION
        "${MX_INSTALL_INCLUDE_DIR}/${lower_project_name}"
  )
endif()
