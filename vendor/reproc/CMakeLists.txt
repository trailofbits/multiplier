#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(enabled_option_list
  REPROC_MULTITHREADED
  REPROC++
)

set(disabled_option_list
  REPROC_DEVELOP
  REPROC_EXAMPLES
  REPROC_TEST
  REPROC_WARNINGS
  REPROC_WARNINGS_AS_ERRORS
  REPROC_TIDY
  REPROC_INSTALL
  REPROC_INSTALL_PKGCONFIG
)

set(target_name_list
  reproc
  reproc++
)

foreach(enabled_option ${enabled_option_list})
  set("${enabled_option}" true CACHE BOOL "Forced reproc setting" FORCE)
endforeach()

foreach(disabled_option ${disabled_option_list})
  set("${disabled_option}" false CACHE BOOL "Forced reproc setting" FORCE)
endforeach()

add_subdirectory(src EXCLUDE_FROM_ALL)
