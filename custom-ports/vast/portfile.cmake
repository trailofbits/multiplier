vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO trailofbits/vast
    REF 7432a1f9858c355bf35f82635def58fe26a3a9b0
    SHA512 922c39ba2772ee74e84b9918abb414997f10a7204b25f3726cf5ac4797aaa3e8e06cc907f1b9d05b774bd48fc53fe0ad2b4c1df36f2c37445545c1f34ece3592
    HEAD_REF master
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON
        -DVAST_ENABLE_GAP_SUBMODULE=FALSE
        -DVAST_WARNINGS_AS_ERRORS=FALSE
        -DVAST_ENABLE_TESTING=OFF
)

vcpkg_cmake_install()
vcpkg_cmake_config_fixup()
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")