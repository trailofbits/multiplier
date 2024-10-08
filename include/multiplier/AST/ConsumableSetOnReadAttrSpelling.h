// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ConsumableSetOnReadAttrSpelling : unsigned char {
  GNU_CONSUMABLE_STATE_ON_READ,
  CXX11_CLANG_CONSUMABLE_STATE_ON_READ,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ConsumableSetOnReadAttrSpelling) {
  return "ConsumableSetOnReadAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ConsumableSetOnReadAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ConsumableSetOnReadAttrSpelling);

} // namespace mx
