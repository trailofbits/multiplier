#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#


function(define_example exe_name source_file)
  add_executable("${exe_name}"
      "${source_file}"
  )
  
  target_link_libraries("${exe_name}"
    PRIVATE
      "mx-api"
      glog::glog
      gflags::gflags
  )
  
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
endfunction(define_example)

define_example("mx-list-files" "ListFiles.cpp")
define_example("mx-print-file" "PrintFile.cpp")
define_example("mx-list-fragments" "ListFragments.cpp")
define_example("mx-print-fragment" "PrintFragment.cpp")
define_example("mx-print-function-names" "PrintFunctionNames.cpp")
define_example("mx-print-uses" "PrintUses.cpp")
define_example("mx-dump-json" "DumpJSON.cpp")
define_example("mx-print-token-contexts" "PrintTokenContexts.cpp")

target_link_libraries("mx-dump-json"
  PRIVATE
    LLVMCore LLVMSupport
)