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
enum class TransparentUnionAttrSpelling : unsigned char {
  GNU_TRANSPARENT_UNION,
  CXX11_GNU_TRANSPARENT_UNION,
  C23_GNU_TRANSPARENT_UNION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(TransparentUnionAttrSpelling) {
  return "TransparentUnionAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(TransparentUnionAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(TransparentUnionAttrSpelling);

} // namespace mx
