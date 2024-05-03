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
enum class CFICanonicalJumpTableAttrSpelling : unsigned char {
  GNU_CFI_CANONICAL_JUMP_TABLE,
  CXX11_CLANG_CFI_CANONICAL_JUMP_TABLE,
  C23_CLANG_CFI_CANONICAL_JUMP_TABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CFICanonicalJumpTableAttrSpelling) {
  return "CFICanonicalJumpTableAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CFICanonicalJumpTableAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CFICanonicalJumpTableAttrSpelling);

} // namespace mx
