// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SpecifierKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SpecifierKind e) {
  switch (e) {
    case SpecifierKind::IDENTIFIER: return "IDENTIFIER";
    case SpecifierKind::NAMESPACE: return "NAMESPACE";
    case SpecifierKind::NAMESPACE_ALIAS: return "NAMESPACE_ALIAS";
    case SpecifierKind::TYPE_SPEC: return "TYPE_SPEC";
    case SpecifierKind::TYPE_SPEC_WITH_TEMPLATE: return "TYPE_SPEC_WITH_TEMPLATE";
    case SpecifierKind::GLOBAL: return "GLOBAL";
    case SpecifierKind::SUPER: return "SUPER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
