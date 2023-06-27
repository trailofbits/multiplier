// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class VPStridedStoreOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class VPStridedStoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_STORE;
  }

  static std::optional<VPStridedStoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPStridedStoreOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::VPStridedStoreOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> stride(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
};
static_assert(sizeof(VPStridedStoreOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
