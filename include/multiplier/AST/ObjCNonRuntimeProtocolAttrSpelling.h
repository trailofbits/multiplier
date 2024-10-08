// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCNonRuntimeProtocolAttrSpelling : unsigned char {
  GNU_OBJC_NON_RUNTIME_PROTOCOL,
  CXX11_CLANG_OBJC_NON_RUNTIME_PROTOCOL,
  C23_CLANG_OBJC_NON_RUNTIME_PROTOCOL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCNonRuntimeProtocolAttrSpelling) {
  return "ObjCNonRuntimeProtocolAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCNonRuntimeProtocolAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCNonRuntimeProtocolAttrSpelling);

} // namespace mx
