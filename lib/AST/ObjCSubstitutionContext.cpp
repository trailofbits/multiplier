// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCSubstitutionContext.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCSubstitutionContext e) {
  switch (e) {
    case ObjCSubstitutionContext::ORDINARY: return "ORDINARY";
    case ObjCSubstitutionContext::RESULT: return "RESULT";
    case ObjCSubstitutionContext::PARAMETER: return "PARAMETER";
    case ObjCSubstitutionContext::PROPERTY: return "PROPERTY";
    case ObjCSubstitutionContext::SUPERCLASS: return "SUPERCLASS";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
