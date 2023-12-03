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
enum class ObjCBridgeMutableAttrSpelling : unsigned char {
  GNU_OBJC_BRIDGE_MUTABLE,
  CXX11_CLANG_OBJC_BRIDGE_MUTABLE,
  C2X_CLANG_OBJC_BRIDGE_MUTABLE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCBridgeMutableAttrSpelling) {
  return "ObjCBridgeMutableAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCBridgeMutableAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCBridgeMutableAttrSpelling);

} // namespace mx
