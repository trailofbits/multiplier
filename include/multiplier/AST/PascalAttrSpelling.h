// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class PascalAttrSpelling : unsigned char {
  GNU_PASCAL,
  CXX11_CLANG_PASCAL,
  C23_CLANG_PASCAL,
  KEYWORD_PASCAL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PascalAttrSpelling) {
  return "PascalAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PascalAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(PascalAttrSpelling);

} // namespace mx
