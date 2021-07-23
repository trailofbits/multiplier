#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(USE_SYSTEM_DEPENDENCIES "${MU_USE_SYSTEM_DEPS}" CACHE BOOL "Disable vcpkg support (forced)")
add_subdirectory("src")

add_library(thirdparty_pasta INTERFACE)
target_link_libraries(thirdparty_pasta INTERFACE
  pasta_compiler
  pasta_util
)

# TODO: This should be exported by the pasta targets
target_include_directories(thirdparty_pasta SYSTEM INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/src/include"
)

target_link_libraries(thirdparty_pasta INTERFACE
  pasta_thirdparty_llvm
)

add_library(pasta::pasta ALIAS thirdparty_pasta)
