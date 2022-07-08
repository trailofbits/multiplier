#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

function(qt_deploy_target target_name target_bundle_path)
  if(NOT TARGET "${target_name}")
    message(FATAL_ERROR "Target ${target_name} is not (yet) defined")
  endif()

  get_target_property(target_binary_dir "${target_name}" BINARY_DIR)
  if(NOT target_binary_dir)
    message(FATAL_ERROR "Failed to acquire the BINARY_DIR property from target ${target_name}")
  endif()

  get_target_property(target_output_name "${target_name}" OUTPUT_NAME)
  if(NOT target_output_name)
    set(target_output_name "${target_name}")
  endif()

  if(NOT TARGET "qt_deploy")
    add_custom_target("qt_deploy")
  endif()
  
  if(NOT "x${Qt6_DIR}x" STREQUAL "xx")
    get_filename_component(qt_cmake_dir "${Qt6_DIR}" DIRECTORY)
  elseif(NOT "x${Qt5_DIR}x" STREQUAL "xx")
    get_filename_component(qt_cmake_dir "${Qt5_DIR}" DIRECTORY)
  else()
    message(FATAL_ERROR "Failed to find ${MX_QT}_Dir")
  endif()
  
  
  get_filename_component(qt_lib_dir "${qt_cmake_dir}" DIRECTORY)
  get_filename_component(qt_root_dir "${qt_lib_dir}" DIRECTORY)
  find_program(macdeployqt_path "macdeployqt" HINTS "${qt_root_dir}/bin")
  
  if(NOT macdeployqt_path)
    message(WARNING "The macdeployqt executable was not found")
    return()
  endif()

  set(runner_target_name "qt_deploy_${target_name}")
  set(output_file_name "${target_name}.dmg")
  set(output_path "${target_binary_dir}/${output_file_name}")

  add_custom_command(
    OUTPUT "${output_path}"
    DEPENDS "${target_name}"
    COMMAND "${macdeployqt_path}" "${target_bundle_path}" -verbose=2 -dmg -always-overwrite
    COMMENT "Running macdeployqt on target ${target_name}..."
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    VERBATIM
  )

  add_custom_target("${runner_target_name}"
    DEPENDS "${output_path}"
  )

  add_dependencies(
    "qt_deploy"
    "${runner_target_name}"
  )
endfunction()

