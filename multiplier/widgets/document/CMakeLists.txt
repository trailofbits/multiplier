#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_library(multiplier_document_widget STATIC
  include/multiplier/widgets/idocument.h

  src/sourcecodemodel.h
  src/sourcecodemodel.cpp

  src/astbuilder.h
  src/astbuilder.cpp

  src/astindex.h
  src/astindex.cpp

  src/document.h
  src/document.cpp

  src/parsedfilesindex.h
  src/parsedfilesindex.cpp
)

target_include_directories(multiplier_document_widget PRIVATE include)
target_include_directories(multiplier_document_widget SYSTEM INTERFACE include)

target_link_libraries(multiplier_document_widget PRIVATE
  mu_cxx_settings

  pasta::pasta
  TobWidgets

  Qt${MU_QT_VERSION}::Core
  Qt${MU_QT_VERSION}::Widgets
)

target_link_libraries(multiplier_widgets INTERFACE
  multiplier_document_widget
)