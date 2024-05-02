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
enum class SwiftIndirectResultAttrSpelling : unsigned char {
  GNU_SWIFT_INDIRECT_RESULT,
  CXX11_CLANG_SWIFT_INDIRECT_RESULT,
  C23_CLANG_SWIFT_INDIRECT_RESULT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SwiftIndirectResultAttrSpelling) {
  return "SwiftIndirectResultAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SwiftIndirectResultAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SwiftIndirectResultAttrSpelling);

} // namespace mx
