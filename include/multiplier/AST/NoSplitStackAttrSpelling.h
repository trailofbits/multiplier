// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NoSplitStackAttrSpelling : unsigned char {
  GNU_NO_SPLIT_STACK,
  CXX11_GNU_NO_SPLIT_STACK,
  C23_GNU_NO_SPLIT_STACK,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoSplitStackAttrSpelling) {
  return "NoSplitStackAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoSplitStackAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(NoSplitStackAttrSpelling);

} // namespace mx
