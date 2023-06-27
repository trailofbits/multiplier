// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class MemsetOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class MemsetOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MEMSET;
  }

  static std::optional<MemsetOp> from(const ::mx::ir::Operation &that);
  static std::optional<MemsetOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::MemsetOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> dst(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> len(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> is_volatile(void) const;
};
static_assert(sizeof(MemsetOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
