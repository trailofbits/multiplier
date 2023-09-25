// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ArgumentWithTypeTagAttrSpelling : unsigned char {
  GNU_ARGUMENT_WITH_TYPE_TAG,
  CXX11_CLANG_ARGUMENT_WITH_TYPE_TAG,
  C23_CLANG_ARGUMENT_WITH_TYPE_TAG,
  GNU_POINTER_WITH_TYPE_TAG,
  CXX11_CLANG_POINTER_WITH_TYPE_TAG,
  C23_CLANG_POINTER_WITH_TYPE_TAG,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ArgumentWithTypeTagAttrSpelling) {
  return "ArgumentWithTypeTagAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ArgumentWithTypeTagAttrSpelling) {
  return 7;
}

const char *EnumeratorName(ArgumentWithTypeTagAttrSpelling);

} // namespace mx
