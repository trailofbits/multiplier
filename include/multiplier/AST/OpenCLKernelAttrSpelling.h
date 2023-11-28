// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenCLKernelAttrSpelling : unsigned char {
  KEYWORD_KERNEL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLKernelAttrSpelling) {
  return "OpenCLKernelAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLKernelAttrSpelling) {
  return 2;
}

const char *EnumeratorName(OpenCLKernelAttrSpelling);

} // namespace mx
