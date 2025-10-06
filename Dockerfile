# syntax=docker/dockerfile:1.4
ARG IMAGE=ubuntu:22.04
ARG PLATFORM=linux/amd64
FROM --platform=${PLATFORM} ${IMAGE} AS builder
ENV INSTALL_DIR=/work/install

ARG CLANG_VERSION=18
ARG LLVM_BUILD=f36f80d

# Install dependencies
RUN apt-get update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -yq \
        --no-install-recommends \
        software-properties-common \
        pkg-config \
        cmake \
        make \
        curl \
        wget \
        unzip \
        clang \
        flex \
        bison \
        xz-utils \
        zlib1g-dev \
        libncurses5-dev \
        libssl-dev \
        git \
        ninja-build \
        lld \
        libzstd-dev \
        python3.11 \
        python3.11-dev \
        gcc && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists/*

SHELL [ "/bin/bash", "-o", "pipefail", "-c" ]

# Install clang and cmake
RUN curl -sl https://apt.llvm.org/llvm.sh --output llvm.sh && \
    bash llvm.sh ${CLANG_VERSION} && \
    update-alternatives --install /usr/bin/clang clang /usr/bin/clang-${CLANG_VERSION} 20 \
      --slave /usr/bin/clang++ clang++ /usr/bin/clang++-${CLANG_VERSION} && \
    wget https://github.com/Kitware/CMake/releases/download/v3.30.6/cmake-3.30.6-linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh && \
    chmod u+x /tmp/cmake-install.sh && \
    mkdir /opt/cmake-3.30.6 && \
    /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.30.6 && \
    rm /tmp/cmake-install.sh && \
    ln -s /opt/cmake-3.30.6/bin/* /usr/local/bin

WORKDIR /work

# Install pre-built llvm 18.1 libraries
RUN mkdir -p ${INSTALL_DIR} && \
    curl -L https://github.com/trail-of-forks/llvm-project/releases/download/${LLVM_BUILD}/llvm-pasta-${LLVM_BUILD}.tar.xz -o llvm-pasta-${LLVM_BUILD}.tar.xz && \
    tar -xJf llvm-pasta-*.tar.xz -C ${INSTALL_DIR} && \
    rm llvm-pasta-*.tar.xz

# Configure and build multiplier with pre-built llvm libraries
RUN --mount=type=bind,source=.,target=/work/src/multiplier \
    --mount=type=tmpfs,target=/work/build \
    cmake \
    -S /work/src/multiplier \
    -B /work/build/multiplier \
    -GNinja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
    -DCMAKE_PREFIX_PATH=${INSTALL_DIR} \
    -DCMAKE_EXE_LINKER_FLAGS="--ld-path=$(which ld.lld-${CLANG_VERSION})" \
    -DCMAKE_MODULE_LINKER_FLAGS="--ld-path=$(which ld.lld-${CLANG_VERSION})" \
    -DCMAKE_SHARED_LINKER_FLAGS="--ld-path=$(which ld.lld-${CLANG_VERSION})" \
    -DCMAKE_C_COMPILER="$(which clang-${CLANG_VERSION})" \
    -DCMAKE_CXX_COMPILER="$(which clang++-${CLANG_VERSION})" \
    -DLLVM_DIR="${INSTALL_DIR}/lib/cmake/llvm" \
    -DMLIR_DIR="${INSTALL_DIR}/lib/cmake/mlir" \
    -DClang_DIR="${INSTALL_DIR}/lib/cmake/clang" \
    -DCMAKE_INTERPROCEDURAL_OPTIMIZATION=TRUE \
    -DMX_USE_VENDORED_CLANG=OFF \
    -DMX_ENABLE_INSTALL=ON && \
    cmake --build /work/build/multiplier --target install

RUN chmod +x /work/install/bin/*
ENV PATH="/work/install/bin:${PATH}"

# Copy multiplier binaries from builder
FROM --platform=${PLATFORM} ${IMAGE} AS release
RUN apt-get update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -yq --no-install-recommends libatomic1 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
COPY --from=builder /work/install /work/install
