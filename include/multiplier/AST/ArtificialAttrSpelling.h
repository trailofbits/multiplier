// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ArtificialAttrSpelling : unsigned char {
  GNU_ARTIFICIAL,
  CXX11_GNU_ARTIFICIAL,
  C23_GNU_ARTIFICIAL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ArtificialAttrSpelling) {
  return "ArtificialAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ArtificialAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ArtificialAttrSpelling);

} // namespace mx
