// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ConstexprSpecKind : unsigned char {
  UNSPECIFIED,
  CONSTEXPR,
  CONSTEVAL,
  CONSTINIT,
};

inline static const char *EnumerationName(ConstexprSpecKind) {
  return "ConstexprSpecKind";
}

inline static constexpr unsigned NumEnumerators(ConstexprSpecKind) {
  return 4;
}

const char *EnumeratorName(ConstexprSpecKind);

} // namespace mx
