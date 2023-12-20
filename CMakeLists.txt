#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

cmake_minimum_required(VERSION 3.24)

include("cmake/ccache.cmake")

project("multiplier" CXX C)

include(CMakeDependentOption)
include(GNUInstallDirs)
include("cmake/options.cmake")

# Have issues with imported locations for Cap'n Proto with `RelWithDebInfo`
# build types.
if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
  message(FATAL_ERROR "CMAKE_BUILD_TYPE must not be RelWithDebInfo")
endif()

list(PREPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

include("cmake/system.cmake")
include("cmake/llvm.cmake")
include("cmake/linker.cmake")
include("cmake/git.cmake")

if(MX_ENABLE_INSTALL)
  include("cmake/packaging.cmake")
endif(MX_ENABLE_INSTALL)

if(PLATFORM_MACOS)
  set(CMAKE_MACOSX_RPATH 1)
  set(CMAKE_INSTALL_RPATH "@executable_path/../${MX_INSTALL_LIB_DIR}")
elseif(PLATFORM_LINUX)
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../${MX_INSTALL_LIB_DIR}")
endif()

add_subdirectory("vendor")

if(MX_ENABLE_RE2)
  find_package(re2 CONFIG REQUIRED)
endif(MX_ENABLE_RE2)

find_package(gflags CONFIG REQUIRED)
if(NOT TARGET gflags::gflags)
  if(TARGET gflags::gflags_static)
    add_library(gflags::gflags ALIAS gflags::gflags_static)
  elseif(TARGET gflags_static)
    add_library(gflags::gflags_static ALIAS gflags_static)
    add_library(gflags::gflags ALIAS gflags_static)
  else()
    message(FATAL_ERROR "Cannot find appropriate gflags target; known targets are ${gflags_LIBRARIES}")
  endif()
endif()

find_package(Filesystem REQUIRED COMPONENTS Final Experimental)
find_package(CapnProto CONFIG REQUIRED)
find_package(xxHash CONFIG REQUIRED)
find_package(zstd CONFIG REQUIRED)
find_package(gap CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)
find_package(pasta CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(reproc++ CONFIG REQUIRED)
find_package(RocksDB CONFIG REQUIRED)
find_package(LLVM CONFIG REQUIRED)
find_package(MLIR CONFIG REQUIRED)
find_package(VAST CONFIG REQUIRED)

include("cmake/mlir.cmake")
include("cmake/vast.cmake")

if(MX_ENABLE_PYTHON_BINDINGS)
  find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Embed)
endif()

if(MX_ENABLE_INSTALL AND NOT MX_ENABLE_BOOTSTRAP)
  export(PACKAGE "${PROJECT_NAME}")
  
  set(cmake_install_dir "${MX_INSTALL_LIB_DIR}/cmake/${PROJECT_NAME}")
  
  include(CMakePackageConfigHelpers)
  configure_package_config_file("${PROJECT_NAME}Config.cmake.in"
      "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
      INSTALL_DESTINATION "${cmake_install_dir}"
  )

  install(
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
      "${PROJECT_SOURCE_DIR}/cmake/modules/FindFilesystem.cmake"
    DESTINATION
      "${cmake_install_dir}"
  )
  install(
    EXPORT
      "${PROJECT_NAME}Targets"
    DESTINATION
      "${cmake_install_dir}"
    NAMESPACE
      "${PROJECT_NAME}::"
  )
endif(MX_ENABLE_INSTALL)

# The remaining arguments to `mx-bootstrap` are the paths to the files that will
# be generated based on analyzing the types/classes in the `pasta` namespace.
set(MX_BOOTSTRAP_LIB_AST_CAPNP "${PROJECT_SOURCE_DIR}/lib/AST.capnp")
set(MX_BOOTSTRAP_INDEX_PASTA_CPP "${PROJECT_SOURCE_DIR}/bin/Index/PASTA.cpp")
set(MX_BOOTSTRAP_INDEX_PASTA_H "${PROJECT_SOURCE_DIR}/bin/Index/PASTA.h")
set(MX_BOOTSTRAP_LIB_DIR "${PROJECT_SOURCE_DIR}/lib")
set(MX_BOOTSTRAP_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/multiplier")
set(MX_BOOTSTRAP_INDEX_SERIALIZE_H "${PROJECT_SOURCE_DIR}/bin/Index/Serialize.h")
set(MX_BOOTSTRAP_INDEX_SERIALIZE_CPP "${PROJECT_SOURCE_DIR}/bin/Index/Serialize.cpp")
set(MX_BOOTSTRAP_INCLUDE_VISITOR_INC_H "${PROJECT_SOURCE_DIR}/include/multiplier/Visitor.inc.h")

# If we're bootstrapping then stop here.
if(MX_ENABLE_BOOTSTRAP)
  add_subdirectory("bin/Bootstrap")
  return()
endif(MX_ENABLE_BOOTSTRAP)

add_subdirectory("lib")
add_subdirectory("bin")
add_subdirectory("bindings")

