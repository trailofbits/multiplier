// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCClassStubAttrSpelling : unsigned char {
  GNU_OBJC_CLASS_STUB,
  CXX11_CLANG_OBJC_CLASS_STUB,
  C23_CLANG_OBJC_CLASS_STUB,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCClassStubAttrSpelling) {
  return "ObjCClassStubAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCClassStubAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCClassStubAttrSpelling);

} // namespace mx
