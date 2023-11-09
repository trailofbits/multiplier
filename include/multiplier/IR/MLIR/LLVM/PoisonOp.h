// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class PoisonOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class PoisonOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_POISON;
  }

  static std::optional<PoisonOp> from(const ::mx::ir::Operation &that);
  static std::optional<PoisonOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::PoisonOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(PoisonOp) == sizeof(Operation));

}  // namespace mx::ir::llvm