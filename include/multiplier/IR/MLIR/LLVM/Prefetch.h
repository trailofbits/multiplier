// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class Prefetch;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class Prefetch final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_PREFETCH;
  }

  static std::optional<Prefetch> from(const ::mx::ir::Operation &that);
  static std::optional<Prefetch> producing(const ::mx::ir::Value &val);

  mlir::LLVM::Prefetch underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> addr(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> rw(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> hint(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> cache(void) const;
};
static_assert(sizeof(Prefetch) == sizeof(Operation));

}  // namespace mx::ir::llvm
