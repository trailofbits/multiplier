// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SourceLocExprIdentKind : unsigned char {
  FUNCTION,
  FUNC_SIG,
  FILE,
  FILE_NAME,
  LINE,
  COLUMN,
  SOURCE_TOKEN_STRUCT,
};

inline static const char *EnumerationName(SourceLocExprIdentKind) {
  return "SourceLocExprIdentKind";
}

inline static constexpr unsigned NumEnumerators(SourceLocExprIdentKind) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(SourceLocExprIdentKind);

} // namespace mx
