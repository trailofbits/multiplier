// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class VarDeclInitializationStyle : unsigned char {
  C_INIT,
  CALL_INITIALIZER,
  LIST_INITIALIZER,
  PARENTHESIS_LIST_INITIALIZER,
};

inline static const char *EnumerationName(VarDeclInitializationStyle) {
  return "VarDeclInitializationStyle";
}

inline static constexpr unsigned NumEnumerators(VarDeclInitializationStyle) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(VarDeclInitializationStyle);

} // namespace mx
