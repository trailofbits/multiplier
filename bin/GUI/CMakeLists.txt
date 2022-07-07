#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(MX_QT "Qt${MX_QT_VERSION}")
set(MX_GUI_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(MX_QT_COMPONENTS Core Widgets)
if(MX_QT_VERSION GREATER "5")
  list(APPEND MX_QT_COMPONENTS Core5Compat)
endif()
find_package(${MX_QT} COMPONENTS ${MX_QT_COMPONENTS} REQUIRED)

if(PLATFORM_MACOS)
  set(MACOSX_BUNDLE_ICON_FILE "Logo.ico")
endif()

set(exe_name "mx-gui")
add_executable("${exe_name}" "${executable_type}"

  Resources/resources.qrc
  
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

target_link_libraries("${exe_name}" PRIVATE
  "mx-api"
  ${MX_QT}::Core
  ${MX_QT}::Widgets
)

if(MX_QT_VERSION GREATER "5")
  target_link_libraries("${exe_name}" PRIVATE
    ${MX_QT}::Core5Compat
  )
endif()

set_target_properties("${exe_name}"
  PROPERTIES
    AUTOMOC TRUE
    AUTOUIC TRUE
    AUTORCC TRUE
)


if(PLATFORM_MACOS)
  set(icon_path "${CMAKE_CURRENT_SOURCE_DIR}/Resources/Icons/Logo.ico")
  set(plist_path "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist")

  target_link_libraries("${exe_name}"
    PRIVATE
      "-framework AppKit"
  )
  
  target_sources("${exe_name}" PRIVATE
    "${icon_path}"
    "${plist_path}"
    "MacOSUtils.h"
    "MacOSUtils.mm"
  )
  
  set_source_files_properties("${icon_path}"
    PROPERTIES
      MACOSX_PACKAGE_LOCATION "Resources"
  )
  
  set_source_files_properties("${plist_path}"
    PROPERTIES
      MACOSX_PACKAGE_LOCATION "Contents"
  )
  set(output_bundle_path "${CMAKE_CURRENT_BINARY_DIR}/Multiplier.app")
  
  add_custom_command(
    OUTPUT "${output_bundle_path}"
    DEPENDS "mx-gui" "mx-index" "mx-import" "mxsqlitebridge"
    
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${output_bundle_path}/Contents"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${output_bundle_path}/Contents/Frameworks"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${output_bundle_path}/Contents/MacOS"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${output_bundle_path}/Contents/Resources"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${output_bundle_path}/Contents/bin"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${output_bundle_path}/Contents/lib"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${output_bundle_path}/Contents/PlugIns"
    COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:mx-gui>" "${output_bundle_path}/Contents/MacOS/Multiplier"
    COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:mx-index>" "${output_bundle_path}/Contents/bin/mx-index"
    COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:mx-import>" "${output_bundle_path}/Contents/bin/mx-import"
    COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:mx-import>" "${output_bundle_path}/Contents/lib/mxsqlitebridge"
    COMMAND "${CMAKE_COMMAND}" -E copy "${plist_path}" "${output_bundle_path}/Contents/Info.plist"
    COMMAND "${CMAKE_COMMAND}" -E copy "${icon_path}" "${output_bundle_path}/Contents/Resources/Logo.ico"
  )
  
  add_custom_target("mx-gui-bundle" ALL
    DEPENDS "${output_bundle_path}"
  )
  
  qt_deploy_target("mx-gui-bundle" "${output_bundle_path}")

endif(PLATFORM_MACOS)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "${exe_name}"
    DESTINATION
      "${CMAKE_INSTALL_BINDIR}")
  
  
  if(PLATFORM_MACOS)
    install(
      DIRECTORY
        "${output_bundle_path}"
      DESTINATION
        "."
      USE_SOURCE_PERMISSIONS)
  endif(PLATFORM_MACOS)
endif(MX_ENABLE_INSTALL)
