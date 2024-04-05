#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(NOT MX_USE_VENDORED_CLANG)
  find_package(LLVM CONFIG QUIET)
  find_package(MLIR CONFIG QUIET)
  find_package(Clang CONFIG QUIET)

  if(LLVM_FOUND AND MLIR_FOUND AND Clang_FOUND)
    return()
  endif()
endif()

find_package(zstd CONFIG REQUIRED QUIET HINTS "${MX_VENDOR_INSTALL_DIR}")

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")
set(build_dir "${CMAKE_CURRENT_BINARY_DIR}/build")

# Fetch the submodule if we don't yet have it.
if(NOT EXISTS "${src_dir}/llvm/CMakeLists.txt")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule update --init vendor/llvm-project/src
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")

  execute_process(
    COMMAND "${GIT_EXECUTABLE}" submodule set-branch --branch pasta-llvmorg-17.0.4 vendor/llvm-project/src
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()

# This is the main build, setup and execute the nested build
# to ensure the Clang and MLIR libraries exist before continuing

# NOTE(pag): C++17 seems to be needed when building Clang on Linux, due to uses
#            of `__is_constructible`.

execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "${build_dir}")

# (b) Nested CMake run. May need more -D... options than shown here.
execute_process(COMMAND ${CMAKE_COMMAND}
                        -G "${CMAKE_GENERATOR}"
                        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                        "-DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}"
                        "-DCMAKE_INSTALL_PREFIX=${MX_VENDOR_INSTALL_DIR}"
                        "-DCMAKE_INSTALL_RPATH=${CMAKE_INSTALL_RPATH}"
                        "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
                        "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
                        "-DCMAKE_ASM_COMPILER=${CMAKE_C_COMPILER}"
                        "-DCMAKE_EXE_LINKER_FLAGS=${CMAKE_EXE_LINKER_FLAGS}"
                        "-DCMAKE_MODULE_LINKER_FLAGS=${CMAKE_MODULE_LINKER_FLAGS}"
                        "-DCMAKE_SHARED_LINKER_FLAGS=${CMAKE_SHARED_LINKER_FLAGS}"
                        -DCMAKE_CXX_STANDARD=17
                        "-DCMAKE_INTERPROCEDURAL_OPTIMIZATION=${CMAKE_INTERPROCEDURAL_OPTIMIZATION}"
                        -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON
                        "-DLLVM_ENABLE_PROJECTS=clang;mlir"
                        "-DLLVM_TARGETS_TO_BUILD=AArch64;X86;ARM"
                        "-DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=ARM;WebAssembly"
                        "-DLLVM_ENABLE_RUNTIMES=libcxx;libcxxabi"
                        -DBUILD_SHARED_LIBS:BOOL=OFF
                        -DLLVM_APPEND_VC_REV:BOOL=OFF
                        -DLLVM_BUILD_DOCS:BOOL=OFF
                        -DLLVM_INCLUDE_DOCS:BOOL=OFF
                        -DLLVM_INCLUDE_EXAMPLES:BOOL=OFF
                        -DLLVM_BUILD_EXAMPLES:BOOL=OFF
                        -DLLVM_BUILD_LLVM_DYLIB:BOOL=OFF
                        -DLLVM_BUILD_TESTS:BOOL=OFF
                        -DLLVM_ENABLE_BINDINGS:BOOL=OFF
                        -DLLVM_ENABLE_OCAMLDOC:BOOL=OFF
                        -DLLVM_ENABLE_DIA_SDK:BOOL=OFF
                        -DLLVM_ENABLE_EH:BOOL=ON
                        -DLLVM_ENABLE_RTTI:BOOL=ON
                        "-DLLVM_ENABLE_ASSERTIONS:BOOL=$<CONFIG:Release>"
                        -DLLVM_ENABLE_EXPENSIVE_CHECKS:BOOL=OFF
                        -DLLVM_ENABLE_FFI:BOOL=OFF
                        -DLLVM_ENABLE_WARNINGS:BOOL=ON
                        -DLLVM_INCLUDE_BENCHMARKS:BOOL=OFF
                        -DLLVM_INCLUDE_EXAMPLES:BOOL=OFF
                        -DLLVM_INCLUDE_TESTS:BOOL=OFF
                        -DLLVM_INCLUDE_TOOLS:BOOL=ON
                        -DLLVM_INSTALL_UTILS:BOOL=ON
                        -DLLVM_ENABLE_ZSTD:BOOL=ON
                        "zstd_DIR=${zstd_DIR}"
                        "${src_dir}/llvm"
               WORKING_DIRECTORY "${build_dir}")

# (c) Build just mycomp in the nested build. Don't specify a --config
#     because we cannot know what config the developer will be using
#     at this point. For non-multi-config generators, we've already
#     specified CMAKE_BUILD_TYPE above in (b).
execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install
                WORKING_DIRECTORY "${build_dir}")

find_package(LLVM CONFIG REQUIRED HINTS "${MX_VENDOR_INSTALL_DIR}" NO_DEFAULT_PATH)
find_package(MLIR CONFIG REQUIRED HINTS "${MX_VENDOR_INSTALL_DIR}" NO_DEFAULT_PATH)
find_package(Clang CONFIG REQUIRED PATHS "${MX_VENDOR_INSTALL_DIR}" NO_DEFAULT_PATH)
