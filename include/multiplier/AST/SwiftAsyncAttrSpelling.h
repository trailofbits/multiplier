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
enum class SwiftAsyncAttrSpelling : unsigned char {
  GNU_SWIFT_ASYNC,
  CXX11_CLANG_SWIFT_ASYNC,
  C23_CLANG_SWIFT_ASYNC,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SwiftAsyncAttrSpelling) {
  return "SwiftAsyncAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SwiftAsyncAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SwiftAsyncAttrSpelling);

} // namespace mx
