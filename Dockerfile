ARG IMAGE=ubuntu:22.04
FROM --platform=linux/amd64 ${IMAGE} as builder
ENV INSTALL_DIR=/work/install
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# Install dependencies
RUN apt-get update \
    && apt-get install --no-install-recommends -y curl gnupg software-properties-common lsb-release \
    && sudo apt remove --purge --auto-remove cmake \
    && sudo apt update \
    && sudo apt clean all \
    && wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null \
    && sudo apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main" \
    && sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 6AF7F09730B3F0A4 \
    && sudo apt update \
    && sudo apt install kitware-archive-keyring \
    && sudo rm /etc/apt/trusted.gpg.d/kitware.gpg \
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
    -DCMAKE_LINKER_TYPE=LLD \
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
