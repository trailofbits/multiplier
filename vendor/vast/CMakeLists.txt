#
# Copyright (c) 2023-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT MX_USE_VENDORED_VAST)
  find_package(VAST CONFIG QUIET)
  if(VAST_FOUND)
    return()
  endif()
endif()

find_package(gap CONFIG REQUIRED QUIET)
find_package(LLVM CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")
find_package(MLIR CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")
find_package(Clang CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")
set(build_dir "${CMAKE_CURRENT_BINARY_DIR}/build")

# Fetch the submodule if we don't yet have it.
if(NOT EXISTS "${src_dir}/CMakeLists.txt")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule update --init vendor/vast/src
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")

  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule set-branch --branch mx_codegen vendor/vast/src
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
                        "-DCMAKE_LINKER_TYPE=${CMAKE_LINKER_TYPE}"
                        "-DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}"
                        "-DCMAKE_INTERPROCEDURAL_OPTIMIZATION=${CMAKE_INTERPROCEDURAL_OPTIMIZATION}"
                        -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON
                        -DVAST_ENABLE_GAP_SUBMODULE:BOOL=FALSE
                        -DVAST_WARNINGS_AS_ERRORS:BOOL=FALSE
                        -DVAST_ENABLE_TESTING:BOOL=OFF
                        -DVAST_GENERATE_TOOLS:BOOL=OFF
                        -DVAST_BUILD_TOOLS:BOOL=OFF
                        -DVAST_BUILD_FRONTEND:BOOL=ON
                        -DVAST_ENABLE_EXCEPTIONS:BOOL=ON
                        "-Dgap_DIR=${gap_DIR}"
                        "-DLLVM_DIR=${LLVM_DIR}"
                        "-DMLIR_DIR=${MLIR_DIR}"
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

find_package(VAST CONFIG REQUIRED HINTS "${MX_VENDOR_INSTALL_DIR}" NO_DEFAULT_PATH)
