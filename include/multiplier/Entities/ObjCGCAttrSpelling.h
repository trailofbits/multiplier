// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCGCAttrSpelling : unsigned char {
  GNU_OBJC_GC,
  CXX11_CLANG_OBJC_GC,
  C2X_CLANG_OBJC_GC,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCGCAttrSpelling) {
  return "ObjCGCAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCGCAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCGCAttrSpelling);

} // namespace mx
