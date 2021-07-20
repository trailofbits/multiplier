#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

cmake_minimum_required(VERSION 3.10.3)
project("TobWidgets")

include("cmake/target_settings.cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_library(TobWidgets
  src/textview.h
  src/textview.cpp

  src/textmodel.h
  src/textmodel.cpp

  src/glyphcache.h
  src/glyphcache.cpp
)

target_link_libraries(TobWidgets PRIVATE
  tobwidgets_cxx_settings
)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
target_link_libraries(TobWidgets PRIVATE
  Qt5::Core
  Qt5::Widgets
)
