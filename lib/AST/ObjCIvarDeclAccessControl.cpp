// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCIvarDeclAccessControl.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCIvarDeclAccessControl e) {
  switch (e) {
    case ObjCIvarDeclAccessControl::NONE: return "NONE";
    case ObjCIvarDeclAccessControl::PRIVATE: return "PRIVATE";
    case ObjCIvarDeclAccessControl::PROTECTED: return "PROTECTED";
    case ObjCIvarDeclAccessControl::PUBLIC: return "PUBLIC";
    case ObjCIvarDeclAccessControl::PACKAGE: return "PACKAGE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
