#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(additional_module_paths_list
  "${CMAKE_CURRENT_SOURCE_DIR}/modules"
)

list(PREPEND CMAKE_MODULE_PATH
  ${additional_module_paths_list}
)

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" PARENT_SCOPE)

find_package(Git REQUIRED)

if(MX_ENABLE_INSTALL)
  set(MX_VENDOR_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}")
else()
  set(MX_VENDOR_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/install")
  execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${MX_VENDOR_INSTALL_DIR}")
endif()

add_subdirectory(capnproto)
add_subdirectory(gflags)
add_subdirectory(glog)  # Depends on gflags
add_subdirectory(concurrentqueue)
add_subdirectory(reproc)
add_subdirectory(sqlite)
add_subdirectory(gap)
add_subdirectory(zstd)
add_subdirectory(llvm-project)  # Depends on zstd
add_subdirectory(pasta)  # Depends on llvm-project
