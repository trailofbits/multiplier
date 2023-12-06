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
enum class ObjCInstanceTypeFamily : unsigned char {
  NONE,
  ARRAY,
  DICTIONARY,
  SINGLETON,
  INITIALIZER,
  RETURNS_SELF,
};

inline static const char *EnumerationName(ObjCInstanceTypeFamily) {
  return "ObjCInstanceTypeFamily";
}

inline static constexpr unsigned NumEnumerators(ObjCInstanceTypeFamily) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(ObjCInstanceTypeFamily);

} // namespace mx
