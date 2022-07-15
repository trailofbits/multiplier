#!/usr/bin/env bash
#
# Copyright (c) 2022 Trail of Bits, Inc.
#

SCRIPTS_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
SRC_DIR=$( cd "$( dirname "${SCRIPTS_DIR}" )" && pwd )
WORKSPACE_DIR=$( cd "$( dirname "${SRC_DIR}" )" && pwd )

# Update GITHUB_ORG to trailofbits repos
GITHUB_ORG=git@github.com:trailofbits
#
# https://vspells.ext.bbn.com/trail-of-bits/pasta.git
# GITHUB_ORG=https://vspells.ext.bbn.com/trail-of-bits
CXX_COMMON_URL="https://github.com/lifting-bits/cxx-common/releases/download"
CXX_COMMON_VERSION="v0.2.8"
LLVM_VERSION="llvm-14"
CMAKE_VERSION_MIN=3.19

OS_VERSION=
ARCH_VERSION=
LIBRARY_VERSION=
VCPKG_TARGET_TRIPLET=

ADD_ARGS=()

# Variables to build the project
BUILD_TYPE=Release
CORE_COUNT=$(nproc --all)

# Help function
function Help
{
  echo "Usage: ./build_multiplier.sh [--workspace-dir DIR] [...]"
  echo ""
  echo "Options:"
  echo "  --workspace-dir <DIR>"
  echo "     Workspace directory"
  echo ""
  echo "  [...]"
  echo "     Extra args to pass"
}

# Get ubuntu version
function GetUbuntuOSVersion
{
  source /etc/lsb-release
  case "${DISTRIB_RELEASE}" in
    20.04)
      OS_VERSION=ubuntu-20.04
      return 0
    ;;
    *)
      echo "[!] Ubuntu ${DISTRIB_RELEASE} is not supported; using libraries for Ubuntu 20.04 instead"
      OS_VERSION=ubuntu-20.04
      return 0
    ;;
  esac
}

# Get cmake version
function CheckCMakeVersionMin
{
  local cmake_version=$(cmake --version | head -n1 | cut -d" " -f3)
  if [[ "$cmake_version" < "${CMAKE_VERSION_MIN}" ]]; then
    echo "[!] Minimum cmake required version is ${CMAKE_VERSION_MIN}. Exiting!"
    exit 1
  fi
}

# Get Architecture version
function GetArchVersion
{
  local version
  version="$(uname -m)"

  case "${version}" in
    x86_64)
      ARCH_VERSION=amd64
      ARCH_TARGET_TRIPLET=x64
      return 0
    ;;
    x86-64)
      ARCH_VERSION=amd64
      ARCH_TARGET_TRIPLET=x64
      return 0
    ;;
    arm64)
      ARCH_VERSION=arm64
      ARCH_TARGET_TRIPLET=arm64
      return 0
    ;;
    aarch64)
      ARCH_VERSION=arm64
      ARCH_TARGET_TRIPLET=arm64
      return 0
    ;;
    *)
      echo "[!] ${version} architecture is not supported."
      return 1
    ;;
  esac
}

# Download vcpkg and install it in workspace directory
function DownloadVcpkg
{
  local workspace=$1

  if ! GetArchVersion; then
    echo "[!] Failed to get architecture type"
    return 1
  fi

  # get macOS package name
  if [[ "${OSTYPE}" = "darwin"* ]]; then
    OS_VERSION="macos-11"
    XCODE_VERSION="13.0"

    VCPKG_TARGET_TRIPLET="${ARCH_TARGET_TRIPLET}-osx-rel"
    LIBRARY_VERSION="vcpkg_${OS_VERSION}_${LLVM_VERSION}_xcode-${XCODE_VERSION}_${ARCH_VERSION}"
  elif [[ "${OSTYPE}" = "linux-gnu" ]]; then
    if ! GetUbuntuOSVersion; then
      return 1
    fi

    VCPKG_TARGET_TRIPLET="${ARCH_TARGET_TRIPLET}-linux-rel"
    LIBRARY_VERSION="vcpkg_${OS_VERSION}_${LLVM_VERSION}_${ARCH_VERSION}"
  else
    echo "[x] OS ${OSTYPE} is not supported."
    return 1
  fi

  echo "[+] Library version is ${LIBRARY_VERSION}"

  local url="${CXX_COMMON_URL}/${CXX_COMMON_VERSION}/${LIBRARY_VERSION}.tar.xz"
  (
    set -x
    if [[ ! -f "${workspace}/$(basename $url)" ]]; then
      wget "${url}" -P "${workspace}"
      tar -xf "${workspace}/$(basename $url)" --directory ${workspace}
      rm -rf ${VCPKG_ROOT}
      mv "${workspace}/$(sed 's/.\{7\}$//' <<< $(basename $url))" ${VCPKG_ROOT}
    fi
  ) || return $?
}

# Set python virtual envionment
function SetupVirtualEnv
{
  local workspace=$1
  if [[ ! -f "${workspace}/install/bin/activate" ]]; then
    python3 -m venv "${workspace}/install"
  fi
  source "${workspace}/install/bin/activate"
}

function InstallDependencies
{
  echo "[+] Installing dependencies!"

  if [[ "${OSTYPE}" = "darwin"* ]]; then
    brew install qt@5 rustup python3
    cargo install cbindgen
    export PATH=${PATH}:${HOME}/.cargo/bin
  elif [[ "${OSTYPE}" = "linux-gnu" ]]; then
    sudo_cmd=""
    if groups ${USER} | grep "\<sudo\>" &> /dev/null; then
      echo "[+] Need sudo permission to install dependecies!"
      sudo_cmd="sudo"
    fi

    ${sudo_cmd} apt install -yq qtcreator gcc-10 g++-10 \
      qt5-default cargo clang lld clang-tools \
      python3-dev
    cargo install cbindgen
    export PATH=${HOME}/.cargo/bin:$PATH
  else
    echo "[x] OS ${OSTYPE} is not supported."
    return 1
  fi
}

# Get or update repositories
function GetOrUpdateRepo
{
  (
    set -x
    pushd "${WORKSPACE_DIR}"
    if [[ ! -d "$1" ]]; then
      git clone "${2}" --branch "$3" --recurse-submodules
    else
      pushd "$1"
      git pull
      git checkout "$3"
      popd
    fi
    popd
  ) || return $?
}

# Configure and build the project
function ConfigureAndBuild
{
  local name="$1"
  local build_dir=${WORKSPACE_DIR}/mx-build/${name}
  shift

  if [ -d "$build_dir" ]; then
    rm -Rf $build_dir
  fi

  mkdir -p "$build_dir"
  pushd "$build_dir"

  if [[ "x${CC}x" == "xx" ]]; then
    export CC="${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang"
  fi
  echo "[+] Using C compiler: ${CC}"

  if [[ "x${CXX}x" == "xx" ]]; then
    export CXX="${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/tools/llvm/clang++"
  fi
  echo "[+] Using C++ compiler: ${CXX}"

  echo "[+] Building ${name} ..."
  (
    set -x
    cmake \
      "-DCMAKE_BUILD_TYPE=${BUILD_TYPE}" \
      "-DCMAKE_INSTALL_PREFIX=${WORKSPACE_DIR}/install" \
      "-DCMAKE_C_COMPILER=${CC}" \
      "-DCMAKE_CXX_COMPILER=${CXX}" \
      $@ \
      "${WORKSPACE_DIR}/${name}"
    make install "-j${CORE_COUNT}"
  ) || return $?
  popd
}

# Initialize the repositories name
PASTA_NAME=pasta
PASTA_REPO="${GITHUB_ORG}/${PASTA_NAME}.git"
PASTA_BRANCH="master"

WEGGLI_NATIVE_NAME=weggli-native
WEGGLI_NATIVE_REPO="https://github.com/trailofbits/${WEGGLI_NATIVE_NAME}"
WEGGLI_NATIVE_BRANCH="main"

MULTIPLIER_NAME=multiplier
MULTIPLIER_REPO="${GITHUB_ORG}/${MULTIPLIER_NAME}.git"
MULTIPLIER_BRANCH="main"

# Configure and build multiplier on MacOS
function BuildMultiplierOSX
{
  if !(ConfigureAndBuild "${MULTIPLIER_NAME}" -DMX_DOWNLOAD_SQLITE=ON \
    -DMX_ENABLE_GUI=ON -DMX_ENABLE_WEGGLI=ON  -DMX_ENABLE_VAST=OFF \
    -DVCPKG_ROOT=${VCPKG_ROOT} -DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET} \
    -Dpasta_ROOT="${WORKSPACE_DIR}/install" \
    -DQt5_DIR:PATH=$(brew --prefix)/opt/qt@5/lib/cmake/Qt5 \
    -DQt5Core_DIR:PATH=$(brew --prefix)/opt/qt@5/lib/cmake/Qt5Core \
    -DQt5Widgets_DIR:PATH=$(brew --prefix)/opt/qt@5/lib/cmake/Qt5Widgets); then
    echo "[!] Failed to configure and build multiplier."
    exit 1
  fi
}

# Configure and build multiplier on Linux
function BuildMultiplierLinux
{
  ConfigureAndBuild "${MULTIPLIER_NAME}" -DMX_DOWNLOAD_SQLITE=ON \
    -DMX_ENABLE_GUI=ON -DMX_ENABLE_WEGGLI=ON  -DMX_ENABLE_VAST=OFF \
    -DVCPKG_ROOT=${VCPKG_ROOT} -DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET} \
    -Dpasta_ROOT="${WORKSPACE_DIR}/install"
}


function main
{
  while [[ $# -gt 0 ]]; do
    key="$1"

    case $key in
    -h | --help)
      Help
      exit 0
      ;;
    --workspace-dir)
      WORKSPACE_DIR=$(python3 -c "import os; import sys; sys.stdout.write(os.path.abspath('${2}'))")
      echo "[+] Exporting to directory ${WORKSPACE_DIR}"
      shift # past argument
      ;;
    *)
      ADD_ARGS+=("$1")
      ;;
    esac
    shift
  done
  
  echo "[+] Setting workspace directory to ${WORKSPACE_DIR}"

  VCPKG_ROOT="${WORKSPACE_DIR}/vcpkg-install"

  CheckCMakeVersionMin

  if ! DownloadVcpkg ${WORKSPACE_DIR}; then
    echo "[!] Failed to download vcpkg libraries"
    exit 1
  fi

  # Install dependencies and set python virtual envionment
  InstallDependencies
  SetupVirtualEnv ${WORKSPACE_DIR}

  if ! GetOrUpdateRepo "${PASTA_NAME}" "${PASTA_REPO}" "${PASTA_BRANCH}"; then
    echo "[!] Failed to clone pasta repository"
    exit 1
  fi

  if ! GetOrUpdateRepo "${WEGGLI_NATIVE_NAME}" "${WEGGLI_NATIVE_REPO}" "${WEGGLI_NATIVE_BRANCH}"; then
    echo "[!] Failed to clone weggli-native repository"
    exit 1
  fi

  if ! GetOrUpdateRepo "${MULTIPLIER_NAME}" "${MULTIPLIER_REPO}" "${MULTIPLIER_BRANCH}"; then
    echo "[!] Failed to clone multiplier repository"
  fi
  
  if !(ConfigureAndBuild "${PASTA_NAME}" -DPASTA_BOOTSTRAP_MACROS=OFF \
    -DPASTA_BOOTSTRAP_TYPES=OFF -DPASTA_ENABLE_TESTING=OFF \
    -DVCPKG_ROOT=${VCPKG_ROOT} -DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET}); then
    echo "[!] Failed to configure and build pasta"
    exit 1
  fi
  
  if !(ConfigureAndBuild "${WEGGLI_NATIVE_NAME}"); then
    echo "[!] Failed to configure and build weggli-native"
    exit 1
  fi
    
  if [[ "${OSTYPE}" = "darwin"* ]]; then
    BuildMultiplierOSX
  elif [[ "${OSTYPE}" = "linux-gnu" ]]; then
    BuildMultiplierLinux
  fi
}

main "$@"
exit $?
