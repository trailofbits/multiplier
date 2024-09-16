// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ConsumableAutoCastAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ConsumableAutoCastAttrSpelling e) {
  switch (e) {
    case ConsumableAutoCastAttrSpelling::GNU_CONSUMABLE_AUTO_CAST_STATE: return "GNU_CONSUMABLE_AUTO_CAST_STATE";
    case ConsumableAutoCastAttrSpelling::CXX11_CLANG_CONSUMABLE_AUTO_CAST_STATE: return "CXX11_CLANG_CONSUMABLE_AUTO_CAST_STATE";
    case ConsumableAutoCastAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
