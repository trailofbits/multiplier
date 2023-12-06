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
enum class CXX11NoReturnAttrSpelling : unsigned char {
  CXX11_NORETURN,
  C2XNORETURN,
  C2X_NORETURN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CXX11NoReturnAttrSpelling) {
  return "CXX11NoReturnAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CXX11NoReturnAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CXX11NoReturnAttrSpelling);

} // namespace mx
