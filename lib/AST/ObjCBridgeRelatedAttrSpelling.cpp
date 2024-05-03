// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCBridgeRelatedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCBridgeRelatedAttrSpelling e) {
  switch (e) {
    case ObjCBridgeRelatedAttrSpelling::GNU_OBJC_BRIDGE_RELATED: return "GNU_OBJC_BRIDGE_RELATED";
    case ObjCBridgeRelatedAttrSpelling::CXX11_CLANG_OBJC_BRIDGE_RELATED: return "CXX11_CLANG_OBJC_BRIDGE_RELATED";
    case ObjCBridgeRelatedAttrSpelling::C23_CLANG_OBJC_BRIDGE_RELATED: return "C23_CLANG_OBJC_BRIDGE_RELATED";
    case ObjCBridgeRelatedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
