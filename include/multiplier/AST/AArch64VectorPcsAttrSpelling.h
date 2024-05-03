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
enum class AArch64VectorPcsAttrSpelling : unsigned char {
  GNU_AARCH64_VECTOR_PCS,
  CXX11_CLANG_AARCH64_VECTOR_PCS,
  C23_CLANG_AARCH64_VECTOR_PCS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AArch64VectorPcsAttrSpelling) {
  return "AArch64VectorPcsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AArch64VectorPcsAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AArch64VectorPcsAttrSpelling);

} // namespace mx
