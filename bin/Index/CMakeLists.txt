#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(exe_name "mx-index")

add_executable("${exe_name}"
  "Compress.cpp"
  "Compress.h"
  "Codegen.cpp"
  "Codegen.h"
  "Context.cpp"
  "Context.h"
  "Hash.cpp"
  "Hash.h"
  "IndexCompileJob.cpp"
  "IndexCompileJob.h"
  "Label.cpp"
  "Label.h"
  "Main.cpp"
  "Persist.cpp"
  "Persist.h"
  "PrintTokenGraph.cpp"
  "PrintTokenGraph.h"
  "SearchAction.cpp"
  "SearchAction.h"
  "SearchRE2.cpp"
  "SearchRE2.h"
  "Serialize.cpp"
  "Serialize.h"
  "Serializer.cpp"
  "Serializer.h"
  "Server.cpp"
  "Server.h"
  "TokenTree.cpp"
  "TokenTree.h"
  "Util.cpp"
  "Util.h"
  "Visitor.cpp"
  "Visitor.h" 
)

target_link_libraries("${exe_name}"
  PRIVATE
    ${MX_BEGIN_FORCE_LOAD_GROUP}
    "mx-util"
    ${MX_BEGIN_FORCE_LOAD_LIB} pasta::pasta ${MX_END_FORCE_LOAD_LIB}
    ${MX_END_FORCE_LOAD_GROUP}
    pasta::pasta
    vast::vast
    MLIRDLTI
    MLIRStandard
    MLIRLLVMIR
)

if(MX_ENABLE_VAST)
  target_link_libraries("${exe_name}"
    PRIVATE
      ${MX_BEGIN_FORCE_LOAD_GROUP}
      vast::vast
      MLIRDLTI
      MLIRStandard
      MLIRLLVMIR
      ${MX_END_FORCE_LOAD_GROUP}
  )
else()
  target_compile_definitions("${exe_name}"
    PRIVATE
      "MX_DISABLE_SOURCEIR"
  )
endif()

add_executable("${PROJECT_NAME}::${exe_name}" ALIAS "${exe_name}")
set_target_properties("${exe_name}" PROPERTIES LINKER_LANGUAGE CXX)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "${exe_name}"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
  )
endif()
