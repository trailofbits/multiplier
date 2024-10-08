// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class FlagEnumAttrSpelling : unsigned char {
  GNU_FLAG_ENUM,
  CXX11_CLANG_FLAG_ENUM,
  C23_CLANG_FLAG_ENUM,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(FlagEnumAttrSpelling) {
  return "FlagEnumAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(FlagEnumAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(FlagEnumAttrSpelling);

} // namespace mx
