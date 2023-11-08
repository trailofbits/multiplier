// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class MatrixTransposeOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class MatrixTransposeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MATRIX_TRANSPOSE;
  }

  static std::optional<MatrixTransposeOp> from(const ::mx::ir::Operation &that);
  static std::optional<MatrixTransposeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MatrixTransposeOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value matrix(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t rows(void) const;
  uint32_t columns(void) const;
};
static_assert(sizeof(MatrixTransposeOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
