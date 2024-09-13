// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ExprSideEffectsKind : unsigned char {
  NO_SIDE_EFFECTS,
  ALLOW_UNDEFINED_BEHAVIOR,
  ALLOW_SIDE_EFFECTS,
};

inline static const char *EnumerationName(ExprSideEffectsKind) {
  return "ExprSideEffectsKind";
}

inline static constexpr unsigned NumEnumerators(ExprSideEffectsKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ExprSideEffectsKind);

} // namespace mx
