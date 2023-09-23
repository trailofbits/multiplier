// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenCLGlobalHostAddressSpaceAttrSpelling : unsigned char {
  GNU_OPENCL_GLOBAL_HOST,
  CXX11_CLANG_OPENCL_GLOBAL_HOST,
  C23_CLANG_OPENCL_GLOBAL_HOST,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLGlobalHostAddressSpaceAttrSpelling) {
  return "OpenCLGlobalHostAddressSpaceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLGlobalHostAddressSpaceAttrSpelling) {
  return 4;
}

const char *EnumeratorName(OpenCLGlobalHostAddressSpaceAttrSpelling);

} // namespace mx
