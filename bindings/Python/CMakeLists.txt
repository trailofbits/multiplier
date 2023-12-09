#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

file(GLOB_RECURSE generated_sources CONFIGURE_DEPENDS RELATIVE_PATH "${CMAKE_CURRENT_LIST_DIR}/Generated" "*.cpp")

add_library("mx-python" STATIC
  "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/Bindings/Python.h"

  ${generated_sources}

  "Binding.cpp"
  "Binding.h"
  "Entity.cpp"
  "Error.cpp"
  "Error.h"
  "FileLocationCache.cpp"
  "Forward.h"  # Auto-generated.
  "Module.cpp"  # Auto-generated.
  "SharedPyPtr.h"
  "TokenTreeVisitor.h"
  "TokenTreeVisitor.cpp"
  "Types.cpp"  # Auto-generated.
  "Types.h"
  "UserToken.cpp"
)

set_target_properties("mx-python"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/Bindings/Python.h"
    VISIBILITY_INLINES_HIDDEN
      YES
    CXX_VISIBILITY_PRESET
      default
    POSITION_INDEPENDENT_CODE
      YES
    COMPILE_FEATURES
      cxx_std_20
    INTERFACE_COMPILE_FEATURES
      cxx_std_20
)

target_include_directories("mx-python"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${MX_INSTALL_INCLUDE_DIR}>
  PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}"
)

target_link_libraries("mx-python"
  PUBLIC
    Python3::Python
  PRIVATE
    "mx-api"
)

# This is a horrible way of "installing" libmultiplier as a Python extension.
if(MX_ENABLE_INSTALL AND NOT MX_ENABLE_BOOTSTRAP)
  include("${PROJECT_SOURCE_DIR}/cmake/python.cmake")
  
  # Get the ABI extension. Native Python modules must be named with this
  # extension.
  get_python_extension_suffix(python_module_extension)

  # Figure out where the installation `site-packages` directory is.
  set(site_packages_dir "${CMAKE_INSTALL_PREFIX}/${MX_INSTALL_LIB_DIR}/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/site-packages")
  
  # Make sure the `site-packages` directory exists in the installation directory.
  # This also copies over the stubs.
  install(
    DIRECTORY
      "${CMAKE_CURRENT_LIST_DIR}/multiplier-stubs"
    DESTINATION
      "${site_packages_dir}"
  )

  # Do the install, which creates a symlink to our main `libmultiplier.so` target.
  # We rely on the following directory hierarchy:
  #
  #     <prefix>/lib/libmultiplier.so
  #     <prefix>/lib/python<major>.<minor>/site-packages/multiplier<abi-extension>
  #
  # So then the `../../` relative symbolic link goes and references the
  # `libmultiplier.so` shared library.
  install(
    CODE
      "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E create_symlink \"../../$<TARGET_FILE_NAME:multiplier>\" \"multiplier${python_module_extension}\" WORKING_DIRECTORY \"${site_packages_dir}\")"
  )
endif()
