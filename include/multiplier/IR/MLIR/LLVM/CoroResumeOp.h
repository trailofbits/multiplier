// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class CoroResumeOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class CoroResumeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_RESUME;
  }

  static std::optional<CoroResumeOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroResumeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroResumeOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value handle(void) const;
};
static_assert(sizeof(CoroResumeOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
