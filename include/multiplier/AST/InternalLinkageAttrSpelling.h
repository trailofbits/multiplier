// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class InternalLinkageAttrSpelling : unsigned char {
  GNU_INTERNAL_LINKAGE,
  CXX11_CLANG_INTERNAL_LINKAGE,
  C23_CLANG_INTERNAL_LINKAGE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(InternalLinkageAttrSpelling) {
  return "InternalLinkageAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(InternalLinkageAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(InternalLinkageAttrSpelling);

} // namespace mx
