// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class BuiltinAliasAttrSpelling : unsigned char {
  CXX11_CLANG_BUILTIN_ALIAS,
  C23_CLANG_BUILTIN_ALIAS,
  GNU_CLANG_BUILTIN_ALIAS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(BuiltinAliasAttrSpelling) {
  return "BuiltinAliasAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(BuiltinAliasAttrSpelling) {
  return 4;
}

const char *EnumeratorName(BuiltinAliasAttrSpelling);

} // namespace mx
