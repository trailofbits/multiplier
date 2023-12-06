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
enum class ScopedLockableAttrSpelling : unsigned char {
  GNU_SCOPED_LOCKABLE,
  CXX11_CLANG_SCOPED_LOCKABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ScopedLockableAttrSpelling) {
  return "ScopedLockableAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ScopedLockableAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ScopedLockableAttrSpelling);

} // namespace mx
