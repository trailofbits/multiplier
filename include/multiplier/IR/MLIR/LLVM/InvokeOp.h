// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class InvokeOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class InvokeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INVOKE;
  }

  static std::optional<InvokeOp> from(const ::mx::ir::Operation &that);
  static std::optional<InvokeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::InvokeOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> callee_operands(void) const;
  gap::generator<::mx::ir::Operand> normal_dest_operands(void) const;
  gap::generator<::mx::ir::Operand> unwind_dest_operands(void) const;
  //::mlir::Block* normal_dest(void) const;
  //::mlir::Block* unwind_dest(void) const;
  std::optional<std::string_view> callee(void) const;
  //::std::optional<::llvm::ArrayRef<int32_t>> branch_weights(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
};
static_assert(sizeof(InvokeOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
