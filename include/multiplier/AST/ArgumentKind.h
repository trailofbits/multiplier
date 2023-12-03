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
enum class ArgumentKind : unsigned char {
  STD_STRING,
  C_STRING,
  SINT,
  UINT,
  TOKENKIND,
  IDENTIFIERINFO,
  ADDRSPACE,
  QUALIFIED,
  QUALTYPE,
  DECLARATIONNAME,
  NAMEDDECL,
  NESTEDNAMESPEC,
  DECLCONTEXT,
  QUALTYPE_PAIR,
  ATTRIBUTE,
};

inline static const char *EnumerationName(ArgumentKind) {
  return "ArgumentKind";
}

inline static constexpr unsigned NumEnumerators(ArgumentKind) {
  return 15;
}

MX_EXPORT const char *EnumeratorName(ArgumentKind);

} // namespace mx
