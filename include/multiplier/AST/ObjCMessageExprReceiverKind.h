// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCMessageExprReceiverKind : unsigned char {
  CLASS,
  INSTANCE,
  SUPER_CLASS,
  SUPER_INSTANCE,
};

inline static const char *EnumerationName(ObjCMessageExprReceiverKind) {
  return "ObjCMessageExprReceiverKind";
}

inline static constexpr unsigned NumEnumerators(ObjCMessageExprReceiverKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ObjCMessageExprReceiverKind);

} // namespace mx
