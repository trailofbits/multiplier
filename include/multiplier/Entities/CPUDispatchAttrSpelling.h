// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CPUDispatchAttrSpelling : unsigned char {
  GNU_CPU_DISPATCH,
  CXX11_CLANG_CPU_DISPATCH,
  C23_CLANG_CPU_DISPATCH,
  DECLSPEC_CPU_DISPATCH,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CPUDispatchAttrSpelling) {
  return "CPUDispatchAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CPUDispatchAttrSpelling) {
  return 5;
}

const char *EnumeratorName(CPUDispatchAttrSpelling);

} // namespace mx
