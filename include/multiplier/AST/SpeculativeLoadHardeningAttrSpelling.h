// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SpeculativeLoadHardeningAttrSpelling : unsigned char {
  GNU_SPECULATIVE_LOAD_HARDENING,
  CXX11_CLANG_SPECULATIVE_LOAD_HARDENING,
  C23_CLANG_SPECULATIVE_LOAD_HARDENING,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SpeculativeLoadHardeningAttrSpelling) {
  return "SpeculativeLoadHardeningAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SpeculativeLoadHardeningAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(SpeculativeLoadHardeningAttrSpelling);

} // namespace mx
