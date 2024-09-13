// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TagTypeKind : unsigned char {
  STRUCT,
  INTERFACE,
  UNION,
  CLASS,
  ENUM,
};

inline static const char *EnumerationName(TagTypeKind) {
  return "TagTypeKind";
}

inline static constexpr unsigned NumEnumerators(TagTypeKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(TagTypeKind);

} // namespace mx
