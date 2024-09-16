// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SwiftAsyncCallAttrSpelling : unsigned char {
  GNU_SWIFTASYNCCALL,
  CXX11_CLANG_SWIFTASYNCCALL,
  C23_CLANG_SWIFTASYNCCALL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SwiftAsyncCallAttrSpelling) {
  return "SwiftAsyncCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SwiftAsyncCallAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SwiftAsyncCallAttrSpelling);

} // namespace mx
