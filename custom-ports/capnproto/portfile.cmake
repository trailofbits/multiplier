vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO capnproto/capnproto
    REF f5531718b95c2ad4fcedc624e0d46866455007f4
    SHA512 255c7a630096c322056775f98336df8d6ab0fb967226d9fca3db6c997dcb4e5580c9e3041aece7c7623ea006f2d857dea348399c9cc869ac8414cdfa36714a75
    HEAD_REF master
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DCAPNP_LITE=OFF
        -DEXTERNAL_CAPNP=OFF
        -DBUILD_TESTING=OFF
        -DWITH_ZLIB=AUTO
        -DWITH_OPENSSL=AUTO
        -DWITH_FIBERS=OFF
)

vcpkg_cmake_install()