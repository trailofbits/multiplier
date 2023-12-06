// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class WeakRefAttrSpelling : unsigned char {
  GNU_WEAKREF,
  CXX11_GNU_WEAKREF,
  C2X_GNU_WEAKREF,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(WeakRefAttrSpelling) {
  return "WeakRefAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(WeakRefAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(WeakRefAttrSpelling);

} // namespace mx
