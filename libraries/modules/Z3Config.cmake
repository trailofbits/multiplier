#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

include("${CMAKE_CURRENT_LIST_DIR}/utils.cmake")

importExternalLibrary("${CMAKE_FIND_PACKAGE_NAME}" "libz3.a;z3" "z3.h")
add_library(z3::libz3 ALIAS thirdparty_z3)
