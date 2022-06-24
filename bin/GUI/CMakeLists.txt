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

if(PLATFORM_MACOS)
  set(executable_type "MACOSX_BUNDLE")
  set(MACOSX_BUNDLE_ICON_FILE "icon.ico")
endif()

set(exe_name "multiplier")
add_executable("${exe_name}" "${executable_type}"

  resources/resources.qrc
  
  Code.h
  
  CodeTheme.cpp
  CodeTheme.h
  
  CodeBrowserView.cpp
  CodeBrowserView.h
  
  CodeSearchResults.cpp
  CodeSearchResults.h
  
  CodeView.cpp
  CodeView.h
  
  Configuration.cpp
  Configuration.h
  
  Event.cpp
  Event.h

  FileBrowserView.cpp
  FileBrowserView.h

  FileView.cpp
  FileView.h
  
  HistoryBrowserView.cpp
  HistoryBrowserView.h

  Main.cpp
  
  Multiplier.cpp
  Multiplier.h
  
  OmniBoxView.cpp
  OmniBoxView.h

  OpenConnectionDialog.cpp
  OpenConnectionDialog.h

  ReferenceBrowserView.cpp
  ReferenceBrowserView.h
  
  TitleNamePrompt.cpp
  TitleNamePrompt.h
  
  Util.cpp
  Util.h
)

if(PLATFORM_MACOS)
  set(icon_path "${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/icon.ico")

  target_sources("${exe_name}" PRIVATE
    "${icon_path}"
  )

  set_source_files_properties("${icon_path}"
    PROPERTIES
      MACOSX_PACKAGE_LOCATION "Resources"
  )
endif()

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
