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
  "Codegen.cpp"
  "Codegen.h"
  "CodegenMetaGenerator.h"
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
  "IdStore.h"
  "IdStore.cpp"
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
  "References.cpp"
  "References.h"
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

find_package(concurrentqueue MODULE REQUIRED)

target_link_libraries("${exe_name}"
  PRIVATE
    "mx-api"
    clangIndex
    glog::glog
    gflags::gflags
    concurrentqueue
    reproc++
    xxHash::xxhash
    RocksDB::rocksdb
    pasta::pasta
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

set_target_properties("${exe_name}"
  PROPERTIES
    LINKER_LANGUAGE
      CXX

    # NOTE(pag): This is important! We need to emulate the shape of the
    #            install directories, so that install targets behave in the
    #            same way to local build targets w.r.t. shared library
    #            resolution. This places `libmultiplier.so` in the `lib/` sub-
    #            directory, where we also place copies of `libLTO.so` and
    #            `libRemarks.so`. This mirrors the organization inside of
    #            `<install-prefix>/lib`. This same-shapedness is necessary for
    #            how we fiddle with the RPATH, and do symlinking for Python
    #            extensions.
    RUNTIME_OUTPUT_DIRECTORY
      "${PROJECT_BINARY_DIR}/${MX_INSTALL_BIN_DIR}"
)

#find_and_link_llvm_dependencies("${exe_name}")

if(MX_ENABLE_INSTALL AND NOT MX_ENABLE_BOOTSTRAP)
  install(
    TARGETS
      "${exe_name}"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${MX_INSTALL_TOOLS_DIR}"
  )
endif()
