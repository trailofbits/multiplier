// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class VPFRemOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class VPFRemOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FREM;
  }

  static std::optional<VPFRemOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFRemOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFRemOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFRemOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
