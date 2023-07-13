// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class LifetimeStartOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class LifetimeStartOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LIFETIME_START;
  }

  static std::optional<LifetimeStartOp> from(const ::mx::ir::Operation &that);
  static std::optional<LifetimeStartOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LifetimeStartOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  //uint64_t size(void) const;
};
static_assert(sizeof(LifetimeStartOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
