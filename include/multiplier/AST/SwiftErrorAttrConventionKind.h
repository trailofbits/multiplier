// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SwiftErrorAttrConventionKind : unsigned char {
  NONE,
  NON_NULL_ERROR,
  NULL_RESULT,
  ZERO_RESULT,
  NON_ZERO_RESULT,
};

inline static const char *EnumerationName(SwiftErrorAttrConventionKind) {
  return "SwiftErrorAttrConventionKind";
}

inline static constexpr unsigned NumEnumerators(SwiftErrorAttrConventionKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(SwiftErrorAttrConventionKind);

} // namespace mx
