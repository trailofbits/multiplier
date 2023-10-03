// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MustTailAttrSpelling : unsigned char {
  GNU_MUSTTAIL,
  CXX11_CLANG_MUSTTAIL,
  C23_CLANG_MUSTTAIL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MustTailAttrSpelling) {
  return "MustTailAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MustTailAttrSpelling) {
  return 4;
}

const char *EnumeratorName(MustTailAttrSpelling);

} // namespace mx
