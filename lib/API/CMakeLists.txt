#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

set(source_include_dir "${PROJECT_SOURCE_DIR}/include/${lower_project_name}")
set(binary_include_dir "${PROJECT_BINARY_DIR}/include/${lower_project_name}")

set(api_headers
  "${source_include_dir}/AST.h"
  "${source_include_dir}/File.h"
  "${source_include_dir}/Fragment.h"
  "${source_include_dir}/Index.h"
  "${source_include_dir}/Iterator.h"
  "${source_include_dir}/Compress.h"
  "${source_include_dir}/Query.h"
  "${source_include_dir}/Reference.h"
  "${source_include_dir}/Result.h"
  "${source_include_dir}/Token.h"
  "${source_include_dir}/Use.h"
  "${MX_BOOTSTRAP_INCLUDE_VISITOR_INC_H}"
)

add_library("mx-api"
  STATIC
    ${api_headers}

    "${MX_BOOTSTRAP_LIB_API_AST_CPP}"  # Auto-generated
    
    "API.cpp"
    "API.h"
    "CachingEntityProvider.cpp"
    "CachingEntityProvider.h"
    "FileList.cpp"
    "File.cpp"
    "File.h"
    "Fragment.cpp"
    "FragmentImpl.cpp"
    "Fragment.h"
    "Index.cpp"
    "InvalidEntityProvider.cpp"
    "InvalidEntityProvider.h"
    "PackedFileImpl.cpp"
    "PackedFragmentImpl.cpp"
    "Re2.cpp"
    "Re2.h"
    "RemoteEntityProvider.cpp"
    "RemoteEntityProvider.h"
    "TokenContext.cpp"
    "TokenSubstitution.cpp"
    "Token.cpp"
    "Token.h"
    "Use.cpp"
    "Use.h"
    "Weggli.cpp"
    "Weggli.h"
    "Re2.cpp"
    "Re2.h"
)

target_link_libraries("mx-api"
  PUBLIC
    "mx-common"
)

set_target_properties("mx-api"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${api_headers}"
    VISIBILITY_INLINES_HIDDEN
      YES
    CXX_VISIBILITY_PRESET
      hidden
    POSITION_INDEPENDENT_CODE
      YES
)

target_compile_definitions("mx-api"
  PRIVATE
    "MX_ENABLE_API")

target_include_directories("mx-api"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

if(MX_ENABLE_INSTALL)
  install(
    TARGETS
      "mx-api"
    EXPORT "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
    LIBRARY
      DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE
      DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER
      DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/${lower_project_name}"
  )
endif(MX_ENABLE_INSTALL)
