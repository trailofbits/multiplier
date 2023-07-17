// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/MatrixColumnMajorLoadOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<MatrixColumnMajorLoadOp> MatrixColumnMajorLoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_LOAD) {
    return reinterpret_cast<const MatrixColumnMajorLoadOp &>(that);
  }
  return std::nullopt;
}

std::optional<MatrixColumnMajorLoadOp> MatrixColumnMajorLoadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MatrixColumnMajorLoadOp MatrixColumnMajorLoadOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::MatrixColumnMajorLoadOp(this->Operation::op_);
}

::mx::ir::Value MatrixColumnMajorLoadOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool MatrixColumnMajorLoadOp::is_volatile(void) const {
  auto val = underlying_op().getIsVolatile();
  return val;
}

uint32_t MatrixColumnMajorLoadOp::rows(void) const {
  auto val = underlying_op().getRows();
  return val;
}

uint32_t MatrixColumnMajorLoadOp::columns(void) const {
  auto val = underlying_op().getColumns();
  return val;
}

}  // namespace mx::ir::llvm
