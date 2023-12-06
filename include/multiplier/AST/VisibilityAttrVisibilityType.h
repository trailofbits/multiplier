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
enum class VisibilityAttrVisibilityType : unsigned char {
  DEFAULT,
  HIDDEN,
  PROTECTED,
};

inline static const char *EnumerationName(VisibilityAttrVisibilityType) {
  return "VisibilityAttrVisibilityType";
}

inline static constexpr unsigned NumEnumerators(VisibilityAttrVisibilityType) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(VisibilityAttrVisibilityType);

} // namespace mx
