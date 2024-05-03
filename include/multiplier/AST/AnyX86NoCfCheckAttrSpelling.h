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
enum class AnyX86NoCfCheckAttrSpelling : unsigned char {
  GNU_NOCF_CHECK,
  CXX11_GNU_NOCF_CHECK,
  C23_GNU_NOCF_CHECK,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AnyX86NoCfCheckAttrSpelling) {
  return "AnyX86NoCfCheckAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AnyX86NoCfCheckAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(AnyX86NoCfCheckAttrSpelling);

} // namespace mx
