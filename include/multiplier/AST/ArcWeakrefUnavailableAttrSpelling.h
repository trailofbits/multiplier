// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ArcWeakrefUnavailableAttrSpelling : unsigned char {
  GNU_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE,
  CXX11_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE,
  C23_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ArcWeakrefUnavailableAttrSpelling) {
  return "ArcWeakrefUnavailableAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ArcWeakrefUnavailableAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ArcWeakrefUnavailableAttrSpelling);

} // namespace mx
