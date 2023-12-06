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
enum class CPUSpecificAttrSpelling : unsigned char {
  GNU_CPU_SPECIFIC,
  CXX11_CLANG_CPU_SPECIFIC,
  C2X_CLANG_CPU_SPECIFIC,
  DECLSPEC_CPU_SPECIFIC,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CPUSpecificAttrSpelling) {
  return "CPUSpecificAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CPUSpecificAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(CPUSpecificAttrSpelling);

} // namespace mx
