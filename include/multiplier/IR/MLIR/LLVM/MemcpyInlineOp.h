// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class MemcpyInlineOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class MemcpyInlineOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MEMCPY_INLINE;
  }

  static std::optional<MemcpyInlineOp> from(const ::mx::ir::Operation &that);
  static std::optional<MemcpyInlineOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MemcpyInlineOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> dst(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> src(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> len(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> is_volatile(void) const;
};
static_assert(sizeof(MemcpyInlineOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
