#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT MX_USE_VENDORED_GAP)
  find_package(gap CONFIG QUIET)
  if(gap_FOUND)
    return()
  endif()
endif()

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")
set(build_dir "${CMAKE_CURRENT_BINARY_DIR}/build")

# Fetch the submodule if we don't yet have it.
if(NOT EXISTS "${src_dir}/CMakeLists.txt")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule update --init vendor/gap/src
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()

# This is the main build, setup and execute the nested build
# to ensure the gap library exists before continuing

execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${build_dir}")

# (b) Nested CMake run. May need more -D... options than shown here.
execute_process(COMMAND ${CMAKE_COMMAND}
                        -G "${CMAKE_GENERATOR}"
                        "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
                        "-DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}"
                        "-DCMAKE_INSTALL_PREFIX=${MX_VENDOR_INSTALL_DIR}"
                        "-DCMAKE_INSTALL_RPATH=${CMAKE_INSTALL_RPATH}"
                        "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
                        "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
                        "-DCMAKE_EXE_LINKER_FLAGS_INIT=${CMAKE_EXE_LINKER_FLAGS_INIT}"
                        "-DCMAKE_MODULE_LINKER_FLAGS_INIT=${CMAKE_MODULE_LINKER_FLAGS_INIT}"
                        "-DCMAKE_SHARED_LINKER_FLAGS_INIT=${CMAKE_SHARED_LINKER_FLAGS_INIT}"
                        -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
                        -DGAP_ENABLE_TESTING:BOOL=OFF
                        -DGAP_ENABLE_EXAMPLES:BOOL=OFF
                        -DGAP_ENABLE_COROUTINES:BOOL=ON
                        -DGAP_ENABLE_VCPKG:BOOL=OFF
                        -DGAP_ENABLE_WARNINGS:BOOL=OFF
                        -DGAP_INSTALL:BOOL=ON
                        "${src_dir}"
               WORKING_DIRECTORY "${build_dir}")

# (c) Build just mycomp in the nested build. Don't specify a --config
#     because we cannot know what config the developer will be using
#     at this point. For non-multi-config generators, we've already
#     specified CMAKE_BUILD_TYPE above in (b).
execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install
                WORKING_DIRECTORY "${build_dir}")

find_package(gap CONFIG REQUIRED PATHS "${MX_VENDOR_INSTALL_DIR}" NO_DEFAULT_PATH)