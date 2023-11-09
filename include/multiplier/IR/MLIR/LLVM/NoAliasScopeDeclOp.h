// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class NoAliasScopeDeclOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class NoAliasScopeDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPERIMENTAL_NOALIAS_SCOPE_DECL;
  }

  static std::optional<NoAliasScopeDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<NoAliasScopeDeclOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::NoAliasScopeDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::AliasScopeAttr scope(void) const;
};
static_assert(sizeof(NoAliasScopeDeclOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
