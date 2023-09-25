// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OSReturnsRetainedOnZeroAttrSpelling : unsigned char {
  GNU_OS_RETURNS_RETAINED_ON_ZERO,
  CXX11_CLANG_OS_RETURNS_RETAINED_ON_ZERO,
  C23_CLANG_OS_RETURNS_RETAINED_ON_ZERO,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OSReturnsRetainedOnZeroAttrSpelling) {
  return "OSReturnsRetainedOnZeroAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OSReturnsRetainedOnZeroAttrSpelling) {
  return 4;
}

const char *EnumeratorName(OSReturnsRetainedOnZeroAttrSpelling);

} // namespace mx
