# Multiplier

Multiplier is a code auditing productivity multiplier. It...

 * Comprehensively indexes code (this repository)
 * Provides a C++ API to access indexed code (this repository)
 * Provides a Python API to access indexed code ([py-multiplier](https://github.com/trailofbits/py-multiplier))
 * Provides a GUI for browsing indexed code ([qt-multiplier](https://github.com/trailofbits/qt-multiplier))

## Pre-built releases

You probably want pre-built releases of Multiplier, including its GUI. Hop over to
the [qt-multiplier releases](https://github.com/trailofbits/qt-multiplier/releases) page
to download those. The releases come with Multiplier's indexer, headers, libraries, etc.
built in.

Another place to find pre-built releases is [package-multiplier](https://github.com/trailofbits/package-multiplier/releases).
These releases mostly focus on meeting deliverables for the DARPA V-SPELLS program.

## Building Multiplier

### Step 0

Going forward, we assume the environment variable `WORKSPACE_DIR` dir represents
the directory where everything goes.

### Step 1

Download the [latest release of cxx-common](https://github.com/lifting-bits/cxx-common/releases)
for for your OS/architecture. You need to download the `-pasta` variant.

Extract the downloaded archive. For example,
if you downloaded `vcpkg_macos-12_llvm-16-pasta_xcode-14.2_amd64.tar.xz` then after extracting
you will have a directory `vcpkg_macos-12_llvm-16-pasta_xcode-14.2_amd64` containing two
subdirectories, `scripts` and `installed`. Rename the extracted directory to
`vcpkg-install` and set `VCPKG_ROOT` to be the path to the `vcpkg-install` directory.

```shell
RELEASE_VERSION=v0.3.2
LLVM_VERSION=16
RELEASE_NAME=vcpkg_macos-12_llvm-${LLVM_VERSION}-pasta_xcode-14.2_amd64
VCPKG_ROOT="${WORKSPACE_DIR}/vcpkg-install"
VCPKG_TARGET_TRIPLET=x64-osx-rel


wget "https://github.com/lifting-bits/cxx-common/releases/download/${RELEASE_VERSION}/${RELEASE_NAME}.tar.xz" -P "${WORKSPACE_DIR}"
tar -xf "${RELEASE_NAME}.tar.xz" --directory "${WORKSPACE_DIR}"
rm -rf "${VCPKG_ROOT}"
mv "${WORKSPACE_DIR}/${RELEASE_NAME}" "${VCPKG_ROOT}"
export VCPKG_ROOT=$(python3 -c "import os; import sys; sys.stdout.write(os.path.abspath('${RELEASE_NAME}'))")
```

Be sure to change `VCPKG_TARGET_TRIPLET` for your host!

### Step 2

#### macOS

##### XCode

Make sure that you have an up-to-date XCode. At a command line, you should be able
to run `clang --version` and see something like this:

```shell
% clang --version
Apple clang version 13.1.6 (clang-1316.0.21.2.3)
Target: x86_64-apple-darwin21.4.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

If you don't see that, then try the following:

```shell
xcode-select --install
```

This will pop open some dialogs and you should click "Install". After installing,
try running the following command:

```shell
% xcode-select -p
/Applications/Xcode.app/Contents/Developer
```

It is worth it to try opening XCode (the app). Sometimes opening the GUI triggers
further downloads and installs, which you should do. It is likely that you will
need to re-do this step after each OS update/upgrade.

If you already had XCode installed, and perhaps had it configured for iOS development
or something like that, then you should open up the XCode app, open its "Preferences"
menu, go to the "Locations" tab, and then modify the path for "Command Line Tools."

##### CMake

Make sure that you have an up-to-date CMake build. On macOS, you can [install Homebrew](https://brew.sh/)
and run the following:

```shell
brew install cmake
```

An alternative is to [download](https://cmake.org/download/) and install CMake from
the official website.

#### Linux

```shell
sudo apt-get update
sudo apt-get install cmake cargo graphviz
export PATH=${HOME}/.cargo/bin:$PATH
```

### Step 2

#### Rust

Download and install Rust by following [these instructions](https://www.rust-lang.org/tools/install).
Be sure to configure your Rust to use nightly builds. 

```shell
rustup default nightly
rustup update
```

##### Rust libraries

```shell
cargo install cbindgen
```

### Step 3

Set up your environment.

```shell
mkdir -p "${WORKSPACE_DIR}/build"
mkdir -p "${WORKSPACE_DIR}/src"
mkdir -p "${WORKSPACE_DIR}/install"
```

Set virtual environment for Python:

```shell
if [[ ! -f "${WORKSPACE_DIR}/install/bin/activate" ]]; then
  python3 -m venv "${WORKSPACE_DIR}/install"
fi
source "${WORKSPACE_DIR}/install/bin/activate"
```

### Step 4: Download and build PASTA

```shell
cd "${WORKSPACE_DIR}/src"
git clone git@github.com:trailofbits/pasta.git
```

```shell
mkdir -p "${WORKSPACE_DIR}/build/pasta"
cd "${WORKSPACE_DIR}/build/pasta"
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  "-DCMAKE_INSTALL_PREFIX=${WORKSPACE_DIR}/install" \
  "-DVCPKG_ROOT=${VCPKG_ROOT}" \
  "-DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET}" \
  "-DCMAKE_C_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang" \
  "-DCMAKE_CXX_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang++" \
  -DPASTA_BOOTSTRAP_MACROS=OFF \
  -DPASTA_BOOTSTRAP_TYPES=OFF \
  -DPASTA_ENABLE_TESTING=OFF \
  "${WORKSPACE_DIR}/src/pasta"

make install -j13
```

### Step 5: Download and build weggli-native

```shell
cd "${WORKSPACE_DIR}/src"
git clone https://github.com/trailofbits/weggli-native
```

```shell
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX="${WORKSPACE_DIR}/install" \
  -S "${WORKSPACE_DIR}/src/weggli-native" \
  -B "${WORKSPACE_DIR}/build/weggli-native"

cmake --build "${WORKSPACE_DIR}/build/weggli-native" --target install
```

### Step 6: Download and build VAST

```shell
cd "${WORKSPACE_DIR}/src"
git clone git@github.com:trailofbits/vast.git
```

```shell
mkdir -p "${WORKSPACE_DIR}/build/vast"
cd "${WORKSPACE_DIR}/build/vast"
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  "-DCMAKE_INSTALL_PREFIX=${WORKSPACE_DIR}/install" \
  "-DVCPKG_ROOT=${VCPKG_ROOT}" \
  "-DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET}" \
  "-DCMAKE_C_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang" \
  "-DCMAKE_CXX_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang++" \
  -DVAST_ENABLE_GAP_SUBMODULE=FALSE \
  -DVAST_WARNINGS_AS_ERRORS=FALSE \
  -DVAST_INSTALL=ON \
  -DENABLE_TESTING=OFF \
  "${WORKSPACE_DIR}/src/vast"

make install -j13
```

### Step 7: Download and build Multiplier


```shell
cd "${WORKSPACE_DIR}/src"
git clone --recurse git@github.com:trailofbits/multiplier.git
```

```shell
mkdir -p "${WORKSPACE_DIR}/build/multiplier"
cd "${WORKSPACE_DIR}/build/multiplier"
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  "-DCMAKE_INSTALL_PREFIX=${WORKSPACE_DIR}/install" \
  "-Dpasta_ROOT=${WORKSPACE_DIR}/install" \
  "-DVCPKG_ROOT=${VCPKG_ROOT}" \
  "-DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET}" \
  "-DCMAKE_C_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang" \
  "-DCMAKE_CXX_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang++" \
  -DMX_ENABLE_BOOTSTRAP=OFF \
  -DMX_ENABLE_WEGGLI=ON \
  -DMX_ENABLE_INSTALL=ON \
  "${WORKSPACE_DIR}/src/multiplier"

make install -j13
```
