// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ReservedLiteralSuffixIdStatus : unsigned char {
  NOT_RESERVED,
  NOT_STARTS_WITH_UNDERSCORE,
  CONTAINS_DOUBLE_UNDERSCORE,
};

inline static const char *EnumerationName(ReservedLiteralSuffixIdStatus) {
  return "ReservedLiteralSuffixIdStatus";
}

inline static constexpr unsigned NumEnumerators(ReservedLiteralSuffixIdStatus) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(ReservedLiteralSuffixIdStatus);

} // namespace mx
