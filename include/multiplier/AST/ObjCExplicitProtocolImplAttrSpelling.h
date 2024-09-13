// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCExplicitProtocolImplAttrSpelling : unsigned char {
  GNU_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION,
  CXX11_CLANG_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION,
  C23_CLANG_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCExplicitProtocolImplAttrSpelling) {
  return "ObjCExplicitProtocolImplAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCExplicitProtocolImplAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCExplicitProtocolImplAttrSpelling);

} // namespace mx
