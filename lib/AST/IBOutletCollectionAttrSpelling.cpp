// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/IBOutletCollectionAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(IBOutletCollectionAttrSpelling e) {
  switch (e) {
    case IBOutletCollectionAttrSpelling::GNU_IBOUTLETCOLLECTION: return "GNU_IBOUTLETCOLLECTION";
    case IBOutletCollectionAttrSpelling::CXX11_CLANG_IBOUTLETCOLLECTION: return "CXX11_CLANG_IBOUTLETCOLLECTION";
    case IBOutletCollectionAttrSpelling::C23_CLANG_IBOUTLETCOLLECTION: return "C23_CLANG_IBOUTLETCOLLECTION";
    case IBOutletCollectionAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
