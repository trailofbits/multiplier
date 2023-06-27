// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class InsertValueOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class InsertValueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INSERTVALUE;
  }

  static std::optional<InsertValueOp> from(const ::mx::ir::Operation &that);
  static std::optional<InsertValueOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::InsertValueOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value container(void) const;
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::ArrayRef<int64_t> position(void) const;
};
static_assert(sizeof(InsertValueOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
