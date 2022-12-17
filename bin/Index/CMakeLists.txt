#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(exe_name "mx-index")

add_executable("${exe_name}"
  "Action.cpp"
  "Action.h"
  "BuildPendingFragment.cpp"
  "Compress.cpp"
  "Compress.h"
  "Codegen.cpp"
  "Codegen.h"
  "Context.cpp"
  "Context.h"
  "EntityMapper.cpp"
  "EntityMapper.h"
  "Executor.cpp"
  "Executor.h"
  "FindUsesInFragment.cpp"
  "Hash.cpp"
  "Hash.h"
  "Importer.cpp"
  "Importer.h"
  "IndexCompileJob.cpp"
  "IndexCompileJob.h"
  "LabelEntitiesInFragment.cpp"
  "LabelParentEntitiesInFragment.cpp"
  "LinkDeclarationsAcrossFragments.cpp"
  "LinkReferencesInFragment.cpp"
  "Macro.h"
  "Main.cpp"
  "NameMangler.cpp"
  "NameMangler.h"
  "Parser.cpp"
  "Parser.h"
  "PendingFragment.h"
  "Persist.cpp"
  "Persist.h"
  "PersistDeclarationInFragments.cpp"
  "ProgressBar.cpp"
  "ProgressBar.h"
  "Pseudo.h"
  "SerializePendingFragment.cpp"
  "Signal.cpp"
  "Signal.h"
  "Subprocess.cpp"
  "Subprocess.h"
  "TokenTree.cpp"
  "TokenTree.h"
  "Util.cpp"
  "Util.h"
  "Visitor.cpp"
  "Visitor.h"
  "WorkerPool.cpp"
  "WorkerPool.h"
  "${MX_BOOTSTRAP_INDEX_PASTA_CPP}"
  "${MX_BOOTSTRAP_INDEX_PASTA_H}"
  "${MX_BOOTSTRAP_INDEX_SERIALIZE_H}"
  "${MX_BOOTSTRAP_INDEX_SERIALIZE_CPP}"
  "${MX_BOOTSTRAP_INCLUDE_VISITOR_INC_H}"
)

target_link_libraries("${exe_name}"
  PRIVATE
    ${MX_BEGIN_FORCE_LOAD_GROUP}
    mx-api
    "glog::glog"
    gflags::gflags
    concurrentqueue
    reproc++
    ${MX_BEGIN_FORCE_LOAD_LIB} pasta::pasta ${MX_END_FORCE_LOAD_LIB}
    ${MX_END_FORCE_LOAD_GROUP}
)

if(MX_ENABLE_VAST)
  target_compile_definitions("${exe_name}"
    PRIVATE
      "MX_ENABLE_SOURCEIR"
  )
  target_link_libraries("${exe_name}"
    PRIVATE
      ${MX_BEGIN_FORCE_LOAD_GROUP}
      vast::vast
      MLIRDLTI
      MLIRStandard
      MLIRLLVMIR
      ${MX_END_FORCE_LOAD_GROUP}
  )
endif()

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

  find_and_install_llvm_dependencies()
endif()
