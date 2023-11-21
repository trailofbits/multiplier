// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/ABI/Operation.h>

namespace mx::ir::abi {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::ABI_CALL_ARGS:
    case mx::ir::OperationKind::ABI_CALL_EXEC:
    case mx::ir::OperationKind::ABI_CALL:
    case mx::ir::OperationKind::ABI_CALL_RETS:
    case mx::ir::OperationKind::ABI_DIRECT:
    case mx::ir::OperationKind::ABI_EPILOGUE:
    case mx::ir::OperationKind::ABI_FUNC:
    case mx::ir::OperationKind::ABI_PROLOGUE:
    case mx::ir::OperationKind::ABI_RET_DIRECT:
    case mx::ir::OperationKind::ABI_TODO:
    case mx::ir::OperationKind::ABI_WRAP_FN:
    case mx::ir::OperationKind::ABI_YIELD:
      return reinterpret_cast<const Operation &>(that);
  }
}

}  // namespace mx::ir::abi
