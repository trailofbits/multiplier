#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(MX_QT "Qt${MX_QT_VERSION}")
set(MX_GUI_DIR "${CMAKE_CURRENT_LIST_DIR}")
find_package(${MX_QT} COMPONENTS Core Widgets REQUIRED)

set(exe_name "multiplier")
add_executable("${exe_name}"

  FileBrowserView.h
  FileBrowserView.cpp

  FileView.h
  FileView.cpp
  
  MainWindow.h
  MainWindow.cpp

  OpenConnectionDialog.h
  OpenConnectionDialog.cpp

  Main.cpp
)

target_link_libraries("${exe_name}" PRIVATE
  "mx-api"
  ${MX_QT}::Core
  ${MX_QT}::Widgets
)

set_target_properties("${exe_name}"
  PROPERTIES
    AUTOMOC TRUE
    AUTOUIC TRUE
    AUTORCC TRUE
)

if(PLATFORM_MACOS)
  target_sources("${exe_name}" PRIVATE
    "MacOSUtils.h"
    "MacOSUtils.mm"
  )

  target_link_libraries("${exe_name}"
    PRIVATE
      "-framework AppKit"
  )
endif(PLATFORM_MACOS)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "${exe_name}"
    DESTINATION
      "${CMAKE_INSTALL_BINDIR}")
endif()
