cmake_minimum_required(VERSION 3.19)

# Takes care of some vcpkg automation so that we can use VCPKG_ROOT
include(cmake/vcpkg_helper.cmake)

project("multiplier")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

option(MU_FIND_PASTA "Should we try to find PASTA as an installed package, or build the submodule?" OFF)

add_subdirectory("libraries")
add_subdirectory("multiplier")
