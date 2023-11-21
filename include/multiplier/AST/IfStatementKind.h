// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class IfStatementKind : unsigned char {
  ORDINARY,
  CONSTEXPR,
  CONSTEVAL_NON_NEGATED,
  CONSTEVAL_NEGATED,
};

inline static const char *EnumerationName(IfStatementKind) {
  return "IfStatementKind";
}

inline static constexpr unsigned NumEnumerators(IfStatementKind) {
  return 4;
}

const char *EnumeratorName(IfStatementKind);

} // namespace mx
