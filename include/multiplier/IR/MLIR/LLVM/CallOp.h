// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class CallOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class CallOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_CALL;
  }

  static std::optional<CallOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CallOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  std::optional<std::string_view> callee(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
  //::std::optional<::llvm::ArrayRef<int32_t>> branch_weights(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
};
static_assert(sizeof(CallOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
