// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class AArch64SVEPcsAttrSpelling : unsigned char {
  GNU_AARCH64_SVE_PCS,
  CXX11_CLANG_AARCH64_SVE_PCS,
  C23_CLANG_AARCH64_SVE_PCS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AArch64SVEPcsAttrSpelling) {
  return "AArch64SVEPcsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AArch64SVEPcsAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AArch64SVEPcsAttrSpelling);

} // namespace mx
