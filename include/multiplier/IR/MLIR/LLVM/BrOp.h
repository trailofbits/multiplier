// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class BrOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class BrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_BR;
  }

  static std::optional<BrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::BrOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> dest_operands(void) const;
  //::mlir::Block* dest(void) const;
  //::std::optional<::mlir::LLVM::LoopAnnotationAttr> loop_annotation(void) const;
};
static_assert(sizeof(BrOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
