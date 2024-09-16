// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SuppressAttrSpelling : unsigned char {
  CXX11_GSL_SUPPRESS,
  GNU_SUPPRESS,
  CXX11_CLANG_SUPPRESS,
  C23_CLANG_SUPPRESS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SuppressAttrSpelling) {
  return "SuppressAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SuppressAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(SuppressAttrSpelling);

} // namespace mx
