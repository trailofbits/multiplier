// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class MipsInterruptAttrInterruptType : unsigned char {
  SW0,
  SW1,
  HW0,
  HW1,
  HW2,
  HW3,
  HW4,
  HW5,
  EIC,
};

inline static const char *EnumerationName(MipsInterruptAttrInterruptType) {
  return "MipsInterruptAttrInterruptType";
}

inline static constexpr unsigned NumEnumerators(MipsInterruptAttrInterruptType) {
  return 9;
}

MX_EXPORT const char *EnumeratorName(MipsInterruptAttrInterruptType);

} // namespace mx
