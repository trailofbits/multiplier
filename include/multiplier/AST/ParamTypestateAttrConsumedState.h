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
enum class ParamTypestateAttrConsumedState : unsigned char {
  UNKNOWN,
  CONSUMED,
  UNCONSUMED,
};

inline static const char *EnumerationName(ParamTypestateAttrConsumedState) {
  return "ParamTypestateAttrConsumedState";
}

inline static constexpr unsigned NumEnumerators(ParamTypestateAttrConsumedState) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ParamTypestateAttrConsumedState);

} // namespace mx
