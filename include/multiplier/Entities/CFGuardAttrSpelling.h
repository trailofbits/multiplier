// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CFGuardAttrSpelling : unsigned char {
  DECLSPEC_GUARD,
  GNU_GUARD,
  CXX11_CLANG_GUARD,
  C2X_CLANG_GUARD,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CFGuardAttrSpelling) {
  return "CFGuardAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CFGuardAttrSpelling) {
  return 5;
}

const char *EnumeratorName(CFGuardAttrSpelling);

} // namespace mx
