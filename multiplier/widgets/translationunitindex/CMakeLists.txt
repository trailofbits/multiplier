#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library(multiplier_tuindex_widget STATIC
  include/multiplier/widgets/itranslationunitindex.h
  src/itranslationunitindex.cpp

  src/translationunitindex.h
  src/translationunitindex.cpp
)

target_include_directories(multiplier_tuindex_widget PRIVATE include)
target_include_directories(multiplier_tuindex_widget SYSTEM INTERFACE include)

target_link_libraries(multiplier_tuindex_widget PRIVATE
  mu_cxx_settings

  pasta::pasta
  TobWidgets

  Qt${MU_QT_VERSION}::Core
  Qt${MU_QT_VERSION}::Widgets
)

target_link_libraries(multiplier_widgets INTERFACE
  multiplier_tuindex_widget
)
