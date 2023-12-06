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
enum class ObjCMethodFamily : unsigned char {
  NONE,
  ALLOC,
  COPY,
  INITIALIZER,
  MUTABLE_COPY,
  NEW,
  AUTORELEASE,
  DEALLOC,
  FINALIZE,
  RELEASE,
  RETAIN,
  RETAIN_COUNT,
  SELF,
  INITIALIZE,
  PERFORM_SELECTOR,
};

inline static const char *EnumerationName(ObjCMethodFamily) {
  return "ObjCMethodFamily";
}

inline static constexpr unsigned NumEnumerators(ObjCMethodFamily) {
  return 15;
}

MX_EXPORT const char *EnumeratorName(ObjCMethodFamily);

} // namespace mx
