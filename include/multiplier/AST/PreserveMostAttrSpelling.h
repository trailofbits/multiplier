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
enum class PreserveMostAttrSpelling : unsigned char {
  GNU_PRESERVE_MOST,
  CXX11_CLANG_PRESERVE_MOST,
  C23_CLANG_PRESERVE_MOST,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PreserveMostAttrSpelling) {
  return "PreserveMostAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PreserveMostAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(PreserveMostAttrSpelling);

} // namespace mx
