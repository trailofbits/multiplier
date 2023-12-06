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
enum class EnumExtensibilityAttrKind : unsigned char {
  CLOSED,
  OPEN,
};

inline static const char *EnumerationName(EnumExtensibilityAttrKind) {
  return "EnumExtensibilityAttrKind";
}

inline static constexpr unsigned NumEnumerators(EnumExtensibilityAttrKind) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(EnumExtensibilityAttrKind);

} // namespace mx
