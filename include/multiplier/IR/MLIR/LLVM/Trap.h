// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class Trap;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class Trap final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_TRAP;
  }

  static std::optional<Trap> from(const ::mx::ir::Operation &that);
  static std::optional<Trap> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::Trap underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Trap) == sizeof(Operation));

}  // namespace mx::ir::llvm
