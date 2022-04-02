#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(PLATFORM_LINUX true)

elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(PLATFORM_MACOS true)
  IF(NOT DEFINED ENV{SDKROOT})
    execute_process(COMMAND xcrun --sdk macosx --show-sdk-path
      OUTPUT_VARIABLE SDKROOT
      ERROR_QUIET
      OUTPUT_STRIP_TRAILING_WHITESPACE)
  ENDIF()

else()
  message(FATAL_ERROR "Unsupported platform")
endif()
