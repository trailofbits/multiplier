// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class FNegOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class FNegOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FNEG;
  }

  static std::optional<FNegOp> from(const ::mx::ir::Operation &that);
  static std::optional<FNegOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::FNegOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value operand(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FNegOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
