#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library(drgui_common_settings INTERFACE)
target_compile_options(drgui_common_settings INTERFACE
  -Wall
  -pedantic
  -Wconversion
  -Wunused
  -Wshadow
  -fvisibility=hidden
  -Werror
  -Wno-deprecated-declarations
)

set_target_properties(drgui_common_settings PROPERTIES
  INTERFACE_POSITION_INDEPENDENT_CODE ON
)

add_library(drgui_cxx_settings INTERFACE)
target_compile_features(drgui_cxx_settings INTERFACE
  cxx_std_17
)

target_link_libraries(drgui_cxx_settings INTERFACE
  drgui_common_settings
)
