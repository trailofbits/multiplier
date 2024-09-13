// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCBridgeMutableAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCBridgeMutableAttrSpelling e) {
  switch (e) {
    case ObjCBridgeMutableAttrSpelling::GNU_OBJC_BRIDGE_MUTABLE: return "GNU_OBJC_BRIDGE_MUTABLE";
    case ObjCBridgeMutableAttrSpelling::CXX11_CLANG_OBJC_BRIDGE_MUTABLE: return "CXX11_CLANG_OBJC_BRIDGE_MUTABLE";
    case ObjCBridgeMutableAttrSpelling::C23_CLANG_OBJC_BRIDGE_MUTABLE: return "C23_CLANG_OBJC_BRIDGE_MUTABLE";
    case ObjCBridgeMutableAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
