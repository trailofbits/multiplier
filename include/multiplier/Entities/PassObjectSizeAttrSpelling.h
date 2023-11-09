// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class PassObjectSizeAttrSpelling : unsigned char {
  GNU_PASS_OBJECT_SIZE,
  CXX11_CLANG_PASS_OBJECT_SIZE,
  C2X_CLANG_PASS_OBJECT_SIZE,
  GNU_PASS_DYNAMIC_OBJECT_SIZE,
  CXX11_CLANG_PASS_DYNAMIC_OBJECT_SIZE,
  C2X_CLANG_PASS_DYNAMIC_OBJECT_SIZE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PassObjectSizeAttrSpelling) {
  return "PassObjectSizeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PassObjectSizeAttrSpelling) {
  return 7;
}

const char *EnumeratorName(PassObjectSizeAttrSpelling);

} // namespace mx
