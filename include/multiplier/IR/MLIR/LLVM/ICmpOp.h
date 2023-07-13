// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class ICmpOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class ICmpOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ICMP;
  }

  static std::optional<ICmpOp> from(const ::mx::ir::Operation &that);
  static std::optional<ICmpOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ICmpOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::ICmpPredicate predicate(void) const;
};
static_assert(sizeof(ICmpOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
