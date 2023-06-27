// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class SDivOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class SDivOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SDIV;
  }

  static std::optional<SDivOp> from(const ::mx::ir::Operation &that);
  static std::optional<SDivOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::SDivOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SDivOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
