// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class IntelOclBiccAttrSpelling : unsigned char {
  GNU_INTEL_OCL_BICC,
  CXX11_CLANG_INTEL_OCL_BICC,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(IntelOclBiccAttrSpelling) {
  return "IntelOclBiccAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(IntelOclBiccAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(IntelOclBiccAttrSpelling);

} // namespace mx
