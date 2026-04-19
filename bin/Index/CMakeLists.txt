#
# Copyright (c) 2021-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(exe_name "mx-index")

add_executable("${exe_name}"
  "Action.cpp"
  "Action.h"
  "ArgumentFilter.cpp"
  "ArgumentFilter.h"
  "BuildPendingFragment.cpp"
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
  "IRGen.cpp"
  "IRGen.h"
  "SerializeIR.cpp"
  "SerializeIR.h"
  "LabelEntitiesInFragment.h"
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

target_link_libraries("${exe_name}"
  PRIVATE
    "mx-api"
    clangIndex
    glog::glog
    gflags::gflags
    concurrentqueue
    intervaltree
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

target_compile_definitions("${exe_name}"
  PRIVATE
    "MX_SHARE_DIR=\"${MX_INSTALL_SHARE_DIR}\""
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

find_and_link_llvm_dependencies("${exe_name}")

# Copy the default argument filter config into the build tree so that mx-index
# can find it when run from the build directory (the binary sits in
# <build>/<bin_dir>/, and it looks for ../<share_dir>/multiplier/).
set(MX_ARG_FILTER_SRC "${PROJECT_SOURCE_DIR}/share/multiplier/unsupported_args.cfg")
set(MX_ARG_FILTER_DST "${PROJECT_BINARY_DIR}/${MX_INSTALL_SHARE_DIR}/multiplier/unsupported_args.cfg")
add_custom_command(
  OUTPUT "${MX_ARG_FILTER_DST}"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
          "${MX_ARG_FILTER_SRC}" "${MX_ARG_FILTER_DST}"
  DEPENDS "${MX_ARG_FILTER_SRC}"
  COMMENT "Copying unsupported_args.cfg to build tree"
)
add_custom_target("${exe_name}-arg-filter" ALL DEPENDS "${MX_ARG_FILTER_DST}")
add_dependencies("${exe_name}" "${exe_name}-arg-filter")

if(MX_ENABLE_INSTALL AND NOT MX_ENABLE_BOOTSTRAP)
  install(
    TARGETS
      "${exe_name}"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
  )

  install(
    FILES
      "${MX_ARG_FILTER_SRC}"
    DESTINATION
      "${MX_INSTALL_SHARE_DIR}/multiplier"
  )
endif()
