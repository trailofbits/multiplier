export CMAKE_INSTALL_PREFIX := env_var_or_default("CMAKE_INSTALL_PREFIX", justfile_directory() + "/install")
build_type := "Release"
builds_dir := justfile_directory() + "/builds"

build-llvm:
  cmake -S vendor/llvm-project/src/llvm \
    -B {{builds_dir}}/llvm-project \
    -G Ninja \
    -DCMAKE_BUILD_TYPE={{build_type}} \
    -DCMAKE_INSTALL_PREFIX={{builds_dir}}/install \
    -DCMAKE_CXX_STANDARD=17 \
    -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON \
    -DLLVM_ENABLE_PROJECTS="clang;mlir;lld" \
    -DLLVM_TARGETS_TO_BUILD="AArch64;X86;ARM" \
    -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=ARM \
    -DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi" \
    -DBUILD_SHARED_LIBS:BOOL=OFF \
    -DLLVM_APPEND_VC_REV:BOOL=OFF \
    -DLLVM_INCLUDE_DOCS:BOOL=OFF \
    -DLLVM_INCLUDE_EXAMPLES:BOOL=OFF \
    -DLLVM_BUILD_EXAMPLES:BOOL=OFF \
    -DLLVM_BUILD_LLVM_DYLIB:BOOL=OFF \
    -DLLVM_ENABLE_BINDINGS:BOOL=OFF \
    -DLLVM_ENABLE_DIA_SDK:BOOL=OFF \
    -DLLVM_ENABLE_EH:BOOL=ON \
    -DLLVM_ENABLE_RTTI:BOOL=ON \
    -DLLVM_ENABLE_ASSERTIONS:BOOL=ON \
    -DLLVM_ENABLE_EXPENSIVE_CHECKS:BOOL=OFF \
    -DLLVM_ENABLE_FFI:BOOL=OFF \
    -DLLVM_ENABLE_WARNINGS:BOOL=ON \
    -DLLVM_INCLUDE_BENCHMARKS:BOOL=OFF \
    -DLLVM_INCLUDE_EXAMPLES:BOOL=OFF \
    -DLLVM_INCLUDE_TESTS:BOOL=OFF \
    -DLLVM_INCLUDE_TOOLS:BOOL=ON \
    -DLLVM_INSTALL_UTILS:BOOL=ON \
    -DLLVM_ENABLE_ZSTD:BOOL=OFF && \
  cmake --build {{builds_dir}}/llvm-project && \
  cmake --build {{builds_dir}}/llvm-project --target install

build-pasta:
  cmake -S vendor/pasta/src \
    -B {{builds_dir}}/pasta \
    -G Ninja \
    -DCMAKE_BUILD_TYPE={{build_type}} \
    -DCMAKE_INSTALL_PREFIX={{builds_dir}}/install \
    -DPASTA_ENABLE_INSTALL=ON \
    -DPASTA_ENABLE_TESTING=OFF \
    -DPASTA_USE_VENDORED_CLANG=OFF \
    -DClang_DIR={{builds_dir}}/llvm-project/lib/cmake/clang \
    -DLLVM_DIR={{builds_dir}}/llvm-project/lib/cmake/llvm && \
  cmake --build {{builds_dir}}/pasta && \
  cmake --build {{builds_dir}}/pasta --target install

build-multiplier: build-pasta
  cmake -S . \
    -B {{builds_dir}}/multiplier \
    -G Ninja \
    -DCMAKE_BUILD_TYPE={{build_type}} \
    -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} \
    -DClang_DIR={{builds_dir}}/install/lib/cmake/clang \
    -DLLVM_DIR={{builds_dir}}/install/lib/cmake/llvm \
    -DMLIR_DIR={{builds_dir}}/install/lib/cmake/mlir \
    -Dpasta_DIR={{builds_dir}}/install/lib/cmake/pasta \
    -DMX_USE_VENDORED_CLANG=OFF \
    -DMX_USE_VENDORED_PASTA=OFF && \
  cmake --build {{builds_dir}}/multiplier

install-multiplier: build-multiplier
  cmake --build {{builds_dir}}/multiplier --target install

clean:
  rm -rf {{builds_dir}} install
