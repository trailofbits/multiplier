// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class UserDefinedLiteralLiteralOperatorKind : unsigned char {
  RAW,
  TEMPLATE,
  INTEGER,
  FLOATING,
  STRING,
  CHARACTER,
};

inline static const char *EnumerationName(UserDefinedLiteralLiteralOperatorKind) {
  return "UserDefinedLiteralLiteralOperatorKind";
}

inline static constexpr unsigned NumEnumerators(UserDefinedLiteralLiteralOperatorKind) {
  return 6;
}

const char *EnumeratorName(UserDefinedLiteralLiteralOperatorKind);

} // namespace mx
