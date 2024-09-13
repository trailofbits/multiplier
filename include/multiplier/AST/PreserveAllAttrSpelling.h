// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class PreserveAllAttrSpelling : unsigned char {
  GNU_PRESERVE_ALL,
  CXX11_CLANG_PRESERVE_ALL,
  C23_CLANG_PRESERVE_ALL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PreserveAllAttrSpelling) {
  return "PreserveAllAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PreserveAllAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(PreserveAllAttrSpelling);

} // namespace mx
