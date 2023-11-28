// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCExceptionAttrSpelling : unsigned char {
  GNU_OBJC_EXCEPTION,
  CXX11_CLANG_OBJC_EXCEPTION,
  C2X_CLANG_OBJC_EXCEPTION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCExceptionAttrSpelling) {
  return "ObjCExceptionAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCExceptionAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCExceptionAttrSpelling);

} // namespace mx
