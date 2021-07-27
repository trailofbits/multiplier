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

  src/sourcecodemodel.h
  src/sourcecodemodel.cpp

  src/astbuilder.h
  src/astbuilder.cpp

  src/astmodel.h
  src/astmodel.cpp

  src/compilecommandsindex.h
  src/compilecommandsindex.cpp

  src/document.h
  src/document.cpp

  src/parsedfilesindex.h
  src/parsedfilesindex.cpp
)

target_link_libraries(multiplier PRIVATE
  mu_cxx_settings
  Qt${MU_QT_VERSION}::Core
  Qt${MU_QT_VERSION}::Widgets
)

find_package(pasta REQUIRED)
target_link_libraries(multiplier PRIVATE
  pasta::pasta
)

find_package(TobWidgets REQUIRED)
target_link_libraries(multiplier PRIVATE
  TobWidgets
)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_sources(multiplier PRIVATE
    src/macos_utils.h
    src/macos_utils.mm
  )

  target_link_libraries(multiplier PRIVATE
    "-framework AppKit"
  )
endif()

if(MU_ENABLE_INSTALL)
  install(TARGETS multiplier DESTINATION bin)
endif()
