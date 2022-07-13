#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type")
set(CMAKE_EXPORT_COMPILE_COMMANDS true CACHE BOOL "Generate the compile_commands.json file (forced)" FORCE)

set(MX_QT_VERSION "5" CACHE STRING "Which version to use for the Qt SDK")

set(MX_INSTALL_LIB_DIR "${CMAKE_INSTALL_LIBDIR}" CACHE PATH "Directory in which Multiplier libraries will be installed")
set(MX_INSTALL_BIN_DIR "${CMAKE_INSTALL_BINDIR}" CACHE PATH "Directory in which Multiplier binaries will be installed")
set(MX_INSTALL_INCLUDE_DIR "${CMAKE_INSTALL_INCLUDEDIR}/multiplier" CACHE PATH "Directory in which Multiplier headers will be installed")
set(MX_INSTALL_SHARE_DIR "${CMAKE_INSTALL_DATADIR}" CACHE PATH "Directory in which Multiplier CMake files will be installed")

option(MX_ENABLE_SANITIZERS "Set to true to enable sanitizers on the build binary/libraries")
option(MX_ENABLE_BOOTSTRAP "Set to ON to enable re-bootstrapping of some auto-generated files." OFF)
option(MX_ENABLE_INSTALL "Set to ON to enable the install target" ON)
option(MX_ENABLE_GUI "Set to ON to build the GUI" OFF)
option(MX_ENABLE_WEGGLI "Set to OFF to disable Weggli integration" ON)
option(MX_ENABLE_VAST "Set to OFF to disable VAST SourceIR generation" ON)
option(MX_DOWNLOAD_SQLITE "Set to OFF to use a system-available SQLite install instead of downloading a new copy" ON)
