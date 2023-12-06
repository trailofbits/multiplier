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
enum class OpenMPOrderClauseModifier : unsigned char {
  MODIFIER_UNKNOWN,
  MODIFIER_REPRODUCIBLE,
  MODIFIER_UNCONSTRAINED,
  MODIFIER_LAST,
};

inline static const char *EnumerationName(OpenMPOrderClauseModifier) {
  return "OpenMPOrderClauseModifier";
}

inline static constexpr unsigned NumEnumerators(OpenMPOrderClauseModifier) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(OpenMPOrderClauseModifier);

} // namespace mx
