#
# Copyright (c) 2021-present, Trail of Bits, Inc.
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

add_subdirectory(concurrentqueue)
add_subdirectory(reproc)