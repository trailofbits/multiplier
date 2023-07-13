// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class MaskedLoadOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class MaskedLoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_LOAD;
  }

  static std::optional<MaskedLoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaskedLoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MaskedLoadOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> data(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::mlir::Operation::operand_range pass_thru(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(MaskedLoadOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
