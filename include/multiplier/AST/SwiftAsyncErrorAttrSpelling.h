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
enum class SwiftAsyncErrorAttrSpelling : unsigned char {
  GNU_SWIFT_ASYNC_ERROR,
  CXX11_CLANG_SWIFT_ASYNC_ERROR,
  C23_CLANG_SWIFT_ASYNC_ERROR,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SwiftAsyncErrorAttrSpelling) {
  return "SwiftAsyncErrorAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SwiftAsyncErrorAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SwiftAsyncErrorAttrSpelling);

} // namespace mx
