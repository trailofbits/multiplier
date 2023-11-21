// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoUwtableAttrSpelling : unsigned char {
  GNU_NOUWTABLE,
  CXX11_CLANG_NOUWTABLE,
  C2X_CLANG_NOUWTABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoUwtableAttrSpelling) {
  return "NoUwtableAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoUwtableAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NoUwtableAttrSpelling);

} // namespace mx
