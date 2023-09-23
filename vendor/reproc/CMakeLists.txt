#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT MX_USE_VENDORED_REPROC)
  find_package(reproc++ CONFIG QUIET)
  if(reproc++_FOUND)
    return()
  endif()
endif()

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")
set(build_dir "${CMAKE_CURRENT_BINARY_DIR}/build")

# Fetch the submodule if we don't yet have it.
if(NOT EXISTS "${src_dir}/CMakeLists.txt")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule update --init vendor/reproc/src
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()

# This is the main build, setup and execute the nested build
# to ensure the reproc library exists before continuing

execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${build_dir}")

# set(REPROC_MULTITHREADED ON)
# set(REPROC_DEVELOP OFF)
# set(REPROC++ ON)
# set(REPROC_TEST OFF)
# set(REPROC_EXAMPLES OFF)
# set(REPROC_WARNINGS $<CONFIG:Debug>)
# set(REPROC_TIDY OFF)
# set(REPROC_WARNINGS_AS_ERRORS OFF)

# (b) Nested CMake run. May need more -D... options than shown here.
execute_process(COMMAND ${CMAKE_COMMAND}
                        -G "${CMAKE_GENERATOR}"
                        "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
                        "-DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}"
                        "-DCMAKE_INSTALL_PREFIX=${MX_VENDOR_INSTALL_DIR}"
                        "-DCMAKE_INSTALL_RPATH=${CMAKE_INSTALL_RPATH}"
                        "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
                        "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
                        -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
                        -DREPROC_MULTITHREADED=ON
                        "-DREPROC++=ON"
                        -DREPROC_DEVELOP=OFF
                        -DREPROC_TEST=OFF
                        -DREPROC_EXAMPLES=OFF
                        -DREPROC_WARNINGS=$<CONFIG:Debug>
                        -DREPROC_TIDY=OFF
                        -DREPROC_WARNINGS_AS_ERRORS=OFF
                        -DREPROC_OBJECT_LIBRARIES=OFF
                        -DREPROC_INSTALL=ON
                        -DREPROC_INSTALL_PKGCONFIG=ON
                        "${src_dir}"
               WORKING_DIRECTORY "${build_dir}")

# (c) Build just mycomp in the nested build. Don't specify a --config
#     because we cannot know what config the developer will be using
#     at this point. For non-multi-config generators, we've already
#     specified CMAKE_BUILD_TYPE above in (b).
execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install
                WORKING_DIRECTORY "${build_dir}")

find_package(reproc CONFIG REQUIRED PATHS "${MX_VENDOR_INSTALL_DIR}" NO_DEFAULT_PATH)
find_package(reproc++ CONFIG REQUIRED PATHS "${MX_VENDOR_INSTALL_DIR}" NO_DEFAULT_PATH)
