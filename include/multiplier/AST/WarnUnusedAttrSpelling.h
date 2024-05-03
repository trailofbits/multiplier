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
enum class WarnUnusedAttrSpelling : unsigned char {
  GNU_WARN_UNUSED,
  CXX11_GNU_WARN_UNUSED,
  C23_GNU_WARN_UNUSED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(WarnUnusedAttrSpelling) {
  return "WarnUnusedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(WarnUnusedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(WarnUnusedAttrSpelling);

} // namespace mx
