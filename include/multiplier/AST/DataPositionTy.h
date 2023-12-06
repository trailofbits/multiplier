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
enum class DataPositionTy : unsigned char {
  POSX,
  POSV,
  POSE,
  POS_UPDATE_EXPRESSION,
  POSD,
  POS_CONDITION,
  POSR,
};

inline static const char *EnumerationName(DataPositionTy) {
  return "DataPositionTy";
}

inline static constexpr unsigned NumEnumerators(DataPositionTy) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(DataPositionTy);

} // namespace mx
