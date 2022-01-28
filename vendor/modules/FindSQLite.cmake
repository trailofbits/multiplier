#
# Copyright (c) 2019-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(LIBRARY_ROOT "${PROJECT_BINARY_DIR}/vendor/sqlite/install")

set(SQLite_FOUND TRUE)
set(SQLite_INCLUDE_DIR "${LIBRARY_ROOT}/include")
set(SQLite_INCLUDE_DIRS "${LIBRARY_ROOT}/include")

if(DEFINED WIN32)
  set(LIBRARY_PREFIX "")
  set(LIBRARY_EXTENSION "lib")
else()
  set(LIBRARY_PREFIX "lib")
  set(LIBRARY_EXTENSION "a")
endif()

set(SQLite_LIBRARIES
    "${LIBRARY_ROOT}/lib/${LIBRARY_PREFIX}sqlite3.${LIBRARY_EXTENSION}"
)

mark_as_advanced(FORCE SQLite_FOUND)
mark_as_advanced(FORCE SQLite_INCLUDE_DIRS)
mark_as_advanced(FORCE SQLite_LIBRARIES)