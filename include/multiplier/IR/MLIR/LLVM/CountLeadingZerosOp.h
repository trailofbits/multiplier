// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class CountLeadingZerosOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class CountLeadingZerosOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CTLZ;
  }

  static std::optional<CountLeadingZerosOp> from(const ::mx::ir::Operation &that);
  static std::optional<CountLeadingZerosOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CountLeadingZerosOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> zero_undefined(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CountLeadingZerosOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
