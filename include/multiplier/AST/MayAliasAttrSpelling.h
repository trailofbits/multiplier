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
enum class MayAliasAttrSpelling : unsigned char {
  GNU_MAY_ALIAS,
  CXX11_GNU_MAY_ALIAS,
  C23_GNU_MAY_ALIAS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MayAliasAttrSpelling) {
  return "MayAliasAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MayAliasAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(MayAliasAttrSpelling);

} // namespace mx
