// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MaybeUndefAttrSpelling : unsigned char {
  GNU_MAYBE_UNDEF,
  CXX11_CLANG_MAYBE_UNDEF,
  C2X_CLANG_MAYBE_UNDEF,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(MaybeUndefAttrSpelling) {
  return "MaybeUndefAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(MaybeUndefAttrSpelling) {
  return 4;
}

const char *EnumeratorName(MaybeUndefAttrSpelling);

} // namespace mx
