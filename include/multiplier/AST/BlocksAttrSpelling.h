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
enum class BlocksAttrSpelling : unsigned char {
  GNU_BLOCKS,
  CXX11_CLANG_BLOCKS,
  C2X_CLANG_BLOCKS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(BlocksAttrSpelling) {
  return "BlocksAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(BlocksAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(BlocksAttrSpelling);

} // namespace mx
