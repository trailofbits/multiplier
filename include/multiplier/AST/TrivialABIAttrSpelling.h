// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TrivialABIAttrSpelling : unsigned char {
  GNU_TRIVIAL_ABI,
  CXX11_CLANG_TRIVIAL_ABI,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(TrivialABIAttrSpelling) {
  return "TrivialABIAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(TrivialABIAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(TrivialABIAttrSpelling);

} // namespace mx
