// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class AShrOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class AShrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ASHR;
  }

  static std::optional<AShrOp> from(const ::mx::ir::Operation &that);
  static std::optional<AShrOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::AShrOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(AShrOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
