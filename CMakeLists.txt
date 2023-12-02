#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

cmake_minimum_required(VERSION 3.23)

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

set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_C_VISIBILITY_PRESET default)
set(VISIBILITY_INLINES_HIDDEN YES)

list(PREPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

include("cmake/system.cmake")
include("cmake/llvm.cmake")
include("cmake/linker.cmake")
include("cmake/git.cmake")

if(MX_ENABLE_INSTALL)
  include("cmake/packaging.cmake")
endif(MX_ENABLE_INSTALL)

if(PLATFORM_MACOS)
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
find_package(Python3 COMPONENTS Interpreter REQUIRED)
find_package(CapnProto CONFIG REQUIRED)
find_package(xxHash CONFIG REQUIRED)
find_package(zstd CONFIG REQUIRED)
if(NOT TARGET zstd::zstd)
  if(TARGET zstd::libzstd_static)
    add_library(zstd::zstd ALIAS zstd::libzstd_static)
  elseif(TARGET zstd::libzstd_shared)
    add_library(zstd::zstd ALIAS zstd::libzstd_shared)
  else()
    message(FATAL_ERROR "Cannot find appropriate zstd target; known targets are ${zstd_LIBRARIES}")
  endif()
endif()

find_package(gap CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)
find_package(pasta CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(reproc++ CONFIG REQUIRED)
find_package(RocksDB CONFIG REQUIRED)

if(MX_ENABLE_VAST)
  find_package(LLVM CONFIG REQUIRED)
  find_package(MLIR CONFIG REQUIRED)
  find_package(VAST CONFIG REQUIRED)

  include("cmake/mlir.cmake")
  include("cmake/vast.cmake")
endif()

if(MX_ENABLE_INSTALL)
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

get_patch_from_git(MX_GIT_HASH)
configure_file(lib/Version.cpp.in "${PROJECT_BINARY_DIR}/Version.cpp" @ONLY)


if(MX_ENABLE_BOOTSTRAP)
  add_subdirectory("bin/Bootstrap")
else()
  add_subdirectory("lib")
  add_subdirectory("bindings")

  add_library("multiplier" SHARED
    "${PROJECT_BINARY_DIR}/Version.cpp"
  )

  target_include_directories("multiplier"
    PUBLIC
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
      $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

  target_link_libraries("multiplier"
    PUBLIC
      "gap::gap"
      "gap::gap-core"
      "gap::gap-settings"
      "std::coroutines"
    PRIVATE
      $<LINK_LIBRARY:WHOLE_ARCHIVE,$<$<BOOL:${MX_ENABLE_PYTHON_BINDINGS}>:mx-python>>
  )

  set_target_properties("multiplier"
    PROPERTIES
      LINKER_LANGUAGE
        CXX
      PUBLIC_HEADER
        "${api_headers}"
      VISIBILITY_INLINES_HIDDEN
        NO
      CXX_VISIBILITY_PRESET
        default
      POSITION_INDEPENDENT_CODE
        YES
      COMPILE_FEATURES
        cxx_std_20
      INTERFACE_COMPILE_FEATURES
        cxx_std_20
  )

  install(
    TARGETS
      "multiplier"
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${MX_INSTALL_BIN_DIR}"
    LIBRARY
      DESTINATION
        "${MX_INSTALL_LIB_DIR}"
    ARCHIVE
      DESTINATION
        "${MX_INSTALL_LIB_DIR}"
    PUBLIC_HEADER
      DESTINATION
        "${MX_INSTALL_INCLUDE_DIR}"
  )

  add_subdirectory("bin")
endif()
