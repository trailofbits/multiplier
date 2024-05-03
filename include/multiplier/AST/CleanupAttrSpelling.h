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
enum class CleanupAttrSpelling : unsigned char {
  GNU_CLEANUP,
  CXX11_GNU_CLEANUP,
  C23_GNU_CLEANUP,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CleanupAttrSpelling) {
  return "CleanupAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CleanupAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CleanupAttrSpelling);

} // namespace mx
