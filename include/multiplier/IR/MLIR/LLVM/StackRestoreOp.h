// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class StackRestoreOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class StackRestoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_STACKRESTORE;
  }

  static std::optional<StackRestoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<StackRestoreOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::StackRestoreOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value ptr(void) const;
};
static_assert(sizeof(StackRestoreOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
