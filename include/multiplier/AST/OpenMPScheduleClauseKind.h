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
enum class OpenMPScheduleClauseKind : unsigned char {
  STATIC,
  DYNAMIC,
  GUIDED,
  AUTO,
  RUNTIME,
  UNKNOWN,
};

inline static const char *EnumerationName(OpenMPScheduleClauseKind) {
  return "OpenMPScheduleClauseKind";
}

inline static constexpr unsigned NumEnumerators(OpenMPScheduleClauseKind) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(OpenMPScheduleClauseKind);

} // namespace mx
