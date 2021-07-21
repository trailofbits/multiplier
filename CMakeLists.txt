#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

cmake_minimum_required(VERSION 3.19)

include("cmake/options.cmake")
if(NOT MU_USE_SYSTEM_DEPS)
  include("cmake/vcpkg_helper.cmake")
endif()

project("multiplier")

include("cmake/system.cmake")
include("cmake/target_settings.cmake")

if(MU_ENABLE_INSTALL)
  include("cmake/packaging.cmake")
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

generateTargetSettings()

add_subdirectory("libraries")
add_subdirectory("multiplier")
