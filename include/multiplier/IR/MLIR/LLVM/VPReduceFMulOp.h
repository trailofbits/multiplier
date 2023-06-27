// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class VPReduceFMulOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class VPReduceFMulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_FMUL;
  }

  static std::optional<VPReduceFMulOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceFMulOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::VPReduceFMulOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::FloatType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceFMulOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
