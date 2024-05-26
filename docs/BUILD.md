# Building Multiplier

## Step 0

Going forward, we assume the environment variable `WORKSPACE_DIR` dir represents
the directory where everything goes.

## Step 1

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

#### Build tools

Make sure that you have an up-to-date CMake build and Ninja build. On macOS, you
can [install Homebrew](https://brew.sh/) and run the following:

```shell
brew install ninja cmake graphviz xdot
```

An alternative is to [download](https://cmake.org/download/) and install CMake
from the official website.

### Linux

```shell
sudo apt-get update
sudo apt-get install build-essential ninja-build cmake graphviz xdot clang-17
```

Make sure to check `cmake --version`. You need at least CMake version 3.28.

## Step 2: Environment

```shell
mkdir -p "${WORKSPACE_DIR}/build"
mkdir -p "${WORKSPACE_DIR}/src"
mkdir -p "${WORKSPACE_DIR}/install"
```

Set virtual environment for Python:

```shell
if [[ ! -f "${WORKSPACE_DIR}/install/bin/activate" ]]; then
  python3.12 -m venv "${WORKSPACE_DIR}/install"
fi
source "${WORKSPACE_DIR}/install/bin/activate"
```

You should use at least Python 3.12 because of its support for subinterpreters.

## Step 3: Download and build Multiplier

**Note:** Multiplier will download and build most/all of its dependencies during
CMake's configuration stage, unless you specify otherwise. Thus, you *do not*
need to recursively initialize/clone its submodules.

```shell
cd "${WORKSPACE_DIR}/src"
git clone git@github.com:trailofbits/multiplier.git
```

### Configuring

#### macOS

You are *strongly* recommended to use Apple Clang (`/usr/bin/clang`) to build
Multiplier, and not whatever version of Clang was built/installed by Homebrew.

```shell
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX="${WORKSPACE_DIR}/install" \
  -DCMAKE_C_COMPILER=/usr/bin/clang \
  -DCMAKE_CXX_COMPILER=/usr/bin/clang++ \
  -DMX_ENABLE_INSTALL=ON \
  -DMX_ENABLE_PYTHON_BINDINGS=ON \
  -GNinja \
  "${WORKSPACE_DIR}/src/multiplier"
```

#### Linux

```shell
cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="${WORKSPACE_DIR}/install" \
    -DCMAKE_EXE_LINKER_FLAGS="--ld-path=$(which ld.lld-17)" \
    -DCMAKE_MODULE_LINKER_FLAGS="--ld-path=$(which ld.lld-17)" \
    -DCMAKE_SHARED_LINKER_FLAGS="--ld-path=$(which ld.lld-17)" \
    -DCMAKE_C_COMPILER="$(which clang-17)" \
    -DCMAKE_CXX_COMPILER="$(which clang++-17)" \
    -DMX_ENABLE_INSTALL=ON \
    -DMX_ENABLE_PYTHON_BINDINGS=ON \
    -GNinja \
    "${WORKSPACE_DIR}/src/multiplier"
```

### Build & Install

```shell
ninja install
```