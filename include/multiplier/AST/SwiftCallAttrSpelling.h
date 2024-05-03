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
enum class SwiftCallAttrSpelling : unsigned char {
  GNU_SWIFTCALL,
  CXX11_CLANG_SWIFTCALL,
  C23_CLANG_SWIFTCALL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SwiftCallAttrSpelling) {
  return "SwiftCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SwiftCallAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SwiftCallAttrSpelling);

} // namespace mx
