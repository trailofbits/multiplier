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
enum class FallThroughAttrSpelling : unsigned char {
  CXX11_FALLTHROUGH,
  C23_FALLTHROUGH,
  CXX11_CLANG_FALLTHROUGH,
  GNU_FALLTHROUGH,
  CXX11_GNU_FALLTHROUGH,
  C23_GNU_FALLTHROUGH,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(FallThroughAttrSpelling) {
  return "FallThroughAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(FallThroughAttrSpelling) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(FallThroughAttrSpelling);

} // namespace mx
