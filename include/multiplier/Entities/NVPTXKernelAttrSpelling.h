// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NVPTXKernelAttrSpelling : unsigned char {
  GNU_NVPTX_KERNEL,
  CXX11_CLANG_NVPTX_KERNEL,
  C23_CLANG_NVPTX_KERNEL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NVPTXKernelAttrSpelling) {
  return "NVPTXKernelAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NVPTXKernelAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NVPTXKernelAttrSpelling);

} // namespace mx
