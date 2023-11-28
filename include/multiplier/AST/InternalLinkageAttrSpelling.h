// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class InternalLinkageAttrSpelling : unsigned char {
  GNU_INTERNAL_LINKAGE,
  CXX11_CLANG_INTERNAL_LINKAGE,
  C2X_CLANG_INTERNAL_LINKAGE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(InternalLinkageAttrSpelling) {
  return "InternalLinkageAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(InternalLinkageAttrSpelling) {
  return 4;
}

const char *EnumeratorName(InternalLinkageAttrSpelling);

} // namespace mx
