// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class LoopHintAttrSpelling : unsigned char {
  PRAGMA_CLANG_LOOP,
  PRAGMA_UNROLL,
  PRAGMA_NOUNROLL,
  PRAGMA_UNROLL_AND_JAM,
  PRAGMA_NOUNROLL_AND_JAM,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(LoopHintAttrSpelling) {
  return "LoopHintAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(LoopHintAttrSpelling) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(LoopHintAttrSpelling);

} // namespace mx
