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
enum class ThisCallAttrSpelling : unsigned char {
  GNU_THISCALL,
  CXX11_GNU_THISCALL,
  C23_GNU_THISCALL,
  KEYWORD_THISCALL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ThisCallAttrSpelling) {
  return "ThisCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ThisCallAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(ThisCallAttrSpelling);

} // namespace mx
