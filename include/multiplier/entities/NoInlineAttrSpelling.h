// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoInlineAttrSpelling : unsigned char {
  GNU_NOINLINE,
  CXX11_GNU_NOINLINE,
  C2X_GNU_NOINLINE,
  DECLSPEC_NOINLINE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoInlineAttrSpelling) {
  return "NoInlineAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoInlineAttrSpelling) {
  return 5;
}

const char *EnumeratorName(NoInlineAttrSpelling);

} // namespace mx
