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
enum class OSReturnsRetainedOnNonZeroAttrSpelling : unsigned char {
  GNU_OS_RETURNS_RETAINED_ON_NON_ZERO,
  CXX11_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO,
  C2X_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OSReturnsRetainedOnNonZeroAttrSpelling) {
  return "OSReturnsRetainedOnNonZeroAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OSReturnsRetainedOnNonZeroAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(OSReturnsRetainedOnNonZeroAttrSpelling);

} // namespace mx
