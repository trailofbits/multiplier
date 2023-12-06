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
enum class ModifiableType : unsigned char {
  UNTESTED,
  MODIFIABLE,
  R_VALUE,
  FUNCTION,
  L_VALUE_CAST,
  NO_SETTER_PROPERTY,
  CONST_QUALIFIED,
  CONST_QUALIFIED_FIELD,
  CONST_ADDRESS_SPACE,
  ARRAY_TYPE,
  INCOMPLETE_TYPE,
};

inline static const char *EnumerationName(ModifiableType) {
  return "ModifiableType";
}

inline static constexpr unsigned NumEnumerators(ModifiableType) {
  return 11;
}

MX_EXPORT const char *EnumeratorName(ModifiableType);

} // namespace mx
