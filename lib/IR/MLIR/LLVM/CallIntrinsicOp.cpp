// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/CallIntrinsicOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<CallIntrinsicOp> CallIntrinsicOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_CALL_INTRINSIC) {
    return reinterpret_cast<const CallIntrinsicOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallIntrinsicOp> CallIntrinsicOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CallIntrinsicOp CallIntrinsicOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::CallIntrinsicOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> CallIntrinsicOp::args(void) const {
  auto range = underlying_op().getArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> CallIntrinsicOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

std::string_view CallIntrinsicOp::intrin(void) const {
  auto val = underlying_op().getIntrin();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::llvm
