ARG IMAGE=ubuntu:22.04
FROM --platform=linux/amd64 ${IMAGE} as builder
ENV CXX_COMMON_URL=https://github.com/lifting-bits/cxx-common/releases/download/v0.4.1/vcpkg_ubuntu-22.04_llvm-16-pasta_amd64.tar.xz \
    VCPKG_ROOT=/work/vcpkg_ubuntu-22.04_llvm-16-pasta_amd64 \
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
        doctest-dev clang-15 python3.10 python3.10-dev \
    && curl -sS https://bootstrap.pypa.io/get-pip.py | python3.10 \
    && python3 -m pip install nanobind \
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
RUN git clone --depth 1 https://github.com/lifting-bits/gap.git /work/src/gap \
    && cmake \
        -S '/work/src/gap' \
        -B '/work/build/gap' \
        -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
        -DCMAKE_C_COMPILER="$(which clang-15)" \
        -DCMAKE_CXX_COMPILER="$(which clang++-15)" \
        -DVCPKG_ROOT="${VCPKG_ROOT}" \
        -DVCPKG_MANIFEST_MODE=OFF \
        -DGAP_WARNINGS_AS_ERRORS=OFF \
        -DGAP_ENABLE_TESTING=OFF \
        -DGAP_ENABLE_EXAMPLES=OFF \
        -DGAP_ENABLE_COROUTINES=ON \
        -DUSE_SYSTEM_DEPENDENCIES=OFF \
    && cmake --build '/work/build/gap' --target install

# Build and install weggli-native
RUN git clone --depth 1 https://github.com/trailofbits/weggli-native /work/src/weggli-native \
    && cargo install --force cbindgen \
    && cmake \
        -S '/work/src/weggli-native' \
        -B '/work/build/weggli-native' \
        -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
    && cmake --build '/work/build/weggli-native' --target install

# Build and install pasta
RUN git clone --depth 1 https://github.com/trailofbits/pasta /work/src/pasta \
    && cmake \
        -S '/work/src/pasta' \
        -B '/work/build/pasta' \
        -G Ninja \
        -DCMAKE_TOOLCHAIN_FILE="${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" \
        -DVCPKG_TARGET_TRIPLET=x64-linux-rel \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_COMPILER="$(which clang-15)" \
        -DCMAKE_CXX_COMPILER="$(which clang++-15)" \
        -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
        -DPASTA_BOOTSTRAP_MACROS=OFF \
        -DPASTA_BOOTSTRAP_TYPES=OFF \
        -DPASTA_ENABLE_TESTING=OFF \
        -DPASTA_ENABLE_INSTALL=ON \
        -DCMAKE_CXX_FLAGS=-w \
    && cmake --build '/work/build/pasta' --target install

COPY . /work/src/multiplier
RUN cmake \
    -S '/work/src/multiplier' \
    -B '/work/build/multiplier' \
    -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE="${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" \
    -DVCPKG_TARGET_TRIPLET=x64-linux-rel \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER="$(which clang-15)" \
    -DCMAKE_CXX_COMPILER="$(which clang++-15)" \
    -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
    -DMX_ENABLE_BOOTSTRAP=OFF \
    -DMX_ENABLE_VAST=OFF \
    -DMX_ENABLE_WEGGLI=ON \
    -DMX_ENABLE_INSTALL=ON

RUN cmake --build '/work/build/multiplier' --target install
RUN chmod +x /work/install/bin/*
ENV PATH="/work/install/bin:${PATH}"


FROM --platform=linux/amd64 ${IMAGE} as release
COPY --from=builder /work/install /work/install
