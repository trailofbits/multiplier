#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library("sqlitebridge" SHARED
  "FileTable.cpp"
  "FragmentTable.cpp"
  "Module.cpp"
  "MultiplierModule.cpp"
  "SQLiteBridge.cpp"
  "Tables.cpp"
)

target_link_libraries("sqlitebridge"
  PRIVATE
    "mx-api"
    "mx-util"
)

add_library("${PROJECT_NAME}::sqlitebridge" ALIAS "sqlitebridge")
target_include_directories("sqlitebridge" PRIVATE ${SQLite3_INCLUDE_DIRS})

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "sqlitebridge"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
  )
endif()