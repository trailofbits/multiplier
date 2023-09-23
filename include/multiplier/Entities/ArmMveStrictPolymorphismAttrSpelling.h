// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ArmMveStrictPolymorphismAttrSpelling : unsigned char {
  GNU_CLANG_ARM_MVE_STRICT_POLYMORPHISM,
  CXX11_CLANG_CLANG_ARM_MVE_STRICT_POLYMORPHISM,
  C23_CLANG_CLANG_ARM_MVE_STRICT_POLYMORPHISM,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ArmMveStrictPolymorphismAttrSpelling) {
  return "ArmMveStrictPolymorphismAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ArmMveStrictPolymorphismAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ArmMveStrictPolymorphismAttrSpelling);

} // namespace mx
