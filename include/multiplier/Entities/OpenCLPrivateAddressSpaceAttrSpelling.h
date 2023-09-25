// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenCLPrivateAddressSpaceAttrSpelling : unsigned char {
  KEYWORD_PRIVATE,
  GNU_OPENCL_PRIVATE,
  CXX11_CLANG_OPENCL_PRIVATE,
  C23_CLANG_OPENCL_PRIVATE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLPrivateAddressSpaceAttrSpelling) {
  return "OpenCLPrivateAddressSpaceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLPrivateAddressSpaceAttrSpelling) {
  return 5;
}

const char *EnumeratorName(OpenCLPrivateAddressSpaceAttrSpelling);

} // namespace mx
