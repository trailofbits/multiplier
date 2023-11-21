// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DeclModuleOwnershipKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DeclModuleOwnershipKind e) {
  switch (e) {
    case DeclModuleOwnershipKind::UNOWNED: return "UNOWNED";
    case DeclModuleOwnershipKind::VISIBLE: return "VISIBLE";
    case DeclModuleOwnershipKind::VISIBLE_WHEN_IMPORTED: return "VISIBLE_WHEN_IMPORTED";
    case DeclModuleOwnershipKind::REACHABLE_WHEN_IMPORTED: return "REACHABLE_WHEN_IMPORTED";
    case DeclModuleOwnershipKind::MODULE_PRIVATE: return "MODULE_PRIVATE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
