// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ReservedIdentifierStatus : unsigned char {
  NOT_RESERVED,
  STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE,
  STARTS_WITH_UNDERSCORE_AND_IS_EXTERN_C,
  STARTS_WITH_DOUBLE_UNDERSCORE,
  STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER,
  CONTAINS_DOUBLE_UNDERSCORE,
};

inline static const char *EnumerationName(ReservedIdentifierStatus) {
  return "ReservedIdentifierStatus";
}

inline static constexpr unsigned NumEnumerators(ReservedIdentifierStatus) {
  return 6;
}

const char *EnumeratorName(ReservedIdentifierStatus);

} // namespace mx
