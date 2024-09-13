// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCStringFormatFamily : unsigned char {
  NONE,
  NS_STRING,
  CF_STRING,
};

inline static const char *EnumerationName(ObjCStringFormatFamily) {
  return "ObjCStringFormatFamily";
}

inline static constexpr unsigned NumEnumerators(ObjCStringFormatFamily) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ObjCStringFormatFamily);

} // namespace mx
