// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ComparisonCategoryResult.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ComparisonCategoryResult e) {
  switch (e) {
    case ComparisonCategoryResult::EQUAL: return "EQUAL";
    case ComparisonCategoryResult::EQUIVALENT: return "EQUIVALENT";
    case ComparisonCategoryResult::LESS: return "LESS";
    case ComparisonCategoryResult::GREATER: return "GREATER";
    case ComparisonCategoryResult::UNORDERED: return "UNORDERED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
