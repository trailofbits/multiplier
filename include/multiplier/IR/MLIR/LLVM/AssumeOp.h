// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class AssumeOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class AssumeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_ASSUME;
  }

  static std::optional<AssumeOp> from(const ::mx::ir::Operation &that);
  static std::optional<AssumeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AssumeOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> cond(void) const;
};
static_assert(sizeof(AssumeOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
