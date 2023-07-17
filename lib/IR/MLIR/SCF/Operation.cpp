// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/Operation.h>

namespace mx::ir::scf {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::SCF_CONDITION:
    case mx::ir::OperationKind::SCF_EXECUTE_REGION:
    case mx::ir::OperationKind::SCF_FOR:
    case mx::ir::OperationKind::SCF_FOREACH_THREAD:
    case mx::ir::OperationKind::SCF_IF:
    case mx::ir::OperationKind::SCF_INDEX_SWITCH:
    case mx::ir::OperationKind::SCF_PARALLEL:
    case mx::ir::OperationKind::SCF_FOREACH_THREAD_PERFORM_CONCURRENTLY:
    case mx::ir::OperationKind::SCF_REDUCE:
    case mx::ir::OperationKind::SCF_REDUCE_RETURN:
    case mx::ir::OperationKind::SCF_WHILE:
    case mx::ir::OperationKind::SCF_YIELD:
      return reinterpret_cast<const Operation &>(that);
  }
}

}  // namespace mx::ir::scf
