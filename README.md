# Building Multiplier

## Step 0

Going forward, we assume the environment variable `WORKSPACE_DIR` dir represents
the directory where everything goes.

## Step 1

Download the [latest release of cxx-common](https://github.com/lifting-bits/cxx-common/releases)
for LLVM 13 for your OS/architecture. Extract the downloaded archive. For example,
if you downloaded `vcpkg_macos-11_llvm-13_xcode-13.0_amd64.tar.xz` then after extracting
you will have a directory `vcpkg_macos-11_llvm-13_xcode-13.0_amd64` containing two
subdirectories, `scripts` and `installed`. Rename the extracted directory to
`vcpkg-install` and set `VCPKG_ROOT` to be the path to the `vcpkg-install` directory.

```shell
RELEASE_VERSION=v0.2.1
RELEASE_NAME=vcpkg_macos-11_llvm-13_xcode-13.0_amd64
VCPKG_ROOT="${WORKSPACE_DIR}/vcpkg-install"
VCPKG_TARGET_TRIPLET=x64-osx


wget "https://github.com/lifting-bits/cxx-common/releases/download/${RELEASE_VERSION}/${RELEASE_NAME}.tar.xz" -P "${WORKSPACE_DIR}"
tar -xf "${RELEASE_NAME}.tar.xz" --directory "${WORKSPACE_DIR}"
rm -rf "${VCPKG_ROOT}"
mv "${WORKSPACE_DIR}/${RELEASE_NAME}" "${VCPKG_ROOT}"
export VCPKG_ROOT=$(python3 -c "import os; import sys; sys.stdout.write(os.path.abspath('${RELEASE_NAME}'))")
```

Be sure to change `VCPKG_TARGET_TRIPLET` for your host!

## Step 2

### macOS

#### XCode

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

#### CMake

Make sure that you have an up-to-date CMake build. On macOS, you can [install Homebrew](https://brew.sh/)
and run the following:

```shell
brew install cmake
```

An alternative is to [download](https://cmake.org/download/) and install CMake from
the official website.

### Linux

```shell
sudo apt-get update
sudo apt-get install cmake cargo graphviz
export PATH=${HOME}/.cargo/bin:$PATH
```

## Step 2

### Rust

Download and install Rust by following [these instructions](https://www.rust-lang.org/tools/install).
Be sure to configure your Rust to use nightly builds. 

```shell
rustup default nightly
rustup update
```

#### Rust libraries

```shell
cargo install cbindgen
```

## Step 3

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

## Step 4: Download and build PASTA

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
  "-DVCPKG_ROOT=${VCPKG_ROOT" \
  "-DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET}" \
  "-DCMAKE_C_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang" \
  "-DCMAKE_CXX_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang++" \
  -DPASTA_BOOTSTRAP_MACROS=OFF \
  -DPASTA_BOOTSTRAP_TYPES=OFF \
  -DPASTA_ENABLE_TESTING=OFF \
  "${WORKSPACE_DIR}/src/pasta"

make install -j13
```

## Step 5: Download and build Multiplier


```shell
cd "${WORKSPACE_DIR}/src"
git clone git@github.com:trailofbits/multiplier.git
```

```shell
mkdir -p "${WORKSPACE_DIR}/build/multiplier"
cd "${WORKSPACE_DIR}/build/multiplier"
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  "-DCMAKE_INSTALL_PREFIX=${WORKSPACE_DIR}/install" \
  "-DVCPKG_ROOT=${VCPKG_ROOT" \
  "-DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET}" \
  "-DCMAKE_C_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang" \
  "-DCMAKE_CXX_COMPILER=${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang++" \
  -DMX_ENABLE_BOOTSTRAP=OFF \
  -DMX_ENABLE_VAST=OFF \
  -DMX_ENABLE_GUI=OFF \
  -DMX_ENABLE_WEGGLI=ON \
  "${WORKSPACE_DIR}/src/multiplier"

make install -j13
```
