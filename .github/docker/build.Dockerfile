FROM --platform=linux/amd64 ubuntu:22.04
ENV CXX_COMMON_URL=https://github.com/lifting-bits/cxx-common/releases/download/v0.2.24/vcpkg_ubuntu-22.04_llvm-15-pasta_amd64.tar.xz \
    VCPKG_ROOT=/work/vcpkg_ubuntu-22.04_llvm-15-pasta_amd64 \
    INSTALL_DIR=/work/install
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# Install dependencies
RUN apt-get update \
    && apt-get install --no-install-recommends -y curl gnupg software-properties-common \
    && curl -sSL https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
    && echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-15 main" | tee -a /etc/apt/sources.list \
    && echo "deb-src http://apt.llvm.org/jammy/ llvm-toolchain-jammy-15 main" | tee -a /etc/apt/sources.list \
    && add-apt-repository ppa:ubuntu-toolchain-r/test \
    && apt-get install --no-install-recommends -y \
        cmake gpg zip unzip tar git pkg-config \
        ninja-build clang-tidy cppcheck ccache build-essential \
        doctest-dev clang-15 bear \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /work
RUN mkdir src build

# Install Rust stable
RUN curl https://sh.rustup.rs -sSf | sh -s -- -y --default-toolchain stable
ENV PATH="/root/.cargo/bin:${PATH}"

# Download cxx-common
RUN curl -sSL "${CXX_COMMON_URL}" | tar xJ

# Build and install gap
RUN git clone https://github.com/lifting-bits/gap.git /work/src/gap \
    && cmake \
        -S '/work/src/gap' \
        -B '/work/build/gap' \
        -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DUSE_SYSTEM_DEPENDENCIES=ON \
        -DCMAKE_C_COMPILER="$(which clang-15)" \
        -DCMAKE_CXX_COMPILER="$(which clang++-15)" \
        -DGAP_ENABLE_WARNINGS=OFF \
        -DGAP_ENABLE_TESTING=OFF \
        -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
    && cmake --build '/work/build/gap' --target install

# Build and install weggli-native
RUN git clone https://github.com/trailofbits/weggli-native /work/src/weggli-native \
    && cargo install --force cbindgen \
    && cmake \
        -S '/work/src/weggli-native' \
        -B '/work/build/weggli-native' \
        -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
    && cmake --build '/work/build/weggli-native' --target install

# Build and install pasta
RUN git clone https://github.com/trailofbits/pasta /work/src/pasta \
    && cmake \
        --toolchain "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" \
        -S '/work/src/pasta' \
        -B '/work/build/pasta' \
        -G Ninja \
        -DVCPKG_ROOT="${VCPKG_ROOT}" \
        -DVCPKG_TARGET_TRIPLET=x64-linux-rel \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_COMPILER="$(which clang-15)" \
        -DCMAKE_CXX_COMPILER="$(which clang++-15)" \
        -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
        -DPASTA_BOOTSTRAP_MACROS=OFF \
        -DPASTA_BOOTSTRAP_TYPES=OFF \
        -DPASTA_ENABLE_TESTING=OFF \
        -DPASTA_ENABLE_INSTALL=ON \
    && cmake --build '/work/build/pasta' --target install

