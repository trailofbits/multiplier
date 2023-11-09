// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/AbsOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<AbsOp> AbsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_ABS) {
    return reinterpret_cast<const AbsOp &>(that);
  }
  return std::nullopt;
}

std::optional<AbsOp> AbsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AbsOp AbsOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::AbsOp(this->Operation::op_);
}

::mx::ir::Value AbsOp::in(void) const {
  auto val = underlying_op().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AbsOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool AbsOp::is_int_min_poison(void) const {
  auto val = underlying_op().getIsIntMinPoison();
  return val;
}

}  // namespace mx::ir::llvm
