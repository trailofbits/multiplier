// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class AbsOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class AbsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_ABS;
  }

  static std::optional<AbsOp> from(const ::mx::ir::Operation &that);
  static std::optional<AbsOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::AbsOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> is_int_min_poison(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(AbsOp) == sizeof(Operation));

}  // namespace mx::ir::llvm