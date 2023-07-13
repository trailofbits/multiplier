// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class StackSaveOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class StackSaveOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_STACKSAVE;
  }

  static std::optional<StackSaveOp> from(const ::mx::ir::Operation &that);
  static std::optional<StackSaveOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::StackSaveOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(StackSaveOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
