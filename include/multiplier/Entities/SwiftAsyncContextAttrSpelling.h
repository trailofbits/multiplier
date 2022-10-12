// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SwiftAsyncContextAttrSpelling : unsigned char {
  GNU_SWIFT_ASYNC_CONTEXT,
  CXX11_CLANG_SWIFT_ASYNC_CONTEXT,
  C2X_CLANG_SWIFT_ASYNC_CONTEXT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SwiftAsyncContextAttrSpelling) {
  return "SwiftAsyncContextAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SwiftAsyncContextAttrSpelling) {
  return 4;
}

const char *EnumeratorName(SwiftAsyncContextAttrSpelling);

} // namespace mx
