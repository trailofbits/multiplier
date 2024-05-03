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
enum class NakedAttrSpelling : unsigned char {
  GNU_NAKED,
  CXX11_GNU_NAKED,
  C23_GNU_NAKED,
  DECLSPEC_NAKED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NakedAttrSpelling) {
  return "NakedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NakedAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(NakedAttrSpelling);

} // namespace mx
