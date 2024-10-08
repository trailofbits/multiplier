// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ObjCDispatchMethodKind : unsigned char {
  LEGACY,
  NON_LEGACY,
  MIXED,
};

inline static const char *EnumerationName(ObjCDispatchMethodKind) {
  return "ObjCDispatchMethodKind";
}

inline static constexpr unsigned NumEnumerators(ObjCDispatchMethodKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ObjCDispatchMethodKind);

} // namespace mx
