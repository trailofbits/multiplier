#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(PLATFORM_LINUX OR PLATFORM_MACOS)
  find_program(ccache_executable "ccache")
  if(NOT ccache_executable STREQUAL "ccache_executable-NOFOUND")
    message(STATUS "multiplier: Enabling ccache support (${ccache_executable})")

    set(CMAKE_CXX_COMPILER_LAUNCHER "${ccache_executable}" CACHE FILEPATH "ccache")
    set(CMAKE_C_COMPILER_LAUNCHER "${ccache_executable}" CACHE FILEPATH "ccache")

  else()
    message(STATUS "multiplier: No ccache executable found")
  endif()
endif()
