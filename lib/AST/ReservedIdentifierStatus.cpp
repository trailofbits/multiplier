// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ReservedIdentifierStatus.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ReservedIdentifierStatus e) {
  switch (e) {
    case ReservedIdentifierStatus::NOT_RESERVED: return "NOT_RESERVED";
    case ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE: return "STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE";
    case ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_AND_IS_EXTERN_C: return "STARTS_WITH_UNDERSCORE_AND_IS_EXTERN_C";
    case ReservedIdentifierStatus::STARTS_WITH_DOUBLE_UNDERSCORE: return "STARTS_WITH_DOUBLE_UNDERSCORE";
    case ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER: return "STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER";
    case ReservedIdentifierStatus::CONTAINS_DOUBLE_UNDERSCORE: return "CONTAINS_DOUBLE_UNDERSCORE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
