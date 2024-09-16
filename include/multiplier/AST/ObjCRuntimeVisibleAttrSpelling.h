// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCRuntimeVisibleAttrSpelling : unsigned char {
  GNU_OBJC_RUNTIME_VISIBLE,
  CXX11_CLANG_OBJC_RUNTIME_VISIBLE,
  C23_CLANG_OBJC_RUNTIME_VISIBLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCRuntimeVisibleAttrSpelling) {
  return "ObjCRuntimeVisibleAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCRuntimeVisibleAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCRuntimeVisibleAttrSpelling);

} // namespace mx
