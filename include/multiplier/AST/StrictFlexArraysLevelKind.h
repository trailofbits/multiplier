// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class StrictFlexArraysLevelKind : unsigned char {
  DEFAULT,
  ONE_ZERO_OR_INCOMPLETE,
  ZERO_OR_INCOMPLETE,
  INCOMPLETE_ONLY,
};

inline static const char *EnumerationName(StrictFlexArraysLevelKind) {
  return "StrictFlexArraysLevelKind";
}

inline static constexpr unsigned NumEnumerators(StrictFlexArraysLevelKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(StrictFlexArraysLevelKind);

} // namespace mx
