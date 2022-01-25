#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#


string(TOLOWER "${PROJECT_NAME}" lower_project_name)
set(multitool_name "mx-multitool")

add_executable("${multitool_name}"
  $<TARGET_OBJECTS:tool_main>)

set_target_properties("${multitool_name}" PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries("${multitool_name}" PRIVATE
  ${MX_BEGIN_FORCE_LOAD_GROUP}
  "tool"
  ${MX_BEGIN_FORCE_LOAD_TOOL} "${PROJECT_NAME}::index" ${MX_END_FORCE_LOAD_TOOL}
  ${MX_END_FORCE_LOAD_GROUP}
  
  glog::glog
  gflags::gflags)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "${multitool_name}"
    EXPORT
      "${PROJECT_NAME}Targets"
  )
endif()