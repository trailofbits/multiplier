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
enum class Kinds : unsigned char {
  L_VALUE,
  X_VALUE,
  FUNCTION,
  VOID,
  ADDRESSABLE_VOID,
  DUPLICATE_VECTOR_COMPONENTS,
  MEMBER_FUNCTION,
  SUB_OBJ_C_PROPERTY_SETTING,
  CLASS_TEMPORARY,
  ARRAY_TEMPORARY,
  OBJ_C_MESSAGE_R_VALUE,
  PR_VALUE,
};

inline static const char *EnumerationName(Kinds) {
  return "Kinds";
}

inline static constexpr unsigned NumEnumerators(Kinds) {
  return 12;
}

MX_EXPORT const char *EnumeratorName(Kinds);

} // namespace mx
