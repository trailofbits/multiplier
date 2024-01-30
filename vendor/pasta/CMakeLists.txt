#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT MX_USE_VENDORED_PASTA)
  find_package(pasta CONFIG QUIET)
  if(pasta_FOUND)
    return()
  endif()
endif()

find_package(LLVM CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")
find_package(Clang CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")
set(build_dir "${CMAKE_CURRENT_BINARY_DIR}/build")

# Fetch the submodule if we don't yet have it.
if(NOT EXISTS "${src_dir}/CMakeLists.txt")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule update --init vendor/pasta/src
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()

# This is the main build, setup and execute the nested build
# to ensure the pasta library exists before continuing

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
                        "-DCMAKE_EXE_LINKER_FLAGS=${CMAKE_EXE_LINKER_FLAGS}"
                        "-DCMAKE_MODULE_LINKER_FLAGS=${CMAKE_MODULE_LINKER_FLAGS}"
                        "-DCMAKE_SHARED_LINKER_FLAGS=${CMAKE_SHARED_LINKER_FLAGS}"
                        "-DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}"
                        "-DCMAKE_INTERPROCEDURAL_OPTIMIZATION=${CMAKE_INTERPROCEDURAL_OPTIMIZATION}"
                        -DPASTA_BOOTSTRAP_MACROS:BOOL=OFF
                        -DPASTA_BOOTSTRAP_TYPES:BOOL=OFF
                        -DPASTA_ENABLE_TESTING:BOOL=OFF
                        -DPASTA_ENABLE_PY_BINDINGS:BOOL=OFF
                        -DPASTA_USE_VENDORED_CLANG:BOOL=OFF
                        -DPASTA_DISABLE_HOST_COMPILER:BOOL=ON
                        -DPASTA_ENABLE_INSTALL:BOOL=ON
                        "-DLLVM_DIR=${LLVM_DIR}"
                        "-DClang_DIR=${Clang_DIR}"
                        "${src_dir}"
               WORKING_DIRECTORY "${build_dir}"
               COMMAND_ECHO STDOUT)

# (c) Build just mycomp in the nested build. Don't specify a --config
#     because we cannot know what config the developer will be using
#     at this point. For non-multi-config generators, we've already
#     specified CMAKE_BUILD_TYPE above in (b).
execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install
                WORKING_DIRECTORY "${build_dir}")

find_package(pasta CONFIG REQUIRED HINTS "${MX_VENDOR_INSTALL_DIR}" NO_DEFAULT_PATH)
