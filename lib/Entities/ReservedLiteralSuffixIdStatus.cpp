// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ReservedLiteralSuffixIdStatus.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ReservedLiteralSuffixIdStatus e) {
  switch (e) {
    case ReservedLiteralSuffixIdStatus::NOT_RESERVED: return "NOT_RESERVED";
    case ReservedLiteralSuffixIdStatus::NOT_STARTS_WITH_UNDERSCORE: return "NOT_STARTS_WITH_UNDERSCORE";
    case ReservedLiteralSuffixIdStatus::CONTAINS_DOUBLE_UNDERSCORE: return "CONTAINS_DOUBLE_UNDERSCORE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
