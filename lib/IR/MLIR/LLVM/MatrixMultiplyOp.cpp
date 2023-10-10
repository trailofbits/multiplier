// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/MatrixMultiplyOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<MatrixMultiplyOp> MatrixMultiplyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MATRIX_MULTIPLY) {
    return reinterpret_cast<const MatrixMultiplyOp &>(that);
  }
  return std::nullopt;
}

std::optional<MatrixMultiplyOp> MatrixMultiplyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MatrixMultiplyOp MatrixMultiplyOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::MatrixMultiplyOp(this->Operation::op_);
}

::mx::ir::Value MatrixMultiplyOp::lhs(void) const {
  auto val = underlying_op().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MatrixMultiplyOp::rhs(void) const {
  auto val = underlying_op().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MatrixMultiplyOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t MatrixMultiplyOp::lhs_rows(void) const {
  auto val = underlying_op().getLhsRows();
  return val;
}

uint32_t MatrixMultiplyOp::lhs_columns(void) const {
  auto val = underlying_op().getLhsColumns();
  return val;
}

uint32_t MatrixMultiplyOp::rhs_columns(void) const {
  auto val = underlying_op().getRhsColumns();
  return val;
}

}  // namespace mx::ir::llvm
