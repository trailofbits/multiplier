// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class CoroSuspendOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class CoroSuspendOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_SUSPEND;
  }

  static std::optional<CoroSuspendOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroSuspendOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::CoroSuspendOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value save(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> final(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroSuspendOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
