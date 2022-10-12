// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class PreferredNameAttrSpelling : unsigned char {
  GNU_PREFERRED_NAME,
  CXX11_CLANG_PREFERRED_NAME,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(PreferredNameAttrSpelling) {
  return "PreferredNameAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(PreferredNameAttrSpelling) {
  return 3;
}

const char *EnumeratorName(PreferredNameAttrSpelling);

} // namespace mx
