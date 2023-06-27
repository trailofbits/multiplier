// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class FreezeOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class FreezeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FREEZE;
  }

  static std::optional<FreezeOp> from(const ::mx::ir::Operation &that);
  static std::optional<FreezeOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::FreezeOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(FreezeOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
