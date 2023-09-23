// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoDuplicateAttrSpelling : unsigned char {
  GNU_NODUPLICATE,
  CXX11_CLANG_NODUPLICATE,
  C23_CLANG_NODUPLICATE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoDuplicateAttrSpelling) {
  return "NoDuplicateAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoDuplicateAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NoDuplicateAttrSpelling);

} // namespace mx
