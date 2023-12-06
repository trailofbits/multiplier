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
enum class ArmBuiltinAliasAttrSpelling : unsigned char {
  GNU_CLANG_ARM_BUILTIN_ALIAS,
  CXX11_CLANG_CLANG_ARM_BUILTIN_ALIAS,
  C2X_CLANG_CLANG_ARM_BUILTIN_ALIAS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ArmBuiltinAliasAttrSpelling) {
  return "ArmBuiltinAliasAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ArmBuiltinAliasAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ArmBuiltinAliasAttrSpelling);

} // namespace mx
