#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(exe_name "mx-index")

add_executable("${exe_name}"
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
    "mx-util"
    pasta::pasta
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