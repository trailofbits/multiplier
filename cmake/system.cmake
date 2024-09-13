#
# Copyright (c) 2021-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(PLATFORM_LINUX true)

elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(PLATFORM_MACOS true)
  IF(NOT DEFINED ENV{SDKROOT})
    execute_process(COMMAND xcrun --sdk macosx --show-sdk-path
      OUTPUT_VARIABLE SDKROOT
      ERROR_QUIET
      OUTPUT_STRIP_TRAILING_WHITESPACE)
  ENDIF()

else()
  message(FATAL_ERROR "Unsupported platform")
endif ()

# TODO(pag): Handle this better. We need to make sure all symbols from
#            tools are linked in, otherwise global constructors in tools
#            won't be called, and then they won't get created in `ToolMain.cpp`.
if(PLATFORM_MACOS)
  set("MX_BEGIN_FORCE_LOAD_GROUP" "-Wl,-all_load")
  set("MX_END_FORCE_LOAD_GROUP" "-Wl,-noall_load")

  set("MX_BEGIN_FORCE_LOAD_LIB" "-Wl,-force_load")
  set("MX_END_FORCE_LOAD_LIB" "")

elseif(PLATFORM_LINUX)
  set("MX_BEGIN_FORCE_LOAD_GROUP" "-Wl,--whole-archive")
  set("MX_END_FORCE_LOAD_GROUP" "-Wl,--no-whole-archive")

  set("MX_BEGIN_LIBRARY_GROUP" "-Wl,--start-group")
  set("MX_END_LIBRARY_GROUP" "-Wl,--end-group")
endif()
