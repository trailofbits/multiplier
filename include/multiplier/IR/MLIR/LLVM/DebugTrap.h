// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class DebugTrap;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class DebugTrap final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DEBUGTRAP;
  }

  static std::optional<DebugTrap> from(const ::mx::ir::Operation &that);
  static std::optional<DebugTrap> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::DebugTrap underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(DebugTrap) == sizeof(Operation));

}  // namespace mx::ir::llvm
