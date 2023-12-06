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
enum class RestrictAttrSpelling : unsigned char {
  DECLSPEC_RESTRICT,
  GNU_MALLOC,
  CXX11_GNU_MALLOC,
  C2X_GNU_MALLOC,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(RestrictAttrSpelling) {
  return "RestrictAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(RestrictAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(RestrictAttrSpelling);

} // namespace mx
