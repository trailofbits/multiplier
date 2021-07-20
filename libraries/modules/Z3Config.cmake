include("${CMAKE_CURRENT_LIST_DIR}/utils.cmake")

importExternalLibrary("${CMAKE_FIND_PACKAGE_NAME}" "libz3.a;z3" "z3.h")
add_library(z3::libz3 ALIAS thirdparty_z3)
