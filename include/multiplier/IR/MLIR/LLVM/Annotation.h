// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class Annotation;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class Annotation final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_ANNOTATION;
  }

  static std::optional<Annotation> from(const ::mx::ir::Operation &that);
  static std::optional<Annotation> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::Annotation underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> integer(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> annotation(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> file_name(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> line(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> res(void) const;
};
static_assert(sizeof(Annotation) == sizeof(Operation));

}  // namespace mx::ir::llvm
