// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class IFuncAttrSpelling : unsigned char {
  GNU_IFUNC,
  CXX11_GNU_IFUNC,
  C23_GNU_IFUNC,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(IFuncAttrSpelling) {
  return "IFuncAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(IFuncAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(IFuncAttrSpelling);

} // namespace mx
