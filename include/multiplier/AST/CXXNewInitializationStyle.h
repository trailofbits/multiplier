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
enum class CXXNewInitializationStyle : unsigned char {
  NONE,
  PARENTHESES,
  BRACES,
};

inline static const char *EnumerationName(CXXNewInitializationStyle) {
  return "CXXNewInitializationStyle";
}

inline static constexpr unsigned NumEnumerators(CXXNewInitializationStyle) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(CXXNewInitializationStyle);

} // namespace mx
