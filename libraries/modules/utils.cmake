#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

include(FindPackageHandleStandardArgs)

function(importSubmodule)
  set(directory_path "${CMAKE_CURRENT_LIST_DIR}/../${CMAKE_FIND_PACKAGE_NAME}")

  add_subdirectory(
    "${directory_path}"
    "${PROJECT_BINARY_DIR}/libraries/${CMAKE_FIND_PACKAGE_NAME}"
  )

  get_property(target_list DIRECTORY "${directory_path}" PROPERTY BUILDSYSTEM_TARGETS)
  list(LENGTH target_list target_count)

  if(NOT ${target_count} EQUAL 0)
    set("${CMAKE_FIND_PACKAGE_NAME}_LIBRARIES" "${target_list}")
  endif()

  find_package_handle_standard_args("${CMAKE_FIND_PACKAGE_NAME}" DEFAULT_MSG
    "${CMAKE_FIND_PACKAGE_NAME}_LIBRARIES"
  )
endfunction()

function(importExternalLibraryHelper package_name library_name_list header_name)
  set(target_name "thirdparty_${package_name}")
  string(TOLOWER "${target_name}" target_name)

  set(libraries_var_name "${package_name}_LIBRARIES")
  find_library("${libraries_var_name}" NAMES ${library_name_list}
    PATH_SUFFIXES "usr/lib" "lib"
  )

  if("${libraries_var_name}" STREQUAL "${package_name}_LIBRARIES-NOTFOUND")
    return()
  endif()

  set(includedir_var_name "${package_name}_INCLUDE_DIR")
  find_path("${includedir_var_name}" NAMES "${header_name}")
  if("${includedir_var_name}" STREQUAL "${package_name}_INCLUDE_DIR-NOTFOUND")
    return()
  endif()

  add_library("${target_name}" UNKNOWN IMPORTED GLOBAL)
  set_target_properties("${target_name}" PROPERTIES
    IMPORTED_LOCATION
      "${${libraries_var_name}}"

    INTERFACE_INCLUDE_DIRECTORIES
      "${${includedir_var_name}}"
  )
endfunction()

function(importExternalLibrary package_name library_name_list header_name)
  importExternalLibraryHelper("${package_name}" "${library_name_list}" "${header_name}")

  set(libraries_var_name "${package_name}_LIBRARIES")
  set(includedir_var_name "${package_name}_INCLUDE_DIR")

  find_package_handle_standard_args("${package_name}" DEFAULT_MSG
    "${libraries_var_name}"
    "${includedir_var_name}"
  )
endfunction()
