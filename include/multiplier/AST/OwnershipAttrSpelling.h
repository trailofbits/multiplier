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
enum class OwnershipAttrSpelling : unsigned char {
  GNU_OWNERSHIP_HOLDS,
  CXX11_CLANG_OWNERSHIP_HOLDS,
  C2X_CLANG_OWNERSHIP_HOLDS,
  GNU_OWNERSHIP_RETURNS,
  CXX11_CLANG_OWNERSHIP_RETURNS,
  C2X_CLANG_OWNERSHIP_RETURNS,
  GNU_OWNERSHIP_TAKES,
  CXX11_CLANG_OWNERSHIP_TAKES,
  C2X_CLANG_OWNERSHIP_TAKES,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OwnershipAttrSpelling) {
  return "OwnershipAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OwnershipAttrSpelling) {
  return 10;
}

MX_EXPORT const char *EnumeratorName(OwnershipAttrSpelling);

} // namespace mx
