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

file(GLOB entity_headers CONFIGURE_DEPENDS "${MX_BOOTSTRAP_INCLUDE_ENTITIES_DIR}/*.h")
file(GLOB entity_sources CONFIGURE_DEPENDS "${MX_BOOTSTRAP_LIB_ENTITIES_DIR}/*.cpp")

add_library("mx-entities" INTERFACE)
set_target_properties("mx-entities"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${entity_headers}"
    VISIBILITY_INLINES_HIDDEN
      YES
    CXX_VISIBILITY_PRESET
      hidden
    POSITION_INDEPENDENT_CODE
      YES
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
  "${source_include_dir}/AST.h"
  $<BUILD_INTERFACE:${source_include_dir}/Database.h>
  "${source_include_dir}/Entity.h"
  "${source_include_dir}/File.h"
  "${source_include_dir}/Fragment.h"
  "${source_include_dir}/Index.h"
  "${source_include_dir}/Iterator.h"
  "${source_include_dir}/Query.h"
  "${source_include_dir}/Re2.h"
  "${source_include_dir}/Reference.h"
  "${source_include_dir}/Token.h"
  "${source_include_dir}/Types.h"
  "${source_include_dir}/SourceIR.h"
  "${source_include_dir}/Weggli.h"
  "${MX_BOOTSTRAP_INCLUDE_VISITOR_INC_H}"
)

add_library("mx-api" STATIC
  ${api_headers}
  ${entity_headers}  # Auto-generated
  ${entity_sources}  # Auto-generated
  
  "API.cpp"
  "API.h"
  "Attr.h"
  "Attr.cpp"
  "CachingEntityProvider.cpp"
  "CachingEntityProvider.h"
  "CXXBaseSpecifier.h"
  "Database.cpp"
  "Decl.h"
  "Decl.cpp"
  "Designator.h"
  "Entity.h"
  "File.cpp"
  "FileImpl.cpp"
  "File.h"
  "Fragment.cpp"
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
  "SourceIR.cpp"
  "SourceIR.h"
  "TemplateArgument.h"
  "TemplateParameterList.h"
  "ThreadLocal.cpp"
  "ThreadLocal.h"
  "TokenContext.cpp"
  "Token.cpp"
  "Token.h"
  "Type.h"
  "Type.cpp"
  "Types.h"
  "Types.cpp"
  "Util.h"
  "Weggli.cpp"
  "WeggliImpl.cpp"
  "WeggliImpl.h"

  # Auto-generated.
  ${copied_headers}
  ${MX_AST_SOURCES}
  ${MX_RPC_SOURCES}
)

add_dependencies("mx-api"
  "copy_headers"
)

target_link_libraries("mx-api"
  PUBLIC
    "CapnProto::capnp-rpc"
    "mx-sqlite"
    "gap::gap"
    "gap::gap-core"
    "std::coroutines"
    "gap::gap-settings"
  PRIVATE
    $<BUILD_INTERFACE:concurrentqueue>
    $<IF:$<TARGET_EXISTS:zstd::libzstd_static>,zstd::libzstd_static,zstd::libzstd_shared>
)

if(MX_ENABLE_RE2)
  target_link_libraries("mx-api"
    PRIVATE
      "re2::re2"
  )
else()
  target_compile_definitions("mx-api"
    PUBLIC
      "MX_DISABLE_RE2")
endif()


if(MX_ENABLE_WEGGLI)
  target_link_libraries("mx-api"
    PRIVATE
      "weggli_native::static"
  )
else()
  target_compile_definitions("mx-api"
    PUBLIC
      "MX_DISABLE_WEGGLI")
endif()

if(MX_ENABLE_VAST)
  target_compile_definitions("mx-api"
    PRIVATE
      "MX_ENABLE_SOURCEIR"
  )
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
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
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

add_library("mx-mlir" INTERFACE)
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

if(MX_ENABLE_VAST)
target_link_libraries("mx-mlir"
  INTERFACE
    vast::vast
    vast::MLIRCore
    vast::MLIRMeta
    MLIRDialect
    MLIRMLProgramDialect
    MLIROpenMPDialect
    MLIRTosaDialect

    MLIRBufferizationTransformOps
    MLIRSparseTensorTransforms
    MLIROpenACCDialect
    MLIRLLVMIRTransforms
    MLIRROCDLDialect
    MLIRAsyncDialect
    MLIRSCFTransformOps
    MLIREmitCDialect
    MLIRNVGPUDialect
    MLIRShapeDialect
    MLIRAMDGPUDialect
    MLIRShapeOpsTransforms
    MLIRLinalgTransformOps
    MLIRSPIRVDialect
    MLIRTensorInferTypeOpInterfaceImpl
)
else(MX_ENABLE_VAST)
target_link_libraries("mx-mlir" INTERFACE)
endif(MX_ENABLE_VAST)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "mx-entities"
    EXPORT
      "${PROJECT_NAME}Targets"
    PUBLIC_HEADER
      DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/${lower_project_name}/Entities"
  )
  install(
    TARGETS
      "mx-api"
      "mx-mlir"
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
        "${CMAKE_INSTALL_INCLUDEDIR}/${lower_project_name}"
  )
endif(MX_ENABLE_INSTALL)

add_subdirectory("Analysis")
