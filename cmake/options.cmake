#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type")
set(CMAKE_EXPORT_COMPILE_COMMANDS true CACHE BOOL "Generate the compile_commands.json file (forced)" FORCE)

option(MU_USE_SYSTEM_DEPS "Use system dependencies instead of trying to find vcpkg")
option(MU_ENABLE_INSTALL "Set to true to enable the install target" true)
