// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ConsumableAutoCastAttrSpelling : unsigned char {
  GNU_CONSUMABLE_AUTO_CAST_STATE,
  CXX11_CLANG_CONSUMABLE_AUTO_CAST_STATE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ConsumableAutoCastAttrSpelling) {
  return "ConsumableAutoCastAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ConsumableAutoCastAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ConsumableAutoCastAttrSpelling);

} // namespace mx
