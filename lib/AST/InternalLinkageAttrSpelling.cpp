// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/InternalLinkageAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(InternalLinkageAttrSpelling e) {
  switch (e) {
    case InternalLinkageAttrSpelling::GNU_INTERNAL_LINKAGE: return "GNU_INTERNAL_LINKAGE";
    case InternalLinkageAttrSpelling::CXX11_CLANG_INTERNAL_LINKAGE: return "CXX11_CLANG_INTERNAL_LINKAGE";
    case InternalLinkageAttrSpelling::C2X_CLANG_INTERNAL_LINKAGE: return "C2X_CLANG_INTERNAL_LINKAGE";
    case InternalLinkageAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
