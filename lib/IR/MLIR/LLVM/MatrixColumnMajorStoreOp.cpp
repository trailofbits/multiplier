// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/MatrixColumnMajorStoreOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<MatrixColumnMajorStoreOp> MatrixColumnMajorStoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE) {
    return reinterpret_cast<const MatrixColumnMajorStoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<MatrixColumnMajorStoreOp> MatrixColumnMajorStoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MatrixColumnMajorStoreOp MatrixColumnMajorStoreOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::MatrixColumnMajorStoreOp(this->Operation::op_);
}

::mx::ir::Value MatrixColumnMajorStoreOp::matrix(void) const {
  auto val = underlying_op().getMatrix();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool MatrixColumnMajorStoreOp::is_volatile(void) const {
  auto val = underlying_op().getIsVolatile();
  return val;
}

uint32_t MatrixColumnMajorStoreOp::rows(void) const {
  auto val = underlying_op().getRows();
  return val;
}

uint32_t MatrixColumnMajorStoreOp::columns(void) const {
  auto val = underlying_op().getColumns();
  return val;
}

}  // namespace mx::ir::llvm
