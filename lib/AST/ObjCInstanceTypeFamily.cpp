// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCInstanceTypeFamily.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCInstanceTypeFamily e) {
  switch (e) {
    case ObjCInstanceTypeFamily::NONE: return "NONE";
    case ObjCInstanceTypeFamily::ARRAY: return "ARRAY";
    case ObjCInstanceTypeFamily::DICTIONARY: return "DICTIONARY";
    case ObjCInstanceTypeFamily::SINGLETON: return "SINGLETON";
    case ObjCInstanceTypeFamily::INITIALIZER: return "INITIALIZER";
    case ObjCInstanceTypeFamily::RETURNS_SELF: return "RETURNS_SELF";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
