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
enum class SwiftNewTypeAttrSpelling : unsigned char {
  GNU_SWIFT_NEWTYPE,
  GNU_SWIFT_WRAPPER,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SwiftNewTypeAttrSpelling) {
  return "SwiftNewTypeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SwiftNewTypeAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(SwiftNewTypeAttrSpelling);

} // namespace mx
