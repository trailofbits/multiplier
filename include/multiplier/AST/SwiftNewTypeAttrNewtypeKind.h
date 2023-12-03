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
enum class SwiftNewTypeAttrNewtypeKind : unsigned char {
  STRUCT,
  ENUM,
};

inline static const char *EnumerationName(SwiftNewTypeAttrNewtypeKind) {
  return "SwiftNewTypeAttrNewtypeKind";
}

inline static constexpr unsigned NumEnumerators(SwiftNewTypeAttrNewtypeKind) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(SwiftNewTypeAttrNewtypeKind);

} // namespace mx
