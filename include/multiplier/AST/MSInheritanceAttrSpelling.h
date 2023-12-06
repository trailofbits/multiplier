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
enum class MSInheritanceAttrSpelling : unsigned char {
  KEYWORD_SINGLE_INHERITANCE,
  KEYWORD_MULTIPLE_INHERITANCE,
  KEYWORD_VIRTUAL_INHERITANCE,
  KEYWORD_UNSPECIFIED_INHERITANCE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MSInheritanceAttrSpelling) {
  return "MSInheritanceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MSInheritanceAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(MSInheritanceAttrSpelling);

} // namespace mx
