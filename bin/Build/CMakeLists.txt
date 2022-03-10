#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)
set(exe_name "mx-build")

# Copy python scripts to the build directory
file(GLOB_RECURSE pyfiles mxbuild/*.py)
foreach (filename ${pyfiles})
  get_filename_component(target "${filename}" NAME)
  message(STATUS "Copying ${filename} to ${CMAKE_CURRENT_BINARY_DIR}/mxbuild/${target}")
  configure_file("${filename}"
    "${CMAKE_CURRENT_BINARY_DIR}/mxbuild/${target}" COPYONLY)
endforeach (filename)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Dockerfile.in
  ${CMAKE_CURRENT_BINARY_DIR}/mxbuild/Dockerfile COPYONLY)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/mx-build.py
  ${CMAKE_CURRENT_BINARY_DIR}/mx-build @ONLY)
