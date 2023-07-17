// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class VPSelectMinOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class VPSelectMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_SELECT;
  }

  static std::optional<VPSelectMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPSelectMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPSelectMinOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  ::mx::ir::Value true_val(void) const;
  ::mx::ir::Value false_val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPSelectMinOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
