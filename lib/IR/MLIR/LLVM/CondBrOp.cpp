// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/CondBrOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<CondBrOp> CondBrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_COND_BR) {
    return reinterpret_cast<const CondBrOp &>(that);
  }
  return std::nullopt;
}

std::optional<CondBrOp> CondBrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CondBrOp CondBrOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::CondBrOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> CondBrOp::true_dest_operands(void) const {
  auto range = underlying_op().getTrueDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> CondBrOp::false_dest_operands(void) const {
  auto range = underlying_op().getFalseDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::llvm
