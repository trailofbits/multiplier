// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoSpeculativeLoadHardeningAttrSpelling : unsigned char {
  GNU_NO_SPECULATIVE_LOAD_HARDENING,
  CXX11_CLANG_NO_SPECULATIVE_LOAD_HARDENING,
  C2X_CLANG_NO_SPECULATIVE_LOAD_HARDENING,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoSpeculativeLoadHardeningAttrSpelling) {
  return "NoSpeculativeLoadHardeningAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoSpeculativeLoadHardeningAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NoSpeculativeLoadHardeningAttrSpelling);

} // namespace mx
