// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/StepVectorOp.h>
#include <multiplier/IR/Value.h>

namespace mx::ir::llvm {
std::optional<StepVectorOp> StepVectorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXPERIMENTAL_STEPVECTOR) {
    return reinterpret_cast<const StepVectorOp &>(that);
  }
  return std::nullopt;
}

std::optional<StepVectorOp> StepVectorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

}  // namespace mx::ir::llvm
