// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MacroDirectiveKind : unsigned char {
  OTHER,
  IF,
  IF_DEFINED,
  IF_NOT_DEFINED,
  ELSE_IF,
  ELSE_IF_DEFINED,
  ELSE_IF_NOT_DEFINED,
  ELSE,
  END_IF,
  DEFINE,
  UNDEFINE,
  HASH_PRAGMA,
  C99_PRAGMA,
  MICROSOFT_PRAGMA,
  INCLUDE,
  INCLUDE_NEXT,
  INCLUDE_MACROS,
  IMPORT,
};

inline static const char *EnumerationName(MacroDirectiveKind) {
  return "MacroDirectiveKind";
}

inline static constexpr unsigned NumEnumerators(MacroDirectiveKind) {
  return 18;
}

const char *EnumeratorName(MacroDirectiveKind);

} // namespace mx
