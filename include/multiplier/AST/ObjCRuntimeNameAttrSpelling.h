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
enum class ObjCRuntimeNameAttrSpelling : unsigned char {
  GNU_OBJC_RUNTIME_NAME,
  CXX11_CLANG_OBJC_RUNTIME_NAME,
  C2X_CLANG_OBJC_RUNTIME_NAME,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCRuntimeNameAttrSpelling) {
  return "ObjCRuntimeNameAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCRuntimeNameAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCRuntimeNameAttrSpelling);

} // namespace mx
