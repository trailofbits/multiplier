#
# Copyright (c) 2023-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

function(get_python_extension_suffix output_var)
  execute_process(
    COMMAND "${Python3_EXECUTABLE}" "-c" "import sysconfig; print(sysconfig.get_config_var('EXT_SUFFIX'))"
    RESULT_VARIABLE ext_suffix_ret
    OUTPUT_VARIABLE ext_suffix
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  if(ext_suffix_ret AND NOT ext_suffix_ret EQUAL 0)
    message(FATAL_ERROR "Python sysconfig query to find 'EXT_SUFFIX' property failed")
  endif()

  set("${output_var}" "${ext_suffix}" PARENT_SCOPE)
endfunction(get_python_extension_suffix)
