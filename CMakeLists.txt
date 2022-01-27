#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

cmake_minimum_required(VERSION 3.19)

include("cmake/options.cmake")
include("cmake/ccache.cmake")
include("cmake/vcpkg_helper.cmake")

project("multiplier")

set(CMAKE_CXX_VISIBILITY_PRESET hidden) 
set(CMAKE_C_VISIBILITY_PRESET hidden) 
set(VISIBILITY_INLINES_HIDDEN YES)

include(GNUInstallDirs)
include("cmake/system.cmake")
include("cmake/llvm.cmake")

if(MX_ENABLE_INSTALL)
  include("cmake/packaging.cmake")
endif(MX_ENABLE_INSTALL)

add_subdirectory("vendor")

find_package(ZLIB REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(Z3 4.8 CONFIG REQUIRED)
find_llvm(llvm)
find_package(Clang CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Flatbuffers CONFIG REQUIRED)

find_package(DrLojekyll CONFIG REQUIRED)
find_package(pasta CONFIG REQUIRED)
find_package(Python3 COMPONENTS Interpreter REQUIRED)

if(MX_ENABLE_INSTALL)
  export(PACKAGE "${PROJECT_NAME}")
  
  set(cmake_install_dir "lib/cmake/${PROJECT_NAME}")
  
  include(CMakePackageConfigHelpers)
  configure_package_config_file("${PROJECT_NAME}Config.cmake.in"
      "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
      INSTALL_DESTINATION "${cmake_install_dir}"
  )

  install(
      FILES
          "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
          "${PROJECT_SOURCE_DIR}/cmake/FindFilesystem.cmake"
      DESTINATION "${cmake_install_dir}"
  )
  install(EXPORT "${PROJECT_NAME}Targets"
      DESTINATION "${cmake_install_dir}"
      NAMESPACE "${PROJECT_NAME}::"
  )
  install(
    TARGETS
      "llvm"
    EXPORT
      "${PROJECT_NAME}Targets"
  )
endif(MX_ENABLE_INSTALL)

# TODO(pag): Handle this better. We need to make sure all symbols from
#            tools are linked in, otherwise global constructors in tools
#            won't be called, and then they won't get created in `ToolMain.cpp`.
if(PLATFORM_MACOS)
  set("MX_BEGIN_FORCE_LOAD_TOOL" "-Wl,-force_load")
  set("MX_END_FORCE_LOAD_TOOL" "")
elseif(PLATFORM_LINUX)
  set("MX_BEGIN_FORCE_LOAD_GROUP" "-Wl,--whole-archive")
  set("MX_END_FORCE_LOAD_GROUP" "-Wl,--no-whole-archive")
endif()

add_subdirectory("lib")
add_subdirectory("bin")

