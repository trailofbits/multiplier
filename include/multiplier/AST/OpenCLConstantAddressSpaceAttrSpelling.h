// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenCLConstantAddressSpaceAttrSpelling : unsigned char {
  KEYWORD_CONSTANT,
  GNU_OPENCL_CONSTANT,
  CXX11_CLANG_OPENCL_CONSTANT,
  C23_CLANG_OPENCL_CONSTANT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLConstantAddressSpaceAttrSpelling) {
  return "OpenCLConstantAddressSpaceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLConstantAddressSpaceAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(OpenCLConstantAddressSpaceAttrSpelling);

} // namespace mx
