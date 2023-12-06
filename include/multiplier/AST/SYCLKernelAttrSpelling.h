// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SYCLKernelAttrSpelling : unsigned char {
  GNU_SYCL_KERNEL,
  CXX11_CLANG_SYCL_KERNEL,
  C2X_CLANG_SYCL_KERNEL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SYCLKernelAttrSpelling) {
  return "SYCLKernelAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SYCLKernelAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SYCLKernelAttrSpelling);

} // namespace mx
