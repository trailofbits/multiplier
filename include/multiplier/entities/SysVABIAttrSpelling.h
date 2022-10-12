// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SysVABIAttrSpelling : unsigned char {
  GNU_SYSV_ABI,
  CXX11_GNU_SYSV_ABI,
  C2X_GNU_SYSV_ABI,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SysVABIAttrSpelling) {
  return "SysVABIAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SysVABIAttrSpelling) {
  return 4;
}

const char *EnumeratorName(SysVABIAttrSpelling);

} // namespace mx
