// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class UBSanTrap;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class UBSanTrap final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_UBSANTRAP;
  }

  static std::optional<UBSanTrap> from(const ::mx::ir::Operation &that);
  static std::optional<UBSanTrap> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UBSanTrap underlying_op(void) const noexcept;

  // Imported methods:
  uint8_t failure_kind(void) const;
};
static_assert(sizeof(UBSanTrap) == sizeof(Operation));

}  // namespace mx::ir::llvm
