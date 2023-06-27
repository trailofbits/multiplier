// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class CoroFreeOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class CoroFreeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_FREE;
  }

  static std::optional<CoroFreeOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroFreeOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::CoroFreeOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value id(void) const;
  ::mx::ir::Value handle(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroFreeOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
