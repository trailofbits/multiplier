// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCLifetime.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCLifetime e) {
  switch (e) {
    case ObjCLifetime::NONE: return "NONE";
    case ObjCLifetime::EXPLICIT_NONE: return "EXPLICIT_NONE";
    case ObjCLifetime::STRONG: return "STRONG";
    case ObjCLifetime::WEAK: return "WEAK";
    case ObjCLifetime::AUTORELEASING: return "AUTORELEASING";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
