// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class PreferredTypeAttrSpelling : unsigned char {
  GNU_PREFERRED_TYPE,
  CXX11_CLANG_PREFERRED_TYPE,
  C23_CLANG_PREFERRED_TYPE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PreferredTypeAttrSpelling) {
  return "PreferredTypeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PreferredTypeAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(PreferredTypeAttrSpelling);

} // namespace mx
