// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class WeakImportAttrSpelling : unsigned char {
  GNU_WEAK_IMPORT,
  CXX11_CLANG_WEAK_IMPORT,
  C2X_CLANG_WEAK_IMPORT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(WeakImportAttrSpelling) {
  return "WeakImportAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(WeakImportAttrSpelling) {
  return 4;
}

const char *EnumeratorName(WeakImportAttrSpelling);

} // namespace mx
