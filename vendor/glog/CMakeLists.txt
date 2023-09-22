#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT MX_USE_VENDORED_GLOG)
  find_package(glog CONFIG QUIET)
  if(glog_FOUND)
    return()
  endif()
endif()

find_package(gflags CONFIG)
if(NOT gflags_FOUND)
  message(FATAL_ERROR "Could not find gflags depedency for glog.")
endif()

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")
set(build_dir "${CMAKE_CURRENT_BINARY_DIR}/build")
set(install_dir "${CMAKE_CURRENT_BINARY_DIR}/install")

# Fetch the submodule if we don't yet have it.
if(NOT EXISTS "${src_dir}/CMakeLists.txt")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule update --init src
    WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
endif()

# This is the main build, setup and execute the nested build
# to ensure the glog library exists before continuing

execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${build_dir}")
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${install_dir}")

# (b) Nested CMake run. May need more -D... options than shown here.
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}"
                        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                        -DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}
                        "-DCMAKE_INSTALL_PREFIX=${install_dir}"
                        "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
                        "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
                        -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
                        "-G${CMAKE_GENERATOR}"
                        -DBUILD_SHARED_LIBS=OFF
                        -DPRINT_UNSYMBOLIZED_STACK_TRACES=OFF
                        -DWITH_GFLAGS=ON
                        -DWITH_GTEST=OFF
                        -DWITH_GMOCK=OFF
                        -DWITH_SYMBOLIZE=OFF
                        -DWITH_THREADS=ON
                        -DWITH_TLS=ON
                        -DWITH_UNWIND=OFF
                        "-Dgflags_DIR=${gflags_DIR}"
                        "${src_dir}"
               WORKING_DIRECTORY "${build_dir}")

# (c) Build just mycomp in the nested build. Don't specify a --config
#     because we cannot know what config the developer will be using
#     at this point. For non-multi-config generators, we've already
#     specified CMAKE_BUILD_TYPE above in (b).
execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install
                WORKING_DIRECTORY "${build_dir}")

find_package(glog CONFIG REQUIRED PATHS "${install_dir}" NO_DEFAULT_PATH)
