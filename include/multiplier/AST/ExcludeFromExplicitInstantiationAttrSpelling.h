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
enum class ExcludeFromExplicitInstantiationAttrSpelling : unsigned char {
  GNU_EXCLUDE_FROM_EXPLICIT_INSTANTIATION,
  CXX11_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION,
  C23_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ExcludeFromExplicitInstantiationAttrSpelling) {
  return "ExcludeFromExplicitInstantiationAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ExcludeFromExplicitInstantiationAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ExcludeFromExplicitInstantiationAttrSpelling);

} // namespace mx
