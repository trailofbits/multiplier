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
enum class MipsInterruptAttrSpelling : unsigned char {
  GNU_INTERRUPT,
  CXX11_GNU_INTERRUPT,
  C23_GNU_INTERRUPT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MipsInterruptAttrSpelling) {
  return "MipsInterruptAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MipsInterruptAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(MipsInterruptAttrSpelling);

} // namespace mx
