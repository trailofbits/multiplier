// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCPropertyImplDeclKind : unsigned char {
  SYNTHESIZE,
  DYNAMIC,
};

inline static const char *EnumerationName(ObjCPropertyImplDeclKind) {
  return "ObjCPropertyImplDeclKind";
}

inline static constexpr unsigned NumEnumerators(ObjCPropertyImplDeclKind) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(ObjCPropertyImplDeclKind);

} // namespace mx
