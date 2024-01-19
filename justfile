export CMAKE_INSTALL_PREFIX := env_var_or_default("CMAKE_INSTALL_PREFIX", justfile_directory() + "/install")
build_type := "Release"

build-llvm:
  cmake -S vendor/llvm-project/src/llvm \
    -B builds/llvm-project \
    -G Ninja \
    -DCMAKE_BUILD_TYPE={{build_type}} \
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} \
    -DCMAKE_CXX_STANDARD=17 \
    -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON \
    -DLLVM_ENABLE_PROJECTS="clang;mlir;lld" \
    -DLLVM_TARGETS_TO_BUILD="AArch64;X86;ARM" \
    -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=ARM \
    -DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi" \
    -DBUILD_SHARED_LIBS:BOOL=OFF \
    -DLLVM_APPEND_VC_REV:BOOL=OFF \
    -DLLVM_BUILD_DOCS:BOOL=OFF \
    -DLLVM_INCLUDE_DOCS:BOOL=OFF \
    -DLLVM_INCLUDE_EXAMPLES:BOOL=OFF \
    -DLLVM_BUILD_EXAMPLES:BOOL=OFF \
    -DLLVM_BUILD_LLVM_DYLIB:BOOL=OFF \
    -DLLVM_BUILD_TESTS:BOOL=OFF \
    -DLLVM_ENABLE_BINDINGS:BOOL=OFF \
    -DLLVM_ENABLE_OCAMLDOC:BOOL=OFF \
    -DLLVM_ENABLE_DIA_SDK:BOOL=OFF \
    -DLLVM_ENABLE_EH:BOOL=ON \
    -DLLVM_ENABLE_RTTI:BOOL=ON \
    -DLLVM_ENABLE_ASSERTIONS:BOOL=ON \
    -DLLVM_ENABLE_EXPENSIVE_CHECKS:BOOL=ON \
    -DLLVM_ENABLE_FFI:BOOL=OFF \
    -DLLVM_ENABLE_WARNINGS:BOOL=ON \
    -DLLVM_INCLUDE_BENCHMARKS:BOOL=OFF \
    -DLLVM_INCLUDE_EXAMPLES:BOOL=OFF \
    -DLLVM_INCLUDE_TESTS:BOOL=OFF \
    -DLLVM_INCLUDE_TOOLS:BOOL=ON \
    -DLLVM_INSTALL_UTILS:BOOL=ON \
    -DLLVM_ENABLE_ZSTD:BOOL=OFF && \
  cmake --build builds/llvm-project

install-llvm: build-llvm
  cmake --build builds/llvm-project --target install

build-pasta: install-llvm
  cmake -S vendor/pasta/src \
    -B builds/pasta \
    -G Ninja \
    -DCMAKE_BUILD_TYPE={{build_type}} \
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} \
    -DPASTA_ENABLE_INSTALL=ON \
    -DPASTA_ENABLE_TESTING=OFF \
    -DPASTA_USE_VENDORED_CLANG=OFF \
    -DClang_DIR=${CMAKE_INSTALL_PREFIX}/lib/cmake/clang \
    -DLLVM_DIR=${CMAKE_INSTALL_PREFIX}/lib/cmake/llvm && \
  cmake --build builds/pasta

install-pasta: build-pasta
  cmake --build builds/pasta --target install

build-multiplier: install-pasta
  cmake -S . \
    -B builds/multiplier \
    -G Ninja \
    -DCMAKE_BUILD_TYPE={{build_type}} \
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} \
    -DClang_DIR=${CMAKE_INSTALL_PREFIX}/lib/cmake/clang \
    -DLLVM_DIR=${CMAKE_INSTALL_PREFIX}/lib/cmake/llvm \
    -DMLIR_DIR=${CMAKE_INSTALL_PREFIX}/lib/cmake/llvm \
    -Dpasta_DIR=${CMAKE_INSTALL_PREFIX}/lib/cmake/pasta \
    -DMX_USE_VENDORED_CLANG=OFF \
    -DMX_USE_VENDORED_PASTA=OFF \
  cmake --build builds/multiplier

install-multiplier: build-multiplier
  cmake --build builds/multiplier --target install

clean:
  rm -rf builds install
