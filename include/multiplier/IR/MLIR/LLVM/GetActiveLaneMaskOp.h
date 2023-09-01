// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class GetActiveLaneMaskOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class GetActiveLaneMaskOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_GET_ACTIVE_LANE_MASK;
  }

  static std::optional<GetActiveLaneMaskOp> from(const ::mx::ir::Operation &that);
  static std::optional<GetActiveLaneMaskOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GetActiveLaneMaskOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> base(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> n(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(GetActiveLaneMaskOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
