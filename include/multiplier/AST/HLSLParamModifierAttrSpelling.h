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
enum class HLSLParamModifierAttrSpelling : unsigned char {
  KEYWORD_IN,
  KEYWORD_INOUT,
  KEYWORD_OUT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(HLSLParamModifierAttrSpelling) {
  return "HLSLParamModifierAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(HLSLParamModifierAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(HLSLParamModifierAttrSpelling);

} // namespace mx
