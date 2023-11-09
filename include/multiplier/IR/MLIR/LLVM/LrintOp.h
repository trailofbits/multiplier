// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class LrintOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class LrintOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LRINT;
  }

  static std::optional<LrintOp> from(const ::mx::ir::Operation &that);
  static std::optional<LrintOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LrintOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(LrintOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
