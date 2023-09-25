// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/CopySignOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<CopySignOp> CopySignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_COPYSIGN) {
    return reinterpret_cast<const CopySignOp &>(that);
  }
  return std::nullopt;
}

std::optional<CopySignOp> CopySignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CopySignOp CopySignOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::CopySignOp(this->Operation::op_);
}

::mx::ir::Value CopySignOp::a(void) const {
  auto val = underlying_op().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CopySignOp::b(void) const {
  auto val = underlying_op().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CopySignOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
