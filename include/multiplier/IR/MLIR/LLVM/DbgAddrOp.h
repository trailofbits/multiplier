// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class DbgAddrOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class DbgAddrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DBG_ADDR;
  }

  static std::optional<DbgAddrOp> from(const ::mx::ir::Operation &that);
  static std::optional<DbgAddrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::DbgAddrOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> addr(void) const;
  //::mlir::LLVM::DILocalVariableAttr var_info(void) const;
};
static_assert(sizeof(DbgAddrOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
