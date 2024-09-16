#
# Copyright (c) 2023-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

string(TOLOWER "${PROJECT_NAME}" lower_project_name)

include("${PROJECT_SOURCE_DIR}/cmake/python.cmake")

# Get the ABI extension. Native Python modules must be named with this
# extension.
get_python_extension_suffix(python_module_extension)

file(GLOB_RECURSE generated_sources CONFIGURE_DEPENDS RELATIVE_PATH "${CMAKE_CURRENT_LIST_DIR}/Generated" "*.cpp")

add_library("mx-python" SHARED
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
  "QualifiedNameRenderOptions.cpp"
  "SharedPyPtr.h"
  "TokenTreeVisitor.h"
  "TokenTreeVisitor.cpp"
  "Types.cpp"  # Auto-generated.
  "Types.h"
  "UserToken.cpp"
)

target_compile_definitions("mx-python"
  PUBLIC
    $<BUILD_INTERFACE:MX_BUILD>
)

set(site_packages_dir "python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/site-packages")

set_target_properties("mx-python"
  PROPERTIES
    LINKER_LANGUAGE
      CXX
    PUBLIC_HEADER
      "${PROJECT_SOURCE_DIR}/include/${lower_project_name}/Bindings/Python.h"
    VISIBILITY_INLINES_HIDDEN
      YES
    CXX_VISIBILITY_PRESET
      hidden
    POSITION_INDEPENDENT_CODE
      YES
    COMPILE_FEATURES
      "cxx_std_${CMAKE_CXX_STANDARD}"
    INTERFACE_COMPILE_FEATURES
      "cxx_std_${CMAKE_CXX_STANDARD}"

    # Make sure we have the right output name, e.g.
    # `multiplier.cpython-312-darwin.so`.
    OUTPUT_NAME
      "${lower_project_name}${python_module_extension}"

    # Remove `lib` prefix.
    PREFIX
      ""

    # Remove `.dylib` or `.so` suffix, the `${python_module_extension}` has the
    # right stuff.
    SUFFIX
      ""

    # NOTE(pag): This is important! We need to emulate the shape of the
    #            install directories, so that install targets behave in the
    #            same way to local build targets w.r.t. shared library
    #            resolution. This places `libmultiplier.so` in the `lib/` sub-
    #            directory, where we also place copies of `libLTO.so` and
    #            `libRemarks.so`. This mirrors the organization inside of
    #            `<install-prefix>/lib`. This same-shapedness is necessary for
    #            how we fiddle with the RPATH, and do symlinking for Python
    #            extensions.
    LIBRARY_OUTPUT_DIRECTORY
      "${PROJECT_BINARY_DIR}/lib/${site_packages_dir}"
)

target_include_directories("mx-python"
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${MX_INSTALL_INCLUDE_DIR}>
  PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}"
)

target_link_libraries("mx-python"
  PUBLIC
    Python3::Python
    "gap::gap"
    "gap::gap-core"
    "gap::gap-settings"
    "std::coroutines"
    "$<BUILD_INTERFACE:mx-api>"
)

# Slightly horrible way of "installing" multiplier as a Python extension, that
# directly invents the relevant files into a `site-packages` directory.
if(MX_ENABLE_INSTALL AND NOT MX_ENABLE_BOOTSTRAP)

  # Copy our stubs into the install site-packages dir. This will also create
  # the installation site-packages directory.
  install(
    DIRECTORY
      "${CMAKE_CURRENT_LIST_DIR}/${lower_project_name}-stubs"
    DESTINATION
      "${CMAKE_INSTALL_PREFIX}/${MX_INSTALL_LIB_DIR}/${site_packages_dir}"
  )

  # Install the binary into the target site-packages directory.
  install(
    TARGETS
      "mx-python"
    EXPORT
      "${PROJECT_NAME}Targets"
    LIBRARY
      DESTINATION
        "${MX_INSTALL_LIB_DIR}/${site_packages_dir}"
    PUBLIC_HEADER
      DESTINATION
        "${MX_INSTALL_INCLUDE_DIR}/${lower_project_name}/Bindings"
  )
endif()
