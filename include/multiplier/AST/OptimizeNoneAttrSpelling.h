// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OptimizeNoneAttrSpelling : unsigned char {
  GNU_OPTNONE,
  CXX11_CLANG_OPTNONE,
  C2X_CLANG_OPTNONE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OptimizeNoneAttrSpelling) {
  return "OptimizeNoneAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OptimizeNoneAttrSpelling) {
  return 4;
}

const char *EnumeratorName(OptimizeNoneAttrSpelling);

} // namespace mx
