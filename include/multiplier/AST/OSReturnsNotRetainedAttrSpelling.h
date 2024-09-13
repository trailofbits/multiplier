// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OSReturnsNotRetainedAttrSpelling : unsigned char {
  GNU_OS_RETURNS_NOT_RETAINED,
  CXX11_CLANG_OS_RETURNS_NOT_RETAINED,
  C23_CLANG_OS_RETURNS_NOT_RETAINED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OSReturnsNotRetainedAttrSpelling) {
  return "OSReturnsNotRetainedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OSReturnsNotRetainedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(OSReturnsNotRetainedAttrSpelling);

} // namespace mx
