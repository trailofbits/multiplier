// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/StoredSpecifierKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StoredSpecifierKind e) {
  switch (e) {
    case StoredSpecifierKind::STORED_IDENTIFIER: return "STORED_IDENTIFIER";
    case StoredSpecifierKind::STORED_DECLARATION: return "STORED_DECLARATION";
    case StoredSpecifierKind::STORED_TYPE_SPEC: return "STORED_TYPE_SPEC";
    case StoredSpecifierKind::STORED_TYPE_SPEC_WITH_TEMPLATE: return "STORED_TYPE_SPEC_WITH_TEMPLATE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
