#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(exe_name "mx-index")

if(MX_ENABLE_VAST)
  set(mlir_codegen_sources
    "Codegen.cpp"
    "Codegen.h"
    "CodegenMetaGenerator.h"
  )
endif()

add_executable("${exe_name}"
  "Action.cpp"
  "Action.h"
  "BuildPendingFragment.cpp"
  ${mlir_codegen_sources}
  "Context.cpp"
  "Context.h"
  "Endian.h"
  "Entity.h"
  "EntityMapper.cpp"
  "EntityMapper.h"
  "Executor.cpp"
  "Executor.h"
  "Hash.cpp"
  "Hash.h"
  "IDStore.h"
  "IDStore.cpp"
  "Importer.cpp"
  "Importer.h"
  "IndexCompileJob.cpp"
  "IndexCompileJob.h"
  "LabelEntitiesInFragment.cpp"
  "LabelParentEntitiesInFragment.cpp"
  "LinkEntitiesAcrossFragments.cpp"
  "LinkEntityNamesToFragment.cpp"
  "LinkExternalReferencesInFragment.cpp"
  "Log.h"
  "Main.cpp"
  "NameMangler.cpp"
  "NameMangler.h"
  "Parser.cpp"
  "Parser.h"
  "PendingFragment.h"
  "Persist.cpp"
  "PersistTokenContexts.cpp"
  "PersistTypes.cpp"
  "ProgressBar.cpp"
  "ProgressBar.h"
  "Provenance.cpp"
  "Provenance.h"
  "Serialize.h"
  "SerializePendingFragment.cpp"
  "Signal.cpp"
  "Signal.h"
  "Subprocess.cpp"
  "Subprocess.h"
  "TypeMapper.cpp"
  "TypeMapper.h"
  "TokenTree.cpp"
  "TokenTree.h"
  "Util.cpp"
  "Util.h"
  "Visitor.cpp"
  "Visitor.h"
  "${MX_BOOTSTRAP_INDEX_PASTA_CPP}"
  "${MX_BOOTSTRAP_INDEX_PASTA_H}"
  "${MX_BOOTSTRAP_INDEX_SERIALIZE_H}"
  "${MX_BOOTSTRAP_INDEX_SERIALIZE_CPP}"
  "${MX_BOOTSTRAP_INCLUDE_VISITOR_INC_H}"
)

target_link_libraries("${exe_name}"
  PRIVATE
    ${MX_BEGIN_FORCE_LOAD_GROUP}
    "mx-api"
    clangIndex
    glog::glog
    gflags::gflags
    concurrentqueue
    reproc++
    xxHash::xxhash
    RocksDB::rocksdb
    ${MX_BEGIN_FORCE_LOAD_LIB} pasta::pasta ${MX_END_FORCE_LOAD_LIB}
    ${MX_END_FORCE_LOAD_GROUP}
)

# When we're bootstrapping, we might be using a different version of Clang and
# LLVM. But if we're still using cxx-common for the 'old' LLVM, then the include
# paths might make the indexer find the old LVLM, rather than the new one.
target_include_directories("${exe_name}"
  PRIVATE
    "$<BUILD_INTERFACE:${LLVM_INCLUDE_DIRS};${LLVM_INCLUDE_DIR};${CLANG_INCLUDE_DIRS}>"
)

target_compile_options("${exe_name}"
  PRIVATE
    "-Wno-unknown-warning-option"
    "-Wno-pragmas"
)

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
