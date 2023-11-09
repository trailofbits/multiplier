// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class AllocaOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class AllocaOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ALLOCA;
  }

  static std::optional<AllocaOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AllocaOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> array_size(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> res(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  //::std::optional<::mlir::Type> elem_type(void) const;
  bool inalloca(void) const;
  //::llvm::SmallVector<::mlir::MemorySlot> promotable_slots(void) const;
  //::llvm::SmallVector<::mlir::DestructurableMemorySlot> destructurable_slots(void) const;
  //Type result_ptr_element_type(void) const;
};
static_assert(sizeof(AllocaOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
