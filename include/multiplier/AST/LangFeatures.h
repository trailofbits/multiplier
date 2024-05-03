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
enum class LangFeatures : unsigned char {
  LINE_COMMENT,
  C99,
  C11,
  C17,
  C23,
  C_PLUS_PLUS,
  C_PLUS_PLUS11,
  C_PLUS_PLUS14,
  C_PLUS_PLUS17,
  C_PLUS_PLUS20,
  C_PLUS_PLUS23,
  C_PLUS_PLUS26,
  DIGRAPHS,
  GNU_MODE,
  HEX_FLOAT,
  OPEN_CL,
  HLSL,
};

inline static const char *EnumerationName(LangFeatures) {
  return "LangFeatures";
}

inline static constexpr unsigned NumEnumerators(LangFeatures) {
  return 17;
}

MX_EXPORT const char *EnumeratorName(LangFeatures);

} // namespace mx
