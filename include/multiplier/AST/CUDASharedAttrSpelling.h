// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CUDASharedAttrSpelling : unsigned char {
  GNU_SHARED,
  DECLSPEC_SHARED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CUDASharedAttrSpelling) {
  return "CUDASharedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CUDASharedAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(CUDASharedAttrSpelling);

} // namespace mx
