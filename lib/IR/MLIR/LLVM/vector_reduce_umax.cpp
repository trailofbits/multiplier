// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/vector_reduce_umax.h>
#include <multiplier/IR/Value.h>

namespace mx::ir::llvm {
std::optional<vector_reduce_umax> vector_reduce_umax::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_UMAX) {
    return reinterpret_cast<const vector_reduce_umax &>(that);
  }
  return std::nullopt;
}

std::optional<vector_reduce_umax> vector_reduce_umax::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

}  // namespace mx::ir::llvm
