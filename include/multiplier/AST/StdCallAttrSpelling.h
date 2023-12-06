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
enum class StdCallAttrSpelling : unsigned char {
  GNU_STDCALL,
  CXX11_GNU_STDCALL,
  C2X_GNU_STDCALL,
  KEYWORD_STDCALL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(StdCallAttrSpelling) {
  return "StdCallAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(StdCallAttrSpelling) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(StdCallAttrSpelling);

} // namespace mx
