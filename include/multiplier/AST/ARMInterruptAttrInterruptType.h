// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ARMInterruptAttrInterruptType : unsigned char {
  IRQ,
  FIQ,
  SWI,
  ABORT,
  UNDEF,
  GENERIC,
};

inline static const char *EnumerationName(ARMInterruptAttrInterruptType) {
  return "ARMInterruptAttrInterruptType";
}

inline static constexpr unsigned NumEnumerators(ARMInterruptAttrInterruptType) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(ARMInterruptAttrInterruptType);

} // namespace mx
