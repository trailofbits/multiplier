#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable(multiplier
  src/main.cpp

  src/mainwindow.h
  src/mainwindow.cpp

  src/textmodel.h
  src/textmodel.cpp

  src/compilecommandsindex.h
  src/compilecommandsindex.cpp

  src/document.h
  src/document.cpp
)

target_link_libraries(multiplier PRIVATE
  mu_cxx_settings
  Qt5::Core
  Qt5::Widgets
)

find_package(pasta REQUIRED)
target_link_libraries(multiplier PRIVATE
  pasta::pasta
)

find_package(TobWidgets REQUIRED)
target_link_libraries(multiplier PRIVATE
  TobWidgets
)

if(MU_ENABLE_INSTALL)
  install(TARGETS multiplier DESTINATION bin)
endif()
