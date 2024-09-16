// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class RISCVInterruptAttrInterruptType : unsigned char {
  SUPERVISOR,
  MACHINE,
};

inline static const char *EnumerationName(RISCVInterruptAttrInterruptType) {
  return "RISCVInterruptAttrInterruptType";
}

inline static constexpr unsigned NumEnumerators(RISCVInterruptAttrInterruptType) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(RISCVInterruptAttrInterruptType);

} // namespace mx
