// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SubExpr : unsigned char {
  CALLEE,
  LHS,
  RHS,
  COUNT,
};

inline static const char *EnumerationName(SubExpr) {
  return "SubExpr";
}

inline static constexpr unsigned NumEnumerators(SubExpr) {
  return 4;
}

const char *EnumeratorName(SubExpr);

} // namespace mx
