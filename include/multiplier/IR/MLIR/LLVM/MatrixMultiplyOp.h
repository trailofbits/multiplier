// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class MatrixMultiplyOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class MatrixMultiplyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MATRIX_MULTIPLY;
  }

  static std::optional<MatrixMultiplyOp> from(const ::mx::ir::Operation &that);
  static std::optional<MatrixMultiplyOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::MatrixMultiplyOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t lhs_rows(void) const;
  uint32_t lhs_columns(void) const;
  uint32_t rhs_columns(void) const;
};
static_assert(sizeof(MatrixMultiplyOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
