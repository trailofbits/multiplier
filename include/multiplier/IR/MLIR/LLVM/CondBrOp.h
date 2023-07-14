// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class CondBrOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class CondBrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_COND_BR;
  }

  static std::optional<CondBrOp> from(const ::mx::ir::Operation &that);
  static std::optional<CondBrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CondBrOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> condition(void) const;
  gap::generator<::mx::ir::Operand> true_dest_operands(void) const;
  gap::generator<::mx::ir::Operand> false_dest_operands(void) const;
  //::mlir::Block* true_dest(void) const;
  //::mlir::Block* false_dest(void) const;
  //::std::optional<::mlir::ElementsAttr> branch_weights(void) const;
};
static_assert(sizeof(CondBrOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
