// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CFConsumedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CFConsumedAttrSpelling e) {
  switch (e) {
    case CFConsumedAttrSpelling::GNU_CF_CONSUMED: return "GNU_CF_CONSUMED";
    case CFConsumedAttrSpelling::CXX11_CLANG_CF_CONSUMED: return "CXX11_CLANG_CF_CONSUMED";
    case CFConsumedAttrSpelling::C23_CLANG_CF_CONSUMED: return "C23_CLANG_CF_CONSUMED";
    case CFConsumedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
