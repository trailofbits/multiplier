// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class EnforceTCBAttrSpelling : unsigned char {
  GNU_ENFORCE_TCB,
  CXX11_CLANG_ENFORCE_TCB,
  C23_CLANG_ENFORCE_TCB,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(EnforceTCBAttrSpelling) {
  return "EnforceTCBAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(EnforceTCBAttrSpelling) {
  return 4;
}

const char *EnumeratorName(EnforceTCBAttrSpelling);

} // namespace mx
