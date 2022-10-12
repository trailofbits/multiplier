// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AsmLabelAttrSpelling : unsigned char {
  KEYWORD_ASSEMBLY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AsmLabelAttrSpelling) {
  return "AsmLabelAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AsmLabelAttrSpelling) {
  return 2;
}

const char *EnumeratorName(AsmLabelAttrSpelling);

} // namespace mx
