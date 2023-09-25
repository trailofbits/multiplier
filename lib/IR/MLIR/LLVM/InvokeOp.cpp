// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/InvokeOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<InvokeOp> InvokeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INVOKE) {
    return reinterpret_cast<const InvokeOp &>(that);
  }
  return std::nullopt;
}

std::optional<InvokeOp> InvokeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::InvokeOp InvokeOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::InvokeOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> InvokeOp::callee_operands(void) const {
  auto range = underlying_op().getCalleeOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> InvokeOp::normal_dest_operands(void) const {
  auto range = underlying_op().getNormalDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> InvokeOp::unwind_dest_operands(void) const {
  auto range = underlying_op().getUnwindDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<std::string_view> InvokeOp::callee(void) const {
  auto opt_val = underlying_op().getCallee();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

gap::generator<::mx::ir::Operand> InvokeOp::arg_operands(void) const {
  auto range = underlying_op().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::llvm
