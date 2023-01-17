#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

# Install libraries for the target
function(install_library target_name library_path)

  add_custom_target(
    ${target_name} ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/lib/${target_name})

  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/lib/${target_name}
    COMMAND ${CMAKE_COMMAND} -E copy ${library_path} "${CMAKE_CURRENT_BINARY_DIR}/lib/${target_name}"
  )

  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/lib/${file_name}
      DESTINATION
        ${CMAKE_INSTALL_LIBDIR}
  )

endfunction(install_library)

# Find libLTO.so or libLTO.dylib. LLVM relies on these, and LLVM is used in
# PASTA, which is used in mx-index and mx-import
function(find_and_install_llvm_dependencies)

  find_library(LIB_LTO LTO REQUIRED)
  message(STATUS "Found LTO library: ${LIB_LTO}")
  get_filename_component(lib_lto_name "${LIB_LTO}" NAME)
  file(GLOB lib_lto_list ${LIB_LTO}*)

  find_library(LIB_REMARKS Remarks REQUIRED)
  message(STATUS "Found Remarks library: ${LIB_REMARKS}")
  get_filename_component(lib_remarks_name "${LIB_REMARKS}" NAME)
  file(GLOB lib_remarks_list ${LIB_REMARKS}*)

  set(library_files ${lib_lto_list} ${lib_remarks_list})

  foreach(file_i ${library_files})
    get_filename_component(file_name "${file_i}" NAME)
    if (NOT TARGET ${file_name})
      install_library(${file_name} ${file_i})
    endif ()
  endforeach(file_i)

endfunction()
