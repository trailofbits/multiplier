// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OSConsumedAttrSpelling : unsigned char {
  GNU_OS_CONSUMED,
  CXX11_CLANG_OS_CONSUMED,
  C2X_CLANG_OS_CONSUMED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OSConsumedAttrSpelling) {
  return "OSConsumedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OSConsumedAttrSpelling) {
  return 4;
}

const char *EnumeratorName(OSConsumedAttrSpelling);

} // namespace mx