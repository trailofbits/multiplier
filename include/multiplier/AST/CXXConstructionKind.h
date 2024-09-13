// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CXXConstructionKind : unsigned char {
  COMPLETE,
  NON_VIRTUAL_BASE,
  VIRTUAL_BASE,
  DELEGATING,
};

inline static const char *EnumerationName(CXXConstructionKind) {
  return "CXXConstructionKind";
}

inline static constexpr unsigned NumEnumerators(CXXConstructionKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CXXConstructionKind);

} // namespace mx
