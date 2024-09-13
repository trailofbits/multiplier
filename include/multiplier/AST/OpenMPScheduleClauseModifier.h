// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenMPScheduleClauseModifier : unsigned char {
  UNKNOWN,
  MONOTONIC,
  NONMONOTONIC,
  SIMD,
};

inline static const char *EnumerationName(OpenMPScheduleClauseModifier) {
  return "OpenMPScheduleClauseModifier";
}

inline static constexpr unsigned NumEnumerators(OpenMPScheduleClauseModifier) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(OpenMPScheduleClauseModifier);

} // namespace mx
