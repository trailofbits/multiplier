// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TypeVisibilityAttrVisibilityType : unsigned char {
  DEFAULT,
  HIDDEN,
  PROTECTED,
};

inline static const char *EnumerationName(TypeVisibilityAttrVisibilityType) {
  return "TypeVisibilityAttrVisibilityType";
}

inline static constexpr unsigned NumEnumerators(TypeVisibilityAttrVisibilityType) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(TypeVisibilityAttrVisibilityType);

} // namespace mx
