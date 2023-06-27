// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class StepVectorOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class StepVectorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPERIMENTAL_STEPVECTOR;
  }

  static std::optional<StepVectorOp> from(const ::mx::ir::Operation &that);
  static std::optional<StepVectorOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::StepVectorOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(StepVectorOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
