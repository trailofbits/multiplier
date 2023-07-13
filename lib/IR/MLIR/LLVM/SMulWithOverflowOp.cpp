// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/SMulWithOverflowOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<SMulWithOverflowOp> SMulWithOverflowOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SMUL_WITH_OVERFLOW) {
    return reinterpret_cast<const SMulWithOverflowOp &>(that);
  }
  return std::nullopt;
}

std::optional<SMulWithOverflowOp> SMulWithOverflowOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SMulWithOverflowOp SMulWithOverflowOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::SMulWithOverflowOp(this->Operation::op_);
}

}  // namespace mx::ir::llvm
