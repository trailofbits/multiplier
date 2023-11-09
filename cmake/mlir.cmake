#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if (MLIR_LINK_MLIR_DYLIB)
  set(MLIR_LIBS MLIR)
else()
  get_property(MLIR_DIALECT_LIBS GLOBAL PROPERTY MLIR_DIALECT_LIBS)
  get_property(MLIR_CONVERSION_LIBS GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
  get_property(MLIR_EXTENSION_LIBS GLOBAL PROPERTY MLIR_EXTENSION_LIBS)
  get_property(MLIR_TRANSLATION_LIBS GLOBAL PROPERTY MLIR_TRANSLATION_LIBS)

  set(mlir_libs
    MLIRAnalysis
    MLIRDialect
    MLIRExecutionEngine
    MLIRIR
    MLIRParser
    MLIRPass
    MLIRSupport
    MLIRTransforms
    MLIRTransformUtils

    ${MLIR_DIALECT_LIBS}
    ${MLIR_CONVERSION_LIBS}
    ${MLIR_EXTENSION_LIBS}
    ${MLIR_TRANSLATION_LIBS}
  )

  foreach(mlir_lib IN LISTS mlir_libs)
    find_library(mlir_lib_path "${mlir_lib}" HINTS "${MX_INSTALL_LIB_DIR}")
    if (mlir_lib_path STREQUAL "mlir_lib_path-NOTFOUND")
      message(FATAL_ERROR "Cannot locate MLIR library ${mlir_lib}")
    endif()
    list(APPEND MLIR_LIBS "${mlir_lib_path}")
  endforeach()
endif()