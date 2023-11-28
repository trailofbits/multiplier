// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenCLLocalAddressSpaceAttrSpelling : unsigned char {
  KEYWORD_LOCAL,
  GNU_OPENCL_LOCAL,
  CXX11_CLANG_OPENCL_LOCAL,
  C2X_CLANG_OPENCL_LOCAL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLLocalAddressSpaceAttrSpelling) {
  return "OpenCLLocalAddressSpaceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLLocalAddressSpaceAttrSpelling) {
  return 5;
}

const char *EnumeratorName(OpenCLLocalAddressSpaceAttrSpelling);

} // namespace mx
