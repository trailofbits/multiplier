// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenCLGlobalAddressSpaceAttrSpelling : unsigned char {
  KEYWORD_GLOBAL,
  GNU_OPENCL_GLOBAL,
  CXX11_CLANG_OPENCL_GLOBAL,
  C23_CLANG_OPENCL_GLOBAL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLGlobalAddressSpaceAttrSpelling) {
  return "OpenCLGlobalAddressSpaceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLGlobalAddressSpaceAttrSpelling) {
  return 5;
}

const char *EnumeratorName(OpenCLGlobalAddressSpaceAttrSpelling);

} // namespace mx
