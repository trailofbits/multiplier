// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/LrintOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<LrintOp> LrintOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LRINT) {
    return reinterpret_cast<const LrintOp &>(that);
  }
  return std::nullopt;
}

std::optional<LrintOp> LrintOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LrintOp LrintOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::LrintOp(this->Operation::op_);
}

::mx::ir::Value LrintOp::val(void) const {
  auto val = underlying_op().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value LrintOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
