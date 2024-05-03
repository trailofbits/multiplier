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
enum class TargetVersionAttrSpelling : unsigned char {
  GNU_TARGET_VERSION,
  CXX11_GNU_TARGET_VERSION,
  C23_GNU_TARGET_VERSION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(TargetVersionAttrSpelling) {
  return "TargetVersionAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(TargetVersionAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(TargetVersionAttrSpelling);

} // namespace mx
