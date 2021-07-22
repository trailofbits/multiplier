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
  include/tob/itextmodel.h

  include/tob/itextview.h
  src/itextview.cpp

  src/textview.h
  src/textview.cpp

  src/glyphcache.h
  src/glyphcache.cpp
)

target_include_directories(TobWidgets PRIVATE include)
target_include_directories(TobWidgets SYSTEM INTERFACE include)

target_link_libraries(TobWidgets PRIVATE
  tobwidgets_cxx_settings
)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
target_link_libraries(TobWidgets PRIVATE
  Qt5::Core
  Qt5::Widgets
)
