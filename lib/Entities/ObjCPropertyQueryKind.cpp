// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCPropertyQueryKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCPropertyQueryKind e) {
  switch (e) {
    case ObjCPropertyQueryKind::QUERY_UNKNOWN: return "QUERY_UNKNOWN";
    case ObjCPropertyQueryKind::QUERY_INSTANCE: return "QUERY_INSTANCE";
    case ObjCPropertyQueryKind::QUERY_CLASS: return "QUERY_CLASS";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
