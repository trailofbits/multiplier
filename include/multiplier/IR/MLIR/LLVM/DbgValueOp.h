// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class DbgValueOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class DbgValueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DBG_VALUE;
  }

  static std::optional<DbgValueOp> from(const ::mx::ir::Operation &that);
  static std::optional<DbgValueOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::DbgValueOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  //::mlir::LLVM::DILocalVariableAttr var_info(void) const;
};
static_assert(sizeof(DbgValueOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
