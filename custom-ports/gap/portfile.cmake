vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO lifting-bits/gap
    REF ad8fefaf7235a9cd6670e272ca4487807ed81f8a
    SHA512 9e9259fd4c3c96e31965613092f7dec9df5e236aa4ef9ac122378fe1708d4efd2fb6bd9837530e8474646dc3b0aa409781fd6f45fc28929d07bb54a95a072566
    HEAD_REF main
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DGAP_ENABLE_TESTING=OFF
        -DGAP_ENABLE_EXAMPLES=OFF
        -DGAP_ENABLE_COROUTINES=ON
        -DGAP_ENABLE_WARNINGS=OFF
        -DGAP_INSTALL=ON
)

vcpkg_cmake_install()
vcpkg_cmake_config_fixup(
    PACKAGE_NAME "gap"
    CONFIG_PATH lib/cmake/gap
)
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/lib")