// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class FenceOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class FenceOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FENCE;
  }

  static std::optional<FenceOp> from(const ::mx::ir::Operation &that);
  static std::optional<FenceOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FenceOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::AtomicOrdering ordering(void) const;
  std::string_view syncscope(void) const;
};
static_assert(sizeof(FenceOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
