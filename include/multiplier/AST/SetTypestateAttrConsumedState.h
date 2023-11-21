// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SetTypestateAttrConsumedState : unsigned char {
  UNKNOWN,
  CONSUMED,
  UNCONSUMED,
};

inline static const char *EnumerationName(SetTypestateAttrConsumedState) {
  return "SetTypestateAttrConsumedState";
}

inline static constexpr unsigned NumEnumerators(SetTypestateAttrConsumedState) {
  return 3;
}

const char *EnumeratorName(SetTypestateAttrConsumedState);

} // namespace mx
