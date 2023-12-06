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
enum class EnforceTCBLeafAttrSpelling : unsigned char {
  GNU_ENFORCE_TCB_LEAF,
  CXX11_CLANG_ENFORCE_TCB_LEAF,
  C2X_CLANG_ENFORCE_TCB_LEAF,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(EnforceTCBLeafAttrSpelling) {
  return "EnforceTCBLeafAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(EnforceTCBLeafAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(EnforceTCBLeafAttrSpelling);

} // namespace mx
