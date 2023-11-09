// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class PtrAnnotation;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class PtrAnnotation final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_PTR_ANNOTATION;
  }

  static std::optional<PtrAnnotation> from(const ::mx::ir::Operation &that);
  static std::optional<PtrAnnotation> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::PtrAnnotation underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> annotation(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> file_name(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> line(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> attr(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> res(void) const;
};
static_assert(sizeof(PtrAnnotation) == sizeof(Operation));

}  // namespace mx::ir::llvm
