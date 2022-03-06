#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)
set(lib_name "index")
set(exe_name "mx-${lib_name}")

add_library("${lib_name}"
  STATIC
    "Context.cpp"
    "Context.h"
    "IndexCompileCommand.cpp"
    "IndexCompileCommand.h"
    "IndexCompileJob.cpp"
    "IndexCompileJob.h"
    "PrintTokenGraph.cpp"
    "PrintTokenGraph.h"
    "TokenizeFile.cpp"
    "TokenizeFile.h"
    "TokenTree.cpp"
    "TokenTree.h"
    "Tool.cpp"
)

target_link_libraries("${lib_name}"
  PRIVATE
    "tool"
)

add_library("${PROJECT_NAME}::${lib_name}" ALIAS "${lib_name}")
set_target_properties("${lib_name}" PROPERTIES LINKER_LANGUAGE CXX)

add_executable("${exe_name}"
  $<TARGET_OBJECTS:tool_main>
)

target_link_libraries("${exe_name}"
  PRIVATE
    ${MX_BEGIN_FORCE_LOAD_GROUP}
    ${MX_BEGIN_FORCE_LOAD_TOOL} "${lib_name}" ${MX_END_FORCE_LOAD_TOOL}
    ${MX_END_FORCE_LOAD_GROUP}
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