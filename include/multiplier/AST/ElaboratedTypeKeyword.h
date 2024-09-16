// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ElaboratedTypeKeyword : unsigned char {
  STRUCT,
  INTERFACE,
  UNION,
  CLASS,
  ENUM,
  TYPENAME,
  NONE,
};

inline static const char *EnumerationName(ElaboratedTypeKeyword) {
  return "ElaboratedTypeKeyword";
}

inline static constexpr unsigned NumEnumerators(ElaboratedTypeKeyword) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(ElaboratedTypeKeyword);

} // namespace mx
