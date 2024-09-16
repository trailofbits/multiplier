// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class PtGuardedVarAttrSpelling : unsigned char {
  GNU_PT_GUARDED_VARIABLE,
  CXX11_CLANG_PT_GUARDED_VARIABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PtGuardedVarAttrSpelling) {
  return "PtGuardedVarAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PtGuardedVarAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(PtGuardedVarAttrSpelling);

} // namespace mx
