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
enum class StringLiteralKind : unsigned char {
  ORDINARY,
  WIDE,
  UTF8,
  UTF16,
  UTF32,
  UNEVALUATED,
};

inline static const char *EnumerationName(StringLiteralKind) {
  return "StringLiteralKind";
}

inline static constexpr unsigned NumEnumerators(StringLiteralKind) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(StringLiteralKind);

} // namespace mx
