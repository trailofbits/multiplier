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
enum class TypeTagForDatatypeAttrSpelling : unsigned char {
  GNU_TYPE_TAG_FOR_DATATYPE,
  CXX11_CLANG_TYPE_TAG_FOR_DATATYPE,
  C23_CLANG_TYPE_TAG_FOR_DATATYPE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(TypeTagForDatatypeAttrSpelling) {
  return "TypeTagForDatatypeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(TypeTagForDatatypeAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(TypeTagForDatatypeAttrSpelling);

} // namespace mx
