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

##### Build tools

Make sure that you have an up-to-date CMake build and Ninja build. On macOS, you
can [install Homebrew](https://brew.sh/) and run the following:

```shell
brew install ninja cmake graphviz xdot
```

An alternative is to [download](https://cmake.org/download/) and install CMake from
the official website.

#### Linux

```shell
sudo apt-get update
sudo apt-get install build-essential ninja-build cmake graphviz xdot gcc g++
```

### Step 2

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

### Step 3: Download and build Multiplier

**Note:** Multiplier will download and build most/all of its dependencies during
CMake's configuration stage, unless you specify otherwise.

```shell
cd "${WORKSPACE_DIR}/src"
git clone git@github.com:trailofbits/multiplier.git
```

```shell
mkdir -p "${WORKSPACE_DIR}/build/multiplier"
cd "${WORKSPACE_DIR}/build/multiplier"
cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX="${WORKSPACE_DIR}/install" \
  -DMX_ENABLE_BOOTSTRAP=OFF \
  -DMX_BOOTSTRAP_VAST=OFF \
  -DMX_BOOTSTRAP_PASTA=OFF \
  -DMX_ENABLE_RE2=ON \
  -DMX_ENABLE_INSTALL=ON \
  -GNinja \
  "${WORKSPACE_DIR}/src/multiplier"

ninja install
```
