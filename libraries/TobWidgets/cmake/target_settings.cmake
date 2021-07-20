#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library(tobwidgets_common_settings INTERFACE)
target_compile_options(tobwidgets_common_settings INTERFACE
  -Wall
  -pedantic
  -Wconversion
  -Wunused
  -Wshadow
  -fvisibility=hidden
  -Werror
  -Wno-deprecated-declarations
)

set_target_properties(tobwidgets_common_settings PROPERTIES
  INTERFACE_POSITION_INDEPENDENT_CODE ON
)

add_library(tobwidgets_cxx_settings INTERFACE)
target_compile_features(tobwidgets_cxx_settings INTERFACE
  cxx_std_17
)

target_link_libraries(tobwidgets_cxx_settings INTERFACE
  tobwidgets_common_settings
)
