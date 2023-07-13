// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/CountTrailingZerosOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<CountTrailingZerosOp> CountTrailingZerosOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CTTZ) {
    return reinterpret_cast<const CountTrailingZerosOp &>(that);
  }
  return std::nullopt;
}

std::optional<CountTrailingZerosOp> CountTrailingZerosOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CountTrailingZerosOp CountTrailingZerosOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::CountTrailingZerosOp(this->Operation::op_);
}

}  // namespace mx::ir::llvm
