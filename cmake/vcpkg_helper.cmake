#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if (NOT EXISTS "${VCPKG_ROOT}")
  message(FATAL_ERROR "VCPKG_ROOT directory does not exist: '${VCPKG_ROOT}'")
endif()

# Find remill first because its config has useful dependency-finding info that
# needs to be found before the CMake `project` declaration
find_package(remill COMPONENTS VCPKG_DEPS QUIET)

set(VCPKG_ROOT_INSTALL_DIR "${VCPKG_ROOT}/installed")
if (NOT EXISTS "${VCPKG_ROOT_INSTALL_DIR}")
  message(FATAL_ERROR "VCPKG_ROOT installation directory does not exist: '${VCPKG_ROOT_INSTALL_DIR}'")
endif()

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "" FORCE)

# Set default triplet to Release VCPKG build unless we can't find it
if (NOT DEFINED VCPKG_TARGET_TRIPLET)
  set(_project_arch "x64")
  if (UNIX)
    execute_process(COMMAND uname -m
                    OUTPUT_VARIABLE _SYSTEM_ARCH
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
  else()
    message(WARNING "No detection of architecture for this platform. Assuming x64")
  endif()
  if (_SYSTEM_ARCH MATCHES "^[Aa][Aa][Rr][Cc][Hh]64$")
    set(_project_arch "arm64")
  endif()

  if (APPLE)
    set(_project_vcpkg_triplet "${_project_arch}-osx-rel")
  elseif(UNIX)
    set(_project_vcpkg_triplet "${_project_arch}-linux-rel")
  elseif(WIN32)
    set(_project_vcpkg_triplet "${_project_arch}-windows-static-md-rel")
  else()
    message(FATAL_ERROR "Could not detect default release triplet")
  endif()

  if (NOT EXISTS "${VCPKG_ROOT_INSTALL_DIR}/${_project_vcpkg_triplet}")
    message(STATUS "Could not find installed project-default triplet '${_project_vcpkg_triplet}' using vcpkg-default for your system")
  else()
    set(VCPKG_TARGET_TRIPLET "${_project_vcpkg_triplet}" CACHE STRING "")
    message(STATUS "Setting default vcpkg triplet to release-only libraries: ${VCPKG_TARGET_TRIPLET}")
  endif()
endif()

if (DEFINED VCPKG_TARGET_TRIPLET AND NOT EXISTS "${VCPKG_ROOT_INSTALL_DIR}/${VCPKG_TARGET_TRIPLET}")
  message(FATAL_ERROR "Could not find vcpkg triplet (${VCPKG_TARGET_TRIPLET}) installation libraries '${VCPKG_ROOT_INSTALL_DIR}/${VCPKG_TARGET_TRIPLET}'.")
endif()

message(STATUS "Using vcpkg installation directory at '${VCPKG_ROOT_INSTALL_DIR}/${VCPKG_TARGET_TRIPLET}'")
