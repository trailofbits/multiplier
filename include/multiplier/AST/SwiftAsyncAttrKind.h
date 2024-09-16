// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SwiftAsyncAttrKind : unsigned char {
  NONE,
  SWIFT_PRIVATE,
  NOT_SWIFT_PRIVATE,
};

inline static const char *EnumerationName(SwiftAsyncAttrKind) {
  return "SwiftAsyncAttrKind";
}

inline static constexpr unsigned NumEnumerators(SwiftAsyncAttrKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(SwiftAsyncAttrKind);

} // namespace mx
