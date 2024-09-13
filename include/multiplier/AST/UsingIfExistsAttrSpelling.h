// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class UsingIfExistsAttrSpelling : unsigned char {
  GNU_USING_IF_EXISTS,
  CXX11_CLANG_USING_IF_EXISTS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(UsingIfExistsAttrSpelling) {
  return "UsingIfExistsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(UsingIfExistsAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(UsingIfExistsAttrSpelling);

} // namespace mx
