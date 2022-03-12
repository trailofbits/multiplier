#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(exe_name "mx-bootstrap")

add_executable("${exe_name}"
  Main.cpp
)

set_target_properties("${exe_name}"
  PROPERTIES
    LINKER_LANGUAGE
      CXX)

target_link_libraries("${exe_name}"
  PRIVATE
    pasta::pasta
)
