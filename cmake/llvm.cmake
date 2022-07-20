#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

function(find_llvm target_name)

  find_package(LLVM CONFIG REQUIRED)
  
  add_library("${target_name}" INTERFACE)
  target_include_directories("${target_name}" SYSTEM INTERFACE
    $<BUILD_INTERFACE:${LLVM_INCLUDE_DIRS}>
  )
  target_compile_definitions("${target_name}" INTERFACE
    ${LLVM_DEFINITIONS}
  )
  
  # Go find only the static libraries of LLVM, and link against those.
  foreach(LLVM_LIB IN LISTS LLVM_AVAILABLE_LIBS)
    get_target_property(LLVM_LIB_TYPE ${LLVM_LIB} TYPE)
    if(LLVM_LIB_TYPE STREQUAL "STATIC_LIBRARY")
      list(APPEND LLVM_LIBRARIES "${LLVM_LIB}")
    endif()
  endforeach()
  
  # These are out-of-order in `LLVM_AVAILABLE_LIBS` and should always be last.
  list(REMOVE_ITEM LLVM_LIBRARIES LLVMMC LLVMCore LLVMSupport)
  list(APPEND LLVM_LIBRARIES LLVMMC LLVMCore LLVMSupport)
  
  target_link_libraries("${target_name}" INTERFACE
    ${LLVM_LIBRARIES}
  )

endfunction(find_llvm)

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
    endif()
  endforeach(file_i)

endfunction()
