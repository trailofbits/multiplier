// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class VPFMulAddOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class VPFMulAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FMULADD;
  }

  static std::optional<VPFMulAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFMulAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFMulAddOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value op1(void) const;
  ::mx::ir::Value op2(void) const;
  ::mx::ir::Value op3(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFMulAddOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
