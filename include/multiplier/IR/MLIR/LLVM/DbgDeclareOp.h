// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class DbgDeclareOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class DbgDeclareOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DBG_DECLARE;
  }

  static std::optional<DbgDeclareOp> from(const ::mx::ir::Operation &that);
  static std::optional<DbgDeclareOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::DbgDeclareOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> addr(void) const;
  //::mlir::LLVM::DILocalVariableAttr var_info(void) const;
};
static_assert(sizeof(DbgDeclareOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
