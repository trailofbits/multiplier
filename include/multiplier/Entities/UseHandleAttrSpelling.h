// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class UseHandleAttrSpelling : unsigned char {
  GNU_USE_HANDLE,
  CXX11_CLANG_USE_HANDLE,
  C23_CLANG_USE_HANDLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(UseHandleAttrSpelling) {
  return "UseHandleAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(UseHandleAttrSpelling) {
  return 4;
}

const char *EnumeratorName(UseHandleAttrSpelling);

} // namespace mx
