// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenCLGenericAddressSpaceAttrSpelling : unsigned char {
  KEYWORD_GENERIC,
  GNU_OPENCL_GENERIC,
  CXX11_CLANG_OPENCL_GENERIC,
  C23_CLANG_OPENCL_GENERIC,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLGenericAddressSpaceAttrSpelling) {
  return "OpenCLGenericAddressSpaceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLGenericAddressSpaceAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(OpenCLGenericAddressSpaceAttrSpelling);

} // namespace mx
