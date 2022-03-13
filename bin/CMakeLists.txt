#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

if(MX_ENABLE_BOOTSTRAP)
  add_subdirectory("Bootstrap")
endif()

add_subdirectory("Import")
add_subdirectory("Index")
  
if(MX_ENABLE_GUI)
  add_subdirectory("GUI")
endif(MX_ENABLE_GUI)
