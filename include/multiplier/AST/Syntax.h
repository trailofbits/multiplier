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
enum class Syntax : unsigned char {
  GNU,
  CXX11,
  C2X,
  DECLSPEC,
  MICROSOFT,
  KEYWORD,
  PRAGMA,
  CONTEXT_SENSITIVE_KEYWORD,
  HLSL_SEMANTIC,
  IMPLICIT,
};

inline static const char *EnumerationName(Syntax) {
  return "Syntax";
}

inline static constexpr unsigned NumEnumerators(Syntax) {
  return 10;
}

MX_EXPORT const char *EnumeratorName(Syntax);

} // namespace mx
