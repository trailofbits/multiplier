// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class DeclObjCDeclQualifier : unsigned char {
  NONE,
  IN,
  INOUT,
  OUT,
  BYCOPY,
  BYREF,
  ONEWAY,
  CS_NULLABILITY,
};

inline static const char *EnumerationName(DeclObjCDeclQualifier) {
  return "DeclObjCDeclQualifier";
}

inline static constexpr unsigned NumEnumerators(DeclObjCDeclQualifier) {
  return 8;
}

MX_EXPORT const char *EnumeratorName(DeclObjCDeclQualifier);

} // namespace mx
