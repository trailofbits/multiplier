// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/CoroBeginOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<CoroBeginOp> CoroBeginOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_BEGIN) {
    return reinterpret_cast<const CoroBeginOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroBeginOp> CoroBeginOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroBeginOp CoroBeginOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::CoroBeginOp(this->Operation::op_);
}

::mx::ir::Value CoroBeginOp::token(void) const {
  auto val = underlying_op().getToken();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CoroBeginOp::mem(void) const {
  auto val = underlying_op().getMem();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CoroBeginOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
