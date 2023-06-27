// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/Operation.h>

namespace mx::ir::ll {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::LL_BR:
    case mx::ir::OperationKind::LL_COND_BR:
    case mx::ir::OperationKind::LL_COND_SCOPE_RET:
    case mx::ir::OperationKind::LL_INITIALIZE:
    case mx::ir::OperationKind::LL_INLINE_SCOPE:
    case mx::ir::OperationKind::LL_GEP:
    case mx::ir::OperationKind::LL_RETURN:
    case mx::ir::OperationKind::LL_SCOPE:
    case mx::ir::OperationKind::LL_SCOPE_RECURSE:
    case mx::ir::OperationKind::LL_SCOPE_RET:
    case mx::ir::OperationKind::LL_UNINITIALIZED_VAR:
      return reinterpret_cast<const Operation &>(that);
  }
}

}  // namespace mx::ir::ll
