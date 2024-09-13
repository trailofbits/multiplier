// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ConstInitAttrSpelling : unsigned char {
  KEYWORD_CONSTINIT,
  GNU_REQUIRE_CONSTANT_INITIALIZATION,
  CXX11_CLANG_REQUIRE_CONSTANT_INITIALIZATION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ConstInitAttrSpelling) {
  return "ConstInitAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ConstInitAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ConstInitAttrSpelling);

} // namespace mx
