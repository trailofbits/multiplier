// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OSConsumesThisAttrSpelling : unsigned char {
  GNU_OS_CONSUMES_THIS,
  CXX11_CLANG_OS_CONSUMES_THIS,
  C2X_CLANG_OS_CONSUMES_THIS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OSConsumesThisAttrSpelling) {
  return "OSConsumesThisAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OSConsumesThisAttrSpelling) {
  return 4;
}

const char *EnumeratorName(OSConsumesThisAttrSpelling);

} // namespace mx
