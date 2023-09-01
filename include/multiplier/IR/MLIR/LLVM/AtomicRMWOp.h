// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class AtomicRMWOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class AtomicRMWOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ATOMICRMW;
  }

  static std::optional<AtomicRMWOp> from(const ::mx::ir::Operation &that);
  static std::optional<AtomicRMWOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AtomicRMWOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::AtomicBinOp bin_op(void) const;
  //::mlir::LLVM::AtomicOrdering ordering(void) const;
};
static_assert(sizeof(AtomicRMWOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
