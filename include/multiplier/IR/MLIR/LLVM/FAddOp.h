// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class FAddOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class FAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FADD;
  }

  static std::optional<FAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<FAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FAddOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FAddOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
