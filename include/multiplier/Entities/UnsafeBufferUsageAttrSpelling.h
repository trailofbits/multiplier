// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class UnsafeBufferUsageAttrSpelling : unsigned char {
  GNU_UNSAFE_BUFFER_USAGE,
  CXX11_CLANG_UNSAFE_BUFFER_USAGE,
  C23_CLANG_UNSAFE_BUFFER_USAGE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(UnsafeBufferUsageAttrSpelling) {
  return "UnsafeBufferUsageAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(UnsafeBufferUsageAttrSpelling) {
  return 4;
}

const char *EnumeratorName(UnsafeBufferUsageAttrSpelling);

} // namespace mx
