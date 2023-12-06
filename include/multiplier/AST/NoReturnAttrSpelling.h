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
enum class NoReturnAttrSpelling : unsigned char {
  GNU_NORETURN,
  CXX11_GNU_NORETURN,
  C2X_GNU_NORETURN,
  DECLSPEC_NORETURN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoReturnAttrSpelling) {
  return "NoReturnAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoReturnAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(NoReturnAttrSpelling);

} // namespace mx
