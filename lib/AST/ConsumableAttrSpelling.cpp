// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ConsumableAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ConsumableAttrSpelling e) {
  switch (e) {
    case ConsumableAttrSpelling::GNU_CONSUMABLE: return "GNU_CONSUMABLE";
    case ConsumableAttrSpelling::CXX11_CLANG_CONSUMABLE: return "CXX11_CLANG_CONSUMABLE";
    case ConsumableAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
