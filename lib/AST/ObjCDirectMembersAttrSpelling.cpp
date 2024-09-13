// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCDirectMembersAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCDirectMembersAttrSpelling e) {
  switch (e) {
    case ObjCDirectMembersAttrSpelling::GNU_OBJC_DIRECT_MEMBERS: return "GNU_OBJC_DIRECT_MEMBERS";
    case ObjCDirectMembersAttrSpelling::CXX11_CLANG_OBJC_DIRECT_MEMBERS: return "CXX11_CLANG_OBJC_DIRECT_MEMBERS";
    case ObjCDirectMembersAttrSpelling::C23_CLANG_OBJC_DIRECT_MEMBERS: return "C23_CLANG_OBJC_DIRECT_MEMBERS";
    case ObjCDirectMembersAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
