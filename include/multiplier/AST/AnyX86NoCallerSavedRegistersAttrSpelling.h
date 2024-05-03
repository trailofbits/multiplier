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
enum class AnyX86NoCallerSavedRegistersAttrSpelling : unsigned char {
  GNU_NO_CALLER_SAVED_REGISTERS,
  CXX11_GNU_NO_CALLER_SAVED_REGISTERS,
  C23_GNU_NO_CALLER_SAVED_REGISTERS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AnyX86NoCallerSavedRegistersAttrSpelling) {
  return "AnyX86NoCallerSavedRegistersAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AnyX86NoCallerSavedRegistersAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AnyX86NoCallerSavedRegistersAttrSpelling);

} // namespace mx
