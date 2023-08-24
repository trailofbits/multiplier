#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

set(ir_source_include_dir "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/IR")

file(GLOB_RECURSE mlir_dialect_headers CONFIGURE_DEPENDS RELATIVE_PATH "${MX_BOOTSTRAP_INCLUDE_MLIR_DIR}" "*.h")
file(GLOB_RECURSE vast_dialect_headers CONFIGURE_DEPENDS RELATIVE_PATH "${MX_BOOTSTRAP_INCLUDE_VAST_DIR}" "*.h")

file(GLOB_RECURSE mlir_dialect_sources CONFIGURE_DEPENDS RELATIVE_PATH "${MX_BOOTSTRAP_LIB_MLIR_DIR}" "*.cpp")
file(GLOB_RECURSE vast_dialect_sources CONFIGURE_DEPENDS RELATIVE_PATH "${MX_BOOTSTRAP_LIB_VAST_DIR}" "*.cpp")

add_library("mx-mlir" STATIC
  ${mlir_dialect_headers}
  ${vast_dialect_headers}
  ${mlir_dialect_sources}
  ${vast_dialect_sources}
  
  "${ir_source_include_dir}/Attribute.h"
  "${ir_source_include_dir}/AttributeKind.h"
  "${ir_source_include_dir}/Block.h"
  "${ir_source_include_dir}/Operation.h"
  "${ir_source_include_dir}/OperationKind.h"
  "${ir_source_include_dir}/Region.h"
  "${ir_source_include_dir}/Type.h"
  "${ir_source_include_dir}/TypeKind.h"
  "${ir_source_include_dir}/Value.h"
  
  "Attribute.h"
  "AttributeKind.cpp"
  "Block.cpp"
  "Operation.cpp"
  "OperationKind.cpp"
  "Operation.h"
  "Region.cpp"
  "SourceIR.cpp"
  "SourceIR.h"
  "Type.h"
  "TypeKind.cpp"
  "Value.cpp"
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

target_link_libraries("mx-mlir"
  PUBLIC

    "gap::gap"
    "gap::gap-core"
    "std::coroutines"
    "gap::gap-settings"
    
    VAST::VASTCodeGen
    VAST::VASTCore
    VAST::VASTMeta
    VAST::VASTLowLevel
    VAST::VASTHighLevel
    VAST::VASTUnsupported

    MLIRDialect
    MLIRAMDGPUDialect
    MLIRAsyncDialect
    MLIREmitCDialect
    MLIRIndexDialect
    MLIRMLProgramDialect
    MLIRNVGPUDialect
    MLIROpenACCDialect
    MLIROpenMPDialect
    MLIRROCDLDialect
    MLIRShapeDialect
    MLIRSPIRVDialect
    MLIRTosaDialect

    MLIRLLVMIRTransforms
    MLIRShapeOpsTransforms
    MLIRSparseTensorTransforms
    MLIRAffineTransformOps
    MLIRBufferizationTransformOps
    MLIRGPUTransformOps
    MLIRLinalgTransformOps
    MLIRMemRefTransformOps
    MLIRSCFTransformOps
    MLIRVectorTransformOps
    MLIRTensorInferTypeOpInterfaceImpl
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
