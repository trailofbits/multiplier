// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ComparisonCategoryType.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ComparisonCategoryType e) {
  switch (e) {
    case ComparisonCategoryType::PARTIAL_ORDERING: return "PARTIAL_ORDERING";
    case ComparisonCategoryType::WEAK_ORDERING: return "WEAK_ORDERING";
    case ComparisonCategoryType::STRONG_ORDERING: return "STRONG_ORDERING";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
