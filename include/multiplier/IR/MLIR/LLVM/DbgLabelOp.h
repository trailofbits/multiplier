// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class DbgLabelOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class DbgLabelOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DBG_LABEL;
  }

  static std::optional<DbgLabelOp> from(const ::mx::ir::Operation &that);
  static std::optional<DbgLabelOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::DbgLabelOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::DILabelAttr label(void) const;
};
static_assert(sizeof(DbgLabelOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
