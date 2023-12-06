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
enum class ConvergentAttrSpelling : unsigned char {
  GNU_CONVERGENT,
  CXX11_CLANG_CONVERGENT,
  C2X_CLANG_CONVERGENT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ConvergentAttrSpelling) {
  return "ConvergentAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ConvergentAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ConvergentAttrSpelling);

} // namespace mx
