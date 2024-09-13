// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class WarnUnusedResultAttrSpelling : unsigned char {
  CXX11_NODISCARD,
  C23_NODISCARD,
  CXX11_CLANG_WARN_UNUSED_RESULT,
  GNU_WARN_UNUSED_RESULT,
  CXX11_GNU_WARN_UNUSED_RESULT,
  C23_GNU_WARN_UNUSED_RESULT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(WarnUnusedResultAttrSpelling) {
  return "WarnUnusedResultAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(WarnUnusedResultAttrSpelling) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(WarnUnusedResultAttrSpelling);

} // namespace mx
