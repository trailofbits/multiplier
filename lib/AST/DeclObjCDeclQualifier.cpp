// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DeclObjCDeclQualifier.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DeclObjCDeclQualifier e) {
  switch (e) {
    case DeclObjCDeclQualifier::NONE: return "NONE";
    case DeclObjCDeclQualifier::IN: return "IN";
    case DeclObjCDeclQualifier::INOUT: return "INOUT";
    case DeclObjCDeclQualifier::OUT: return "OUT";
    case DeclObjCDeclQualifier::BYCOPY: return "BYCOPY";
    case DeclObjCDeclQualifier::BYREF: return "BYREF";
    case DeclObjCDeclQualifier::ONEWAY: return "ONEWAY";
    case DeclObjCDeclQualifier::CS_NULLABILITY: return "CS_NULLABILITY";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
