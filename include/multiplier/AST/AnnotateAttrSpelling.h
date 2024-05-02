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
enum class AnnotateAttrSpelling : unsigned char {
  GNU_ANNOTATE,
  CXX11_CLANG_ANNOTATE,
  C23_CLANG_ANNOTATE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AnnotateAttrSpelling) {
  return "AnnotateAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AnnotateAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AnnotateAttrSpelling);

} // namespace mx
