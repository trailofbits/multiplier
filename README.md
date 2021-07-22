# Multiplier

### Building

#### Step 1

Set up your environment.

```bash
export MU_SRC_DIR=/Users/pag/Code/multiplier
export MU_BUILD_DIR=/Users/pag/Build/multiplier-release
export MU_INSTALL_PREFIX=/Users/pag/Build/install-release
```

Create a virtual environment for your installations.

```bash
python3 -m venv --system-site-packages "${MU_INSTALL_PREFIX}"
source "${MU_INSTALL_PREFIX}/bin/activate"
```

Clone the code.

```
git clone git@github.com:trailofbits/multiplier.git "${MU_SRC_DIR}"
```

Create the build directory.

```bash
mkdir -p "${MU_BUILD_DIR}"
```

Download the [latest release](https://github.com/lifting-bits/cxx-common/releases/)
of cxx-common for LLVM 12 that is associated with your platform. Extract the
cxx-common build into the directory `VCPKG_ROOT`.

```bash
export VCPKG_ROOT=/path/to/extracted/release
export VCPKG_TARGET_TRIPLET=x64-osx-rel
```

Download and install the Qt5 SDK.

```bash
export QT_SDK_ROOT=/Users/pag/Qt5.12.11/5.12.11/clang_64/
```

#### Step 2

Configure the build. Be sure to specify an absolute path to the Clang compiler.

```bash
cd "${MU_BUILD_DIR}"
cmake \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DCMAKE_INSTALL_PREFIX="${MU_INSTALL_PREFIX}" \
  -DVCPKG_ROOT="${VCPKG_ROOT}" \
  -DVCPKG_TARGET_TRIPLET="${VCPKG_TARGET_TRIPLET}" \
  -DQt5_DIR:PATH="${QT_SDK_ROOT}/lib/cmake/Qt5" \
  -DQt5Core_DIR:PATH="${QT_SDK_ROOT}/lib/cmake/Qt5Core" \
  -DQt5Widgets_DIR:PATH="${QT_SDK_ROOT}/lib/cmake/Qt5Widgets" \
  -DCMAKE_C_COMPILER=`which clang` \
  -DCMAKE_CXX_COMPILER=`which clang++` \
  "${MU_SRC_DIR}"
```

#### Step 3

Build the code.

```bash
make install -j12
```