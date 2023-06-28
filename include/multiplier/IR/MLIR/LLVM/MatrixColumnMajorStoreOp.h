// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class MatrixColumnMajorStoreOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class MatrixColumnMajorStoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE;
  }

  static std::optional<MatrixColumnMajorStoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<MatrixColumnMajorStoreOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::MatrixColumnMajorStoreOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value matrix(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> data(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> stride(void) const;
  bool is_volatile(void) const;
  uint32_t rows(void) const;
  uint32_t columns(void) const;
};
static_assert(sizeof(MatrixColumnMajorStoreOp) == sizeof(Operation));

}  // namespace mx::ir::llvm