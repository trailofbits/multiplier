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
enum class NSReturnsRetainedAttrSpelling : unsigned char {
  GNU_NS_RETURNS_RETAINED,
  CXX11_CLANG_NS_RETURNS_RETAINED,
  C23_CLANG_NS_RETURNS_RETAINED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NSReturnsRetainedAttrSpelling) {
  return "NSReturnsRetainedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NSReturnsRetainedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NSReturnsRetainedAttrSpelling);

} // namespace mx
