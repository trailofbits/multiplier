// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class RegCallAttrSpelling : unsigned char {
  GNU_REGCALL,
  CXX11_GNU_REGCALL,
  C23_GNU_REGCALL,
  KEYWORD_REGCALL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(RegCallAttrSpelling) {
  return "RegCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(RegCallAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(RegCallAttrSpelling);

} // namespace mx
