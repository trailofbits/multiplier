// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ZeroCallUsedRegsAttrSpelling : unsigned char {
  GNU_ZERO_CALL_USED_REGS,
  CXX11_GNU_ZERO_CALL_USED_REGS,
  C23_GNU_ZERO_CALL_USED_REGS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ZeroCallUsedRegsAttrSpelling) {
  return "ZeroCallUsedRegsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ZeroCallUsedRegsAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ZeroCallUsedRegsAttrSpelling);

} // namespace mx
