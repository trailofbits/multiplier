ARG IMAGE=ubuntu:22.04
FROM --platform=linux/amd64 ${IMAGE} as builder
ENV INSTALL_DIR=/work/install
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# Install dependencies
RUN apt-get update \
    && apt-get install --no-install-recommends -y curl gnupg software-properties-common \
    && curl -sSL https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
    && echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-17 main" | tee -a /etc/apt/sources.list \
    && echo "deb-src http://apt.llvm.org/jammy/ llvm-toolchain-jammy-17 main" | tee -a /etc/apt/sources.list \
    && add-apt-repository ppa:ubuntu-toolchain-r/test \
    && apt-get install --no-install-recommends -y \
        gpg zip unzip tar git \
        pkg-config ninja-build ccache cmake build-essential \
        doctest-dev \
        clang-17 lld-17 \
        python3.11 python3.11-dev \
    && curl -sS https://bootstrap.pypa.io/get-pip.py | python3.11 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /work
RUN mkdir src build

COPY . /work/src/multiplier
RUN cmake \
    -S '/work/src/multiplier' \
    -B '/work/build/multiplier' \
    -G Ninja \
    -DCMAKE_EXE_LINKER_FLAGS="--ld-path=$(which ld.lld-17)" \
    -DCMAKE_MODULE_LINKER_FLAGS="--ld-path=$(which ld.lld-17)" \
    -DCMAKE_SHARED_LINKER_FLAGS="--ld-path=$(which ld.lld-17)" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER="$(which clang-17)" \
    -DCMAKE_CXX_COMPILER="$(which clang++-17)" \
    -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
    -DCMAKE_INTERPROCEDURAL_OPTIMIZATION=TRUE \
    -DLLVM_ENABLE_LLD:BOOL=TRUE

RUN cmake --build '/work/build/multiplier' --target install
RUN chmod +x /work/install/bin/*
ENV PATH="/work/install/bin:${PATH}"

FROM --platform=linux/amd64 ${IMAGE} as release
COPY --from=builder /work/install /work/install
