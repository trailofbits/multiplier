#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library("mx-example-index" STATIC
  "Index.h"
  "Index.cpp"
)

target_link_libraries("mx-example-index"
  PUBLIC
    "mx-api"
    "mx-analysis"
    glog::glog
    gflags::gflags
)

function(define_example exe_name source_file)
  add_executable("${exe_name}"
    "${source_file}"
  )

  target_link_libraries("${exe_name}"
    PRIVATE
      "mx-example-index"
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
  endif()
endfunction(define_example)

define_example("mx-list-files" "ListFiles.cpp")
define_example("mx-dump-files" "DumpFiles.cpp")
define_example("mx-print-file" "PrintFile.cpp")
define_example("mx-highlight-entity" "HighlightEntity.cpp")
define_example("mx-print-call-hierarchy" "PrintCallHierarchy.cpp")
define_example("mx-print-call-graph" "PrintCallGraph.cpp")
define_example("mx-print-include-graph" "PrintIncludeGraph.cpp")
define_example("mx-print-token-graph" "PrintTokenGraph.cpp")
define_example("mx-print-token-tree" "PrintTokenTree.cpp")
define_example("mx-print-reference-graph" "PrintReferenceGraph.cpp")
define_example("mx-list-fragments" "ListFragments.cpp")
define_example("mx-print-fragment" "PrintFragment.cpp")
define_example("mx-list-functions" "ListFunctions.cpp")
define_example("mx-list-variables" "ListVariables.cpp")
define_example("mx-list-macros" "ListMacros.cpp")
define_example("mx-list-redeclarations" "ListRedeclarations.cpp")
define_example("mx-list-structures" "ListStructures.cpp")
# define_example("mx-list-uses" "ListUses.cpp")  # TODO(pag): Make this list-references.
define_example("mx-dump-json" "DumpJSON.cpp")

define_example("mx-weggli-query" "WeggliQuery.cpp")
define_example("mx-regex-query" "RegexQuery.cpp")
define_example("mx-find-calls-in-macro-expansions" "FindCallsInMacroExpansions.cpp")
define_example("mx-find-sketchy-casts" "FindSketchyCasts.cpp")
define_example("mx-find-divergent-candidates" "FindDivergentCandidates.cpp")
define_example("mx-find-other-uses-of-max" "FindOtherUsesOfMax.cpp")
define_example("mx-find-sketchy-strchr" "FindSketchyStrchr.cpp")
define_example("mx-find-symbol" "FindSymbol.cpp")
define_example("mx-taint-entity" "TaintEntity.cpp")
define_example("mx-harness" "Harness.cpp")
define_example("mx-find-sequoia" "FindSequoia.cpp")
define_example("mx-print-type-token-graph" "PrintTypeTokenGraph.cpp")

target_compile_definitions("mx-dump-json"
  PRIVATE
    "-DLLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING"
)

target_link_libraries("mx-dump-json"
  PRIVATE
    LLVMCore LLVMSupport
)

define_example("mx-count-sourceir" "CountSourceIR.cpp")
define_example("mx-print-sourceir" "PrintSourceIR.cpp")
#  define_example("mx-dump-sourceir" "DumpSourceIR.cpp")
#  define_example("mx-find-uses-of-entity-sourceir" "FindUsesOfEntitySourceIR.cpp")
