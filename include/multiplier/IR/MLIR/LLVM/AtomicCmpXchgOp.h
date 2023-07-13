// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class AtomicCmpXchgOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class AtomicCmpXchgOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_CMPXCHG;
  }

  static std::optional<AtomicCmpXchgOp> from(const ::mx::ir::Operation &that);
  static std::optional<AtomicCmpXchgOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AtomicCmpXchgOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  ::mx::ir::Value cmp(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::AtomicOrdering success_ordering(void) const;
  //::mlir::LLVM::AtomicOrdering failure_ordering(void) const;
};
static_assert(sizeof(AtomicCmpXchgOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
