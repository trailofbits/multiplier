// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ReturnsTwiceAttrSpelling : unsigned char {
  GNU_RETURNS_TWICE,
  CXX11_GNU_RETURNS_TWICE,
  C23_GNU_RETURNS_TWICE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ReturnsTwiceAttrSpelling) {
  return "ReturnsTwiceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ReturnsTwiceAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ReturnsTwiceAttrSpelling);

} // namespace mx
