// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class BTFDeclTagAttrSpelling : unsigned char {
  GNU_BTF_DECLARATION_TAG,
  CXX11_CLANG_BTF_DECLARATION_TAG,
  C23_CLANG_BTF_DECLARATION_TAG,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(BTFDeclTagAttrSpelling) {
  return "BTFDeclTagAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(BTFDeclTagAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(BTFDeclTagAttrSpelling);

} // namespace mx
