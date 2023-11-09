// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/FshlOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<FshlOp> FshlOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_FSHL) {
    return reinterpret_cast<const FshlOp &>(that);
  }
  return std::nullopt;
}

std::optional<FshlOp> FshlOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FshlOp FshlOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::FshlOp(this->Operation::op_);
}

::mx::ir::Value FshlOp::a(void) const {
  auto val = underlying_op().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FshlOp::b(void) const {
  auto val = underlying_op().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FshlOp::c(void) const {
  auto val = underlying_op().getC();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FshlOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
