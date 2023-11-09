// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class CallIntrinsicOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class CallIntrinsicOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_CALL_INTRINSIC;
  }

  static std::optional<CallIntrinsicOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallIntrinsicOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CallIntrinsicOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> args(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  std::string_view intrin(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(CallIntrinsicOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
