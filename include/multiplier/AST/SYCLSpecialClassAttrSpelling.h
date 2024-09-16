// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SYCLSpecialClassAttrSpelling : unsigned char {
  GNU_SYCL_SPECIAL_CLASS,
  CXX11_CLANG_SYCL_SPECIAL_CLASS,
  C23_CLANG_SYCL_SPECIAL_CLASS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SYCLSpecialClassAttrSpelling) {
  return "SYCLSpecialClassAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SYCLSpecialClassAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SYCLSpecialClassAttrSpelling);

} // namespace mx
