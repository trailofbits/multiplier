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
enum class InterestingIdentifierKind : unsigned char {
  NOT_INTERESTING,
  FILE,
  JMP_BUF,
  SIGJMP_BUF,
  UCONTEXT_T,
  FLOAT_T,
  DOUBLE_T,
  NUMINTERESTINGIDENTIFIERS,
};

inline static const char *EnumerationName(InterestingIdentifierKind) {
  return "InterestingIdentifierKind";
}

inline static constexpr unsigned NumEnumerators(InterestingIdentifierKind) {
  return 8;
}

MX_EXPORT const char *EnumeratorName(InterestingIdentifierKind);

} // namespace mx
