#
# Copyright (c) 2023-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT MX_USE_VENDORED_GAP)
  
  # NOTE(pag): Require that we find Gap in the installation directory. This
  #            simplifies releases, and ensures that vendoring also installs
  #            gap into the releases directory.
  find_package(gap CONFIG QUIET PATHS "${CMAKE_INSTALL_PREFIX}" NO_DEFAULT_PATH)
  if(gap_FOUND)
    return()
  endif()
endif()

find_package(LLVM CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")
find_package(MLIR CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")
find_package(Clang CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")

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

# NOTE(pag): We use `CMAKE_INSTALL_PREFIX` so that `gap` ends up inside of our
#            installation prefix for Multiplier, so that it's easy to
#            distribute.
execute_process(COMMAND ${CMAKE_COMMAND}
                        -G "${CMAKE_GENERATOR}"
                        "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
                        "-DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}"
                        "-DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}"
                        "-DCMAKE_INSTALL_RPATH=${CMAKE_INSTALL_RPATH}"
                        "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
                        "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
                        "-DCMAKE_LINKER_TYPE=${CMAKE_LINKER_TYPE}"
                        "-DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}"
                        "-DCMAKE_INTERPROCEDURAL_OPTIMIZATION=${CMAKE_INTERPROCEDURAL_OPTIMIZATION}"
                        -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON
                        -DGAP_ENABLE_TESTING:BOOL=OFF
                        -DGAP_ENABLE_EXAMPLES:BOOL=OFF
                        -DGAP_ENABLE_COROUTINES:BOOL=ON
                        -DGAP_ENABLE_VCPKG:BOOL=OFF
                        -DGAP_ENABLE_WARNINGS:BOOL=OFF
                        -DGAP_ENABLE_SARIF:BOOL=OFF
                        -DGAP_ENABLE_MLIR:BOOL=ON
                        -DGAP_INSTALL:BOOL=ON
                        "-DLLVM_DIR=${LLVM_DIR}"
                        "-DMLIR_DIR=${MLIR_DIR}"
                        "-DClang_DIR=${Clang_DIR}"
                        "${src_dir}"
               WORKING_DIRECTORY "${build_dir}")

execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install
                WORKING_DIRECTORY "${build_dir}")

find_package(gap CONFIG REQUIRED HINTS "${CMAKE_INSTALL_PREFIX}" NO_DEFAULT_PATH)
