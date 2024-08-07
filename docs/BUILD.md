# Building Multiplier

Building Multiplier from scratch can take a long time, so prepare yourself. You
will need a modern Clang (18+) and CMake (3.30+) to build Multiplier, as it
relies on modern C++ and CMake features.

* [Step 0](#step-0)
  + [Dependencies](#dependencies)
* [Step 1](#step-1)
  + [macOS](#macos)
    - [XCode](#xcode)
    - [Build tools](#build-tools)
  + [Linux](#linux)
    - [Clang](#clang)
    - [CMake](#cmake)
    - [Python](#python)
* [Step 2: Environment](#step-2--environment)
* [Step 3: Download and build Multiplier](#step-3--download-and-build-multiplier)
  + [Configuring](#configuring)
    - [macOS](#macos-1)
    - [Linux](#linux-1)
  + [Build & Install](#build---install)

## Step 0

Going forward, we assume the environment variable `WORKSPACE_DIR` dir represents
the directory where everything goes.

### Dependencies

| Name | Version |
| ---- | ------- |
| [Git](https://git-scm.com/) | Latest |
| [CMake](https://cmake.org/) | 3.30+ |
| [Clang](http://clang.llvm.org/) | 18+ |
| [Python](https://www.python.org/) | 3.12+ |

## Step 1

### macOS

#### XCode

Make sure that you have an up-to-date XCode. At a command line, you should be able
to run `clang --version` and see something like this:

```shell
% clang --version
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: arm64-apple-darwin23.5.0
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
sudo apt update
sudo apt install build-essential ninja-build cmake graphviz xdot
```

#### Clang

If you can't `sudo apt-get install clang-18`, then try the following:

```shell
sudo apt install lsb_release

curl -sSL https://apt.llvm.org/llvm-snapshot.gpg.key | \
  gpg --dearmor - | \
  sudo tee /etc/apt/trusted.gpg.d/llvm.gpg

sudo apt-add-repository "deb https://apt.llvm.org/$(lsb_release -cs)/ llvm-toolchain-$(lsb_release -cs)-${LLVM_VER} main"

sudo apt install clang-18
```

#### CMake

If you don't already have CMake 3.30+, and if your installed `cmake --version`
reports a smaller version number, then try the following:

```shell
curl -sSL https://apt.kitware.com/keys/kitware-archive-latest.asc | \
    gpg --dearmor - | \
    sudo tee /etc/apt/trusted.gpg.d/kitware.gpg

sudo apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 6AF7F09730B3F0A4
sudo apt update
sudo apt install kitware-archive-keyring
sudo apt install cmake
```

#### Python

You will need to have the Python headers and libraries installed, ideally for
Python 3.12+. Python 3.11 should also work, but other uses of Multiplier's
Python API may prefer 3.12+ due to its support for subinterpreters.

```shell
sudo apt install python3.12-dev
```

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
    -DCMAKE_LINKER_TYPE=LLD \
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