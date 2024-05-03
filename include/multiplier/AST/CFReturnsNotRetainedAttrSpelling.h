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
enum class CFReturnsNotRetainedAttrSpelling : unsigned char {
  GNU_CF_RETURNS_NOT_RETAINED,
  CXX11_CLANG_CF_RETURNS_NOT_RETAINED,
  C23_CLANG_CF_RETURNS_NOT_RETAINED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CFReturnsNotRetainedAttrSpelling) {
  return "CFReturnsNotRetainedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CFReturnsNotRetainedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CFReturnsNotRetainedAttrSpelling);

} // namespace mx
