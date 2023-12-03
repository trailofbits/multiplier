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
enum class VisibilityAttrSpelling : unsigned char {
  GNU_VISIBILITY,
  CXX11_GNU_VISIBILITY,
  C2X_GNU_VISIBILITY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(VisibilityAttrSpelling) {
  return "VisibilityAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(VisibilityAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(VisibilityAttrSpelling);

} // namespace mx
