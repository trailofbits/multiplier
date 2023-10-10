// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TagTypeKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TagTypeKind e) {
  switch (e) {
    case TagTypeKind::STRUCT: return "STRUCT";
    case TagTypeKind::INTERFACE: return "INTERFACE";
    case TagTypeKind::UNION: return "UNION";
    case TagTypeKind::CLASS: return "CLASS";
    case TagTypeKind::ENUM: return "ENUM";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
