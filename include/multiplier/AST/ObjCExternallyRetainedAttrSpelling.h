// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCExternallyRetainedAttrSpelling : unsigned char {
  GNU_OBJC_EXTERNALLY_RETAINED,
  CXX11_CLANG_OBJC_EXTERNALLY_RETAINED,
  C23_CLANG_OBJC_EXTERNALLY_RETAINED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCExternallyRetainedAttrSpelling) {
  return "ObjCExternallyRetainedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCExternallyRetainedAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCExternallyRetainedAttrSpelling);

} // namespace mx
