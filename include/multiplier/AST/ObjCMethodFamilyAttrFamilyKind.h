// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCMethodFamilyAttrFamilyKind : unsigned char {
  NONE,
  ALLOC,
  COPY,
  INITIALIZER,
  MUTABLE_COPY,
  NEW,
};

inline static const char *EnumerationName(ObjCMethodFamilyAttrFamilyKind) {
  return "ObjCMethodFamilyAttrFamilyKind";
}

inline static constexpr unsigned NumEnumerators(ObjCMethodFamilyAttrFamilyKind) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(ObjCMethodFamilyAttrFamilyKind);

} // namespace mx
