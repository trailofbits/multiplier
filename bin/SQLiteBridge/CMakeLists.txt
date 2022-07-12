#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

# NOTE(pag): Can't use `-` in the library name due to SQLite limitations.
add_library("mxsqlitebridge" SHARED
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

target_link_libraries("mxsqlitebridge"
  PRIVATE
    "mx-api"
    LLVMCore
    LLVMSupport
)

add_library("${PROJECT_NAME}::sqlitebridge" ALIAS "mxsqlitebridge")

target_include_directories("mxsqlitebridge"
  PRIVATE
    ${SQLite3_INCLUDE_DIRS}
)

# target_compile_definitions("mxsqlitebridge" PRIVATE "-DSQLITE_CORE")

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "mxsqlitebridge"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
  )
endif()