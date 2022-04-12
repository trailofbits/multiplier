#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(disabled_option_list
  RE2_BUILD_TESTING
)

foreach(disabled_option ${disabled_option_list})
  set("${disabled_option}" OFF CACHE BOOL "Forced reproc setting" FORCE)
endforeach()

add_subdirectory(src EXCLUDE_FROM_ALL)