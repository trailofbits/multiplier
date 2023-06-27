// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class UMaxOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class UMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_UMAX;
  }

  static std::optional<UMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<UMaxOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::UMaxOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UMaxOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
