// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCMessageExprReceiverKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCMessageExprReceiverKind e) {
  switch (e) {
    case ObjCMessageExprReceiverKind::CLASS: return "CLASS";
    case ObjCMessageExprReceiverKind::INSTANCE: return "INSTANCE";
    case ObjCMessageExprReceiverKind::SUPER_CLASS: return "SUPER_CLASS";
    case ObjCMessageExprReceiverKind::SUPER_INSTANCE: return "SUPER_INSTANCE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
