// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MayAliasAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MayAliasAttrSpelling e) {
  switch (e) {
    case MayAliasAttrSpelling::GNU_MAY_ALIAS: return "GNU_MAY_ALIAS";
    case MayAliasAttrSpelling::CXX11_GNU_MAY_ALIAS: return "CXX11_GNU_MAY_ALIAS";
    case MayAliasAttrSpelling::C23_GNU_MAY_ALIAS: return "C23_GNU_MAY_ALIAS";
    case MayAliasAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
