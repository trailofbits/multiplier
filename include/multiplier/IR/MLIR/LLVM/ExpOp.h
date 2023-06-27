// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class ExpOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class ExpOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXP;
  }

  static std::optional<ExpOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExpOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::ExpOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(ExpOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
