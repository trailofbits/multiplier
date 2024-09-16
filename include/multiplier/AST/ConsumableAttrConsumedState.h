// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ConsumableAttrConsumedState : unsigned char {
  UNKNOWN,
  CONSUMED,
  UNCONSUMED,
};

inline static const char *EnumerationName(ConsumableAttrConsumedState) {
  return "ConsumableAttrConsumedState";
}

inline static constexpr unsigned NumEnumerators(ConsumableAttrConsumedState) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ConsumableAttrConsumedState);

} // namespace mx
