// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class SwitchOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class SwitchOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SWITCH;
  }

  static std::optional<SwitchOp> from(const ::mx::ir::Operation &that);
  static std::optional<SwitchOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SwitchOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> value(void) const;
  gap::generator<::mx::ir::Operand> default_operands(void) const;
  //::mlir::OperandRangeRange case_operands(void) const;
  //::mlir::Block* default_destination(void) const;
  //::mlir::SuccessorRange case_destinations(void) const;
  //::std::optional<::mlir::DenseIntElementsAttr> case_values(void) const;
  //::llvm::ArrayRef<int32_t> case_operand_segments(void) const;
  //::std::optional<::llvm::ArrayRef<int32_t>> branch_weights(void) const;
};
static_assert(sizeof(SwitchOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
