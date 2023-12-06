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
enum class ObjCPropertyQueryKind : unsigned char {
  QUERY_UNKNOWN,
  QUERY_INSTANCE,
  QUERY_CLASS,
};

inline static const char *EnumerationName(ObjCPropertyQueryKind) {
  return "ObjCPropertyQueryKind";
}

inline static constexpr unsigned NumEnumerators(ObjCPropertyQueryKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ObjCPropertyQueryKind);

} // namespace mx
