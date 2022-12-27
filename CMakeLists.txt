#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

cmake_minimum_required(VERSION 3.19)

include("cmake/ccache.cmake")

project("multiplier" CXX C)

# Have issues with imported locations for Cap'n Proto with `RelWithDebInfo`
# build types.
if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
  message(FATAL_ERROR "CMAKE_BUILD_TYPE must not be RelWithDebInfo")
endif()

include(CMakeDependentOption)
include(GNUInstallDirs)
include("cmake/options.cmake")

set(CMAKE_CXX_VISIBILITY_PRESET hidden) 
set(CMAKE_C_VISIBILITY_PRESET hidden) 
set(VISIBILITY_INLINES_HIDDEN YES)

list(PREPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

include("cmake/system.cmake")
include("cmake/llvm.cmake")

if(MX_ENABLE_RE2)
  find_package(re2 CONFIG REQUIRED)
endif(MX_ENABLE_RE2)

if(MX_ENABLE_WEGGLI)
  find_package(weggli_native CONFIG REQUIRED)
endif(MX_ENABLE_WEGGLI)

if(MX_ENABLE_INSTALL)
  include("cmake/packaging.cmake")
endif(MX_ENABLE_INSTALL)

add_subdirectory("vendor")

DownloadSQLite3()

find_package(Filesystem REQUIRED COMPONENTS Final Experimental)
find_package(CapnProto CONFIG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(Z3 CONFIG REQUIRED)
find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)

find_package(reproc++ REQUIRED)
find_package(pasta CONFIG REQUIRED)
find_package(Python3 COMPONENTS Interpreter REQUIRED)

if(PLATFORM_MACOS)
  set(CMAKE_INSTALL_RPATH "@executable_path/../${CMAKE_INSTALL_LIBDIR}")
elseif(PLATFORM_LINUX)
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
endif()

if(MX_ENABLE_VAST)
  find_package(vast CONFIG REQUIRED)
  find_package(MLIR CONFIG REQUIRED)
endif(MX_ENABLE_VAST)

if(MX_ENABLE_INSTALL)
  export(PACKAGE "${PROJECT_NAME}")
  
  set(cmake_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
  
  include(CMakePackageConfigHelpers)
  configure_package_config_file("${PROJECT_NAME}Config.cmake.in"
      "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
      INSTALL_DESTINATION "${cmake_install_dir}"
  )

  install(
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
      "${PROJECT_SOURCE_DIR}/cmake/modules/FindFilesystem.cmake"
    DESTINATION "${cmake_install_dir}"
  )
  install(EXPORT "${PROJECT_NAME}Targets"
    DESTINATION "${cmake_install_dir}"
    NAMESPACE "${PROJECT_NAME}::"
  )
endif(MX_ENABLE_INSTALL)

# TODO(pag): Handle this better. We need to make sure all symbols from
#            tools are linked in, otherwise global constructors in tools
#            won't be called, and then they won't get created in `ToolMain.cpp`.
if(PLATFORM_MACOS)
  set("MX_BEGIN_FORCE_LOAD_LIB" "-Wl,-force_load")
  set("MX_END_FORCE_LOAD_LIB" "")
elseif(PLATFORM_LINUX)
  set("MX_BEGIN_FORCE_LOAD_GROUP" "-Wl,--whole-archive")
  set("MX_END_FORCE_LOAD_GROUP" "-Wl,--no-whole-archive")
endif()

# The remaining arguments to `mx-bootstrap` are the paths to the files that will
# be generated based on analyzing the types/classes in the `pasta` namespace.
set(MX_BOOTSTRAP_LIB_COMMON_AST_CAPNP "${PROJECT_SOURCE_DIR}/lib/Common/AST.capnp")
set(MX_BOOTSTRAP_INDEX_PASTA_CPP "${PROJECT_SOURCE_DIR}/bin/Index/PASTA.cpp")
set(MX_BOOTSTRAP_INDEX_PASTA_H "${PROJECT_SOURCE_DIR}/bin/Index/PASTA.h")
set(MX_BOOTSTRAP_LIB_API_AST_CPP "${PROJECT_SOURCE_DIR}/lib/API/AST.cpp")
set(MX_BOOTSTRAP_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/multiplier")
set(MX_BOOTSTRAP_INDEX_SERIALIZE_H "${PROJECT_SOURCE_DIR}/bin/Index/Serialize.h")
set(MX_BOOTSTRAP_INDEX_SERIALIZE_CPP "${PROJECT_SOURCE_DIR}/bin/Index/Serialize.cpp")
set(MX_BOOTSTRAP_INCLUDE_VISITOR_INC_H "${PROJECT_SOURCE_DIR}/include/multiplier/Visitor.inc.h")

if(MX_ENABLE_BOOTSTRAP)
  add_subdirectory("bin/Bootstrap")
else()
  add_subdirectory("lib")
  add_subdirectory("bin")
endif()
