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
enum class M68kRTDAttrSpelling : unsigned char {
  GNUM68K_RTD,
  CXX11_CLANG_M68K_RTD,
  C23_CLANG_M68K_RTD,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(M68kRTDAttrSpelling) {
  return "M68kRTDAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(M68kRTDAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(M68kRTDAttrSpelling);

} // namespace mx
