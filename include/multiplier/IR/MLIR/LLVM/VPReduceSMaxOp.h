// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class VPReduceSMaxOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class VPReduceSMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_SMAX;
  }

  static std::optional<VPReduceSMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceSMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceSMaxOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceSMaxOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
