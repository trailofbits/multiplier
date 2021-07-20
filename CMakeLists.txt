cmake_minimum_required(VERSION 3.21.0)
project("multiplier")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_subdirectory("libraries")
add_subdirectory("multiplier")
