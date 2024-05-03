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
enum class NotTailCalledAttrSpelling : unsigned char {
  GNU_NOT_TAIL_CALLED,
  CXX11_CLANG_NOT_TAIL_CALLED,
  C23_CLANG_NOT_TAIL_CALLED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NotTailCalledAttrSpelling) {
  return "NotTailCalledAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NotTailCalledAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NotTailCalledAttrSpelling);

} // namespace mx
