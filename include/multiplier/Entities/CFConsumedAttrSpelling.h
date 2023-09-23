// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CFConsumedAttrSpelling : unsigned char {
  GNU_CF_CONSUMED,
  CXX11_CLANG_CF_CONSUMED,
  C23_CLANG_CF_CONSUMED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CFConsumedAttrSpelling) {
  return "CFConsumedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CFConsumedAttrSpelling) {
  return 4;
}

const char *EnumeratorName(CFConsumedAttrSpelling);

} // namespace mx
