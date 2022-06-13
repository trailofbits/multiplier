#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library("sqlitebridge"
  "ConnectionModule.cpp"
  "FileTable.cpp"
  "FragmentTable.cpp"
  "Module.cpp"
  "MultiplierModule.cpp"
  "QueryTable.cpp"
  "ReferenceTable.cpp"
  "SQLiteBridge.cpp"
  "Tables.cpp"
  "TableUtils.cpp"
)

target_link_libraries("sqlitebridge"
  PRIVATE
    "mx-api"
    "mx-util"
    LLVMCore
    LLVMSupport
)

add_library("${PROJECT_NAME}::sqlitebridge" ALIAS "sqlitebridge")
target_include_directories("sqlitebridge" PRIVATE ${SQLite3_INCLUDE_DIRS})

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions("sqlitebridge" PRIVATE "-DSQLITE_CORE")
endif()

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