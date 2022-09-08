#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#


set(exe_name "mx-import")

add_executable("${exe_name}"
  "Log.h"
  
  "Parser.h"
  "Parser.cpp"
  
  "Importer.h"
  "Importer.cpp"
  
  "Main.cpp"
  
  "Util.h"
  "Util.cpp"
)

set_target_properties("${exe_name}"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
)

target_link_libraries("${exe_name}"
  PRIVATE
    mx-util
    pasta::pasta
)

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
