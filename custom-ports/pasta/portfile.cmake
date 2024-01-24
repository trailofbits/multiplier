vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO trailofbits/pasta
    REF 828e2e930f6a7b5eeae318bd50023bf6f7a2b85f
    SHA512 7f751c1f4ae90fe378b4f5c1726550d010f35c3cc28e1d92c09054c043ee0ead5886022740f69aa043e36c3f0d30fee6556b35be1ac99cd3ee84d4a4ccc8be7a
    HEAD_REF master
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DPASTA_BOOTSTRAP_MACROS=OFF
        -DPASTA_BOOTSTRAP_TYPES=OFF
        -DPASTA_ENABLE_TESTING=OFF
        -DPASTA_ENABLE_PY_BINDINGS=OFF
        -DPASTA_USE_VENDORED_CLANG=OFF
        -DPASTA_DISABLE_HOST_COMPILER=ON
        -DPASTA_ENABLE_INSTALL=ON
)

vcpkg_cmake_install()
vcpkg_cmake_config_fixup(
    PACKAGE_NAME "pasta"
    CONFIG_PATH lib/cmake/pasta
)
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")