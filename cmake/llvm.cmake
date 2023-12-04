#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

function(find_and_link_llvm_dependency target_name dependency_name)

  if(TARGET "${dependency_name}")
    string(TOUPPER "${CMAKE_BUILD_TYPE}" our_config)
    get_target_property(target_file "${dependency_name}" "IMPORTED_LOCATION_${our_config}")
    if(target_file STREQUAL "target_file-NOTFOUND")
      message(FATAL_ERROR "Could not find imported location of ${dependency_name} for config ${CMAKE_BUILD_TYPE}")
    endif()
  else()
    find_library(found_lib ${dependency_name} REQUIRED HINTS ${LLVM_LIBRARY_DIRS} NO_DEFAULT_PATH)
    cmake_path(ABSOLUTE_PATH found_lib NORMALIZE)
  endif()

  message(STATUS "Found ${dependency_name} library: ${target_file}")

  cmake_path(GET target_file FILENAME target_filename)
  file(REAL_PATH "${target_file}" target_realfile)

  set(dest_lib "${MX_INSTALL_LIB_DIR}/${target_filename}")
  cmake_path(ABSOLUTE_PATH dest_lib NORMALIZE)

  # It's already in the right spot!
  if(target_file STREQUAL dest_lib OR target_realfile STREQUAL dest_lib)
    target_link_libraries("${target_name}" PUBLIC "${dest_lib}")
    return()
  endif()

  set(local_lib "${PROJECT_BINARY_DIR}/lib/${target_filename}")

  add_custom_target(
    "gen-${dependency_name}" ALL DEPENDS "${local_lib}")

  add_custom_command(
    OUTPUT "${local_lib}"
    COMMAND ${CMAKE_COMMAND} -E copy "${target_realfile}" "${local_lib}"
    MAIN_DEPENDENCY "${target_realfile}"
  )

  add_library("mx-${dependency_name}" INTERFACE)
  target_link_libraries("mx-${dependency_name}"
    INTERFACE
      "$<BUILD_INTERFACE:${local_lib}>"
      "$<INSTALL_INTERFACE:${target_filename}>"
  )

  target_link_directories("mx-${dependency_name}"
    INTERFACE
      "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/lib>")

  if(PLATFORM_MACOS)
    find_program(install_name_tool install_name_tool)
    if("${install_name_tool}" STREQUAL "install_name_tool-NOTFOUND")
      message(FATAL_ERROR "Could not find install_name_tool")  
    endif()

    add_custom_command(TARGET "${target_name}"
      COMMAND
        COMMAND "${install_name_tool}" -change "@rpath/${target_filename}" "@loader_path/../lib/${target_filename}" "$<TARGET_FILE:${target_name}>")
  endif()

  if(MX_ENABLE_INSTALL)
    install(
      TARGETS
        "mx-${dependency_name}"
      EXPORT
        "${PROJECT_NAME}Targets"
      LIBRARY
        DESTINATION
          "${MX_INSTALL_LIB_DIR}"
    )

    install(
      FILES
        "${local_lib}"
      DESTINATION
        "${MX_INSTALL_LIB_DIR}"
    )
  endif()

  target_link_libraries("${target_name}" PUBLIC "mx-${dependency_name}")

endfunction(find_and_link_llvm_dependency)

# Find libLTO.so or libLTO.dylib. LLVM relies on these, and LLVM is used in
# PASTA, which is used in mx-index and libmultipllier.so (if VAST is used).
# We might be dealing with a vendored LLVM, so we need to find its libLTO.so
# and other files, and move them to Multiplier's install dir.
function(find_and_link_llvm_dependencies target_name)
  find_and_link_llvm_dependency("${target_name}" LTO)
  find_and_link_llvm_dependency("${target_name}" Remarks)
endfunction()
