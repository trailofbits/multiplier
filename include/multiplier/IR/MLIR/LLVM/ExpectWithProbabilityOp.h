// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class ExpectWithProbabilityOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class ExpectWithProbabilityOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPECT_WITH_PROBABILITY;
  }

  static std::optional<ExpectWithProbabilityOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExpectWithProbabilityOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ExpectWithProbabilityOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> expected(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::APFloat prob(void) const;
};
static_assert(sizeof(ExpectWithProbabilityOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
