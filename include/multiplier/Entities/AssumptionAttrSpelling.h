// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AssumptionAttrSpelling : unsigned char {
  GNU_ASSUME,
  CXX11_CLANG_ASSUME,
  C23_CLANG_ASSUME,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AssumptionAttrSpelling) {
  return "AssumptionAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AssumptionAttrSpelling) {
  return 4;
}

const char *EnumeratorName(AssumptionAttrSpelling);

} // namespace mx
