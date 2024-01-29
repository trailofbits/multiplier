vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO trail-of-forks/llvm-project
    REF ba5b66d60c3e1f1a138e753fcf2669fce0d89117
    SHA512 ad345fd870d01e78ac182613dc850d29dbd8c5b71bb5ba35cdb289b94cc315d434614f15dfa0ad09ff697f31c714bfa74a594e89ad1843e8be8ec8d4a23b22c5
    HEAD_REF pasta-llvmorg-17.0.4
)

if("dynamic" STREQUAL "${VCPKG_LIBRARY_LINKAGE}")
    set(LLVM_DYLIB OFF)
else()
    set(LLVM_DYLIB ON)
endif()

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}/llvm"
    OPTIONS
        "-DLLVM_ENABLE_PROJECTS=clang;mlir"
        "-DLLVM_TARGETS_TO_BUILD=AArch64;X86;ARM"
        -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=ARM
        -DLLVM_APPEND_VC_REV=OFF
        -DLLVM_BUILD_DOCS=OFF
        -DLLVM_INCLUDE_DOCS=OFF
        -DLLVM_INCLUDE_EXAMPLES=OFF
        -DLLVM_BUILD_EXAMPLES=OFF
        -DBUILD_SHARED_LIBS=OFF
        -DLLVM_BUILD_LLVM_DYLIB="${LLVM_DYLIB}"
        -DLLVM_BUILD_TESTS=OFF
        -DLLVM_ENABLE_BINDINGS=OFF
        -DLLVM_ENABLE_OCAMLDOC=OFF
        -DLLVM_ENABLE_DIA_SDK=OFF
        -DLLVM_ENABLE_EH=ON
        -DLLVM_ENABLE_RTTI=ON
        -DLLVM_ENABLE_EXPENSIVE_CHECKS=OFF
        -DLLVM_ENABLE_FFI=OFF
        -DLLVM_ENABLE_WARNINGS=ON
        -DLLVM_INCLUDE_BENCHMARKS=OFF
        -DLLVM_INCLUDE_EXAMPLES=OFF
        -DLLVM_INCLUDE_TESTS=OFF
        -DLLVM_INCLUDE_TOOLS=ON
        -DLLVM_INSTALL_UTILS=ON
        -DLLVM_ENABLE_ZSTD=ON
        -DLLVM_OPTIMIZED_TABLEGEN=ON
        -DCMAKE_INSTALL_PACKAGEDIR=share
)
vcpkg_cmake_install(ADD_BIN_TO_PATH)

function(llvm_cmake_package_config_fixup package_name)
    cmake_parse_arguments("arg" "DO_NOT_DELETE_PARENT_CONFIG_PATH" "FEATURE_NAME;CONFIG_PATH" "" ${ARGN})
    if(NOT DEFINED arg_FEATURE_NAME)
        set(arg_FEATURE_NAME ${package_name})
    endif()
    if("${arg_FEATURE_NAME}" STREQUAL "${PORT}" OR "${arg_FEATURE_NAME}" IN_LIST FEATURES)
        set(args)
        list(APPEND args PACKAGE_NAME "${package_name}")
        if(arg_DO_NOT_DELETE_PARENT_CONFIG_PATH)
            list(APPEND args "DO_NOT_DELETE_PARENT_CONFIG_PATH")
        endif()
        if(arg_CONFIG_PATH)
            list(APPEND args "CONFIG_PATH" "${arg_CONFIG_PATH}")
        endif()
        vcpkg_cmake_config_fixup(${args})
        file(INSTALL "${SOURCE_PATH}/${arg_FEATURE_NAME}/LICENSE.TXT" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${package_name}" RENAME copyright)
        if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/${package_name}_usage")
            file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/${package_name}_usage" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${package_name}" RENAME usage)
        endif()
    endif()
endfunction()

llvm_cmake_package_config_fixup("Clang" DO_NOT_DELETE_PARENT_CONFIG_PATH)
llvm_cmake_package_config_fixup("MLIR" DO_NOT_DELETE_PARENT_CONFIG_PATH)
llvm_cmake_package_config_fixup("LLVM")

vcpkg_replace_string("${CURRENT_PACKAGES_DIR}/share/mlir/MLIRConfig.cmake" "set(MLIR_MAIN_SRC_DIR \"${SOURCE_PATH}/mlir\")" "")
vcpkg_replace_string("${CURRENT_PACKAGES_DIR}/share/mlir/MLIRConfig.cmake" "${CURRENT_BUILDTREES_DIR}" "\${MLIR_INCLUDE_DIRS}")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/llvm/LICENSE.TXT")

if(NOT DEFINED VCPKG_BUILD_TYPE OR VCPKG_BUILD_TYPE STREQUAL "debug")
    file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/bin"
        "${CURRENT_PACKAGES_DIR}/debug/include"
        "${CURRENT_PACKAGES_DIR}/debug/share"
        "${CURRENT_PACKAGES_DIR}/debug/lib/clang"
    )
endif()

# Use 'bin' instead of 'tools/llvm'
file(GLOB_RECURSE release_targets
    "${CURRENT_PACKAGES_DIR}/share/*/*Targets-*.cmake"
    "${CURRENT_PACKAGES_DIR}/share/*/*Exports-*.cmake"
)
foreach(release_target IN LISTS release_targets)
    file(READ "${release_target}" contents)
    string(REPLACE "${CURRENT_INSTALLED_DIR}" "\${_IMPORT_PREFIX}" contents "${contents}")
    string(REGEX REPLACE
        "\\\${_IMPORT_PREFIX}/tools/llvm/([^ \"]+${EXECUTABLE_SUFFIX})"
        "\${_IMPORT_PREFIX}/bin/\\1"
        contents "${contents}")
    file(WRITE "${release_target}" "${contents}")
endforeach()

if(VCPKG_TARGET_IS_WINDOWS)
    # LLVM still generates a few DLLs in the static build:
    # * LLVM-C.dll
    # * libclang.dll
    # * LTO.dll
    # * Remarks.dll
    set(VCPKG_POLICY_DLLS_IN_STATIC_LIBRARY enabled)
endif()