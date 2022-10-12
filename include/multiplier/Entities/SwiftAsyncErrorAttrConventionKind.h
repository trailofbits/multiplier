// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SwiftAsyncErrorAttrConventionKind : unsigned char {
  NONE,
  NON_NULL_ERROR,
  ZERO_ARGUMENT,
  NON_ZERO_ARGUMENT,
};

inline static const char *EnumerationName(SwiftAsyncErrorAttrConventionKind) {
  return "SwiftAsyncErrorAttrConventionKind";
}

inline static constexpr unsigned NumEnumerators(SwiftAsyncErrorAttrConventionKind) {
  return 4;
}

const char *EnumeratorName(SwiftAsyncErrorAttrConventionKind);

} // namespace mx
