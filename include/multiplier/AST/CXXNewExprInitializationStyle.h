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
enum class CXXNewExprInitializationStyle : unsigned char {
  NO_INITIALIZER,
  CALL_INITIALIZER,
  LIST_INITIALIZER,
};

inline static const char *EnumerationName(CXXNewExprInitializationStyle) {
  return "CXXNewExprInitializationStyle";
}

inline static constexpr unsigned NumEnumerators(CXXNewExprInitializationStyle) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(CXXNewExprInitializationStyle);

} // namespace mx
